#include <thread>
#include <iostream>
#include <condition_variable>
#include <mutex>

using namespace std;

constexpr int LAST = 1000;

void work(int serial, int &value, condition_variable &c, mutex &m, int &turn)
{
    while (true) {
        {
            unique_lock w{m};
            c.wait(w, [&turn, &serial]() { return turn == serial; });
        }
        if (value >= LAST) {
            exit(1);
            break;
        }
        cout << serial << " " << value << endl;
        ++value;

        {
            unique_lock w{m};
            turn = 1 - turn;
            c.notify_all();
        }
    }
}

int main()
{
    int value = 0;
    condition_variable c;
    mutex m;
    int turn = 0;
    thread t1(work, 0, ref(value), ref(c), ref(m), ref(turn)); // NB! ref()
    thread t2(work, 0, ref(value), ref(c), ref(m), ref(turn));

    {
        std::unique_lock w{m};
        c.notify_all();
    }

    t1.join();
    t2.join();
}
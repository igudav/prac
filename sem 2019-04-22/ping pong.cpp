#include <thread>
#include <iostream>
#include <condition_variable>
#include <mutex>

using namespace std;

constexpr int LAST = 1000;

void work(int serial, int &value, condition_variable &self, condition_variable &other, mutex &m,
        bool &sf, bool &of)
{
    while (true) {
        {
            unique_lock w{m};
            while (!sf) { // NB! more safe than if
                self.wait(w);
            }
            sf = false;
        }
        if (value >= 1000) {
            unique_lock w{m};
            of = true;
            other.notify_one();
            break;
        }
        cout << serial << " " << value << endl;
        ++value;

        {
            unique_lock w{m};
            of = true;
            other.notify_one(); // lost if the other thread is not still in wait
        }
    }
}

int main()
{
    int value = 0;
    condition_variable c1;
    condition_variable c2;
    mutex m;
    bool f1{};
    bool f2{};
    thread t1(work, 0, ref(value), ref(c1), ref(c2), ref(m), ref(f1), ref(f2)); // NB! ref()
    thread t2(work, 1, ref(value), ref(c2), ref(c1), ref(m), ref(f2), ref(f1));

    {
        std::unique_lock w{m};
        f1 = true;
        c1.notify_one();
    }

    t1.join();
    t2.join();
}
#include <thread>
#include <vector>
#include <iostream>
#include <mutex>

constexpr int COUNT = 5;
constexpr int ITER = 1000000;

long long value1 = 0;
long long value2 = 0; // если есть mutex, то можно без volatile
std::mutex m;

class wrapper { // такой класс уже есть и называется std::unique_lock
    std::mutex &m;

public:
    wrapper(std::mutex &m) : m{m} { m.lock(); }
    ~wrapper() { m.unlock(); }
};

int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < COUNT; ++i) {
        threads.emplace_back([] (int diff) {
            for (int j = 0; j < ITER; ++j) {
                std::unique_lock w(m); // unlock m in destructor automatically in any case
//                m.lock();
                value1 += diff;
                value2 -= diff;
//                m.unlock();
            }
            }, (i + 1) * 100);
    }
    for (auto &t : threads) {
        t.join();
    }

    std::cout << value1 << std::endl << value2 << std::endl;
}
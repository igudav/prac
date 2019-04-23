#include <thread>
#include <vector>
#include <iostream>
#include <mutex>
#include <array>

constexpr int COUNT = 5;
constexpr int ITER = 10000;

std::array<long long, COUNT> values;
std::array<std::mutex, COUNT> mutexes;

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
        threads.emplace_back([] (int serial, int diff) {
                for (int j = 0; j < ITER; ++j) {
//                    int n1 = std::min(serial, (serial + 1) % COUNT);
//                    int n2 = std::max(serial, (serial + 1) % COUNT);
//                    std::unique_lock w1(mutexes[n1]);
//                    std::unique_lock w2(mutexes[n2]);

                    // orders mutexes automatically to prevent deadlocks
                    std::scoped_lock w(mutexes[serial], mutexes[(serial + 1) % COUNT]);
                    values[serial] += diff;
                    values[(serial + 1) % COUNT] -= diff;
                }
            }, i, (i + 1) * 100);
    }
    for (auto &t : threads) {
        t.join();
    }
    for (auto x : values) {
        std::cout << x << std::endl;
    }
}
#include <thread>
#include <iostream>
#include <array>
#include <mutex>
#include <iomanip>

constexpr int SZ = 3;
constexpr int TIMES = 1000000;

double arr[SZ];
std::mutex m;

void proc(int num)
{
    for (int i = 0; i < TIMES; ++i) {
        m.lock();
        arr[num] += (num + 1) * 100;
        arr[(num + 1) % SZ] -= ((num + 1) * 100 + 1);
        m.unlock();
    }
}

int main()
{
    std::array<std::thread, SZ> arrthr;
    for (int i = 0; i < SZ; ++i) {
        arrthr[i] = std::thread(proc, i);
    }

    for (int i = 0; i < SZ; ++i) {
        arrthr[i].join();
    }

    for (int i = 0; i < SZ; ++i) {
        std::cout << std::setprecision(10) << arr[i] << std::endl;
    }
}
#include <thread>
#include <iostream>
#include <future>
#include <vector>
#include <exception>

bool is_prime(uint64_t num)
{
    if (num < 2) {
        return false;
    }
    for (uint64_t n = 2; n * n <= num; ++n) {
        if (num % n == 0) {
            return false;
        }
    }
    return true;
}

void proc(uint64_t low, uint64_t high, uint32_t count, std::vector<std::promise<uint64_t>> &vprom)
{
    uint32_t n = 0;
    for (uint64_t i = low; i <= high; ++i) {
        if (is_prime(i)) {
            vprom[n++].set_value(i);
        }
        if (n == count) {
            return;
        }
    }
    try {
        if (n < count) {
            throw high;
        }
    } catch (const uint64_t &ex) {
        vprom[n].set_exception(std::make_exception_ptr(ex));
    }
}

int main()
{
    uint64_t low, high;
    uint32_t count;

    std::cin >> low >> high >> count;

    std::vector<std::promise<uint64_t>> vprom(count);
    std::vector<std::future<uint64_t>> vfut(count);

    for(uint32_t i = 0; i < count; ++i) {
        vfut[i] = vprom[i].get_future();
    }

    std::thread thr(proc, low, high, count, std::ref(vprom));

    try {
        for (auto &item : vfut) {
            std::cout << item.get() << std::endl;
        }
    } catch (const uint64_t &exp) {
        std::cout << exp << std::endl;
    }

    thr.join();

}
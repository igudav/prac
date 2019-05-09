#include <iostream>
#include <thread>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <future>
#include <string>
#include <iomanip>

std::pair<unsigned long long, unsigned long long> func(unsigned num, unsigned long long iters)
{
    unsigned long long inside = 0;
    for (unsigned long long i = 0; i < iters; ++i) {
        double x = (double) rand_r(&num) / RAND_MAX * 2.0 - 1;
        double y = (double) rand_r(&num) / RAND_MAX * 2.0 - 1;
        if (x * x + y * y < 1.0) {
            ++inside;
        }
    }
    return std::make_pair(inside, iters);
}

int main(int argc, char *argv[])
{
    std::stringstream iss(argv[1]);
    unsigned thr_cnt;
    unsigned long long iters;
    iss >> thr_cnt;
    iss = std::stringstream(argv[2]);
    iss >> iters;

    std::vector<std::future<std::pair<unsigned long long, unsigned long long>>> vfut;

    for (unsigned i = 0; i < thr_cnt; ++i) {
        vfut.push_back(std::async(std::launch::async, func, i, iters));
    }

    unsigned long long all = 0;
    unsigned long long inside = 0;

    for (auto &item : vfut) {
        auto [a, b] = item.get();
        inside += a;
        all += b;
    }

    std::cout << std::fixed << std::setprecision(5) << (double) inside / all * 4.0 << std::endl;
}
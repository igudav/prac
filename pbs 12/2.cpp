#include <thread>
#include <iostream>
#include <mutex>
#include <vector>
#include <iomanip>

void func(unsigned iters, unsigned acc1, double sum1, unsigned acc2, double sum2,
        std::vector<std::mutex> &vm, std::vector<double> &vacc)
{
    for (unsigned i = 0; i < iters; ++i) {
        vm[acc1 < acc2 ? acc1 : acc2].lock();
        vm[acc1 < acc2 ? acc2 : acc1].lock();
        vacc[acc1] += sum1;
        vacc[acc2] += sum2;
        vm[acc1 < acc2 ? acc2 : acc1].unlock();
        vm[acc1 < acc2 ? acc1 : acc2].unlock();
    }
}

int main()
{
    unsigned acc_count, thr_count;
    std::cin >> acc_count >> thr_count;

    std::vector<std::thread> vthr;
    std::vector<std::mutex> vm(acc_count);
    std::vector<double> vacc(acc_count, 0.0);

    for (unsigned i = 0; i < thr_count; ++i) {
        unsigned iters, acc1, acc2;
        double sum1, sum2;
        std::cin >> iters >> acc1 >> sum1 >> acc2 >> sum2;
        vthr.emplace_back(func, iters, acc1, sum1, acc2, sum2, std::ref(vm), std::ref(vacc));
    }

    for (auto &item : vthr) {
        item.join();
    }

    for (const auto &item : vacc) {
        std::cout << std::setprecision(10) << item << std::endl;
    }
}
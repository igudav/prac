#include <iostream>
#include <future>
#include <vector>
#include <queue>
#include <mutex>
#include <shared_mutex>
#include <fstream>

int main() {
    std::queue<std::packaged_task<int(int, int)>> queries;
    std::queue<std::future<int>> results;
    std::thread t1([&]() {
        std::ifstream in("ops.txt");
        char c;
        while (in >> c) {
            switch (c) {
                case '+':
                    queries.push(std::packaged_task<int(int, int)>([](int a, int b) -> int { return
                    a + b; }));
                    break;
                case '*':
                    queries.push(std::packaged_task<int(int, int)>([](int a, int b) -> int { return
                            a * b; }));
                    break;
                default:
                    break;
            }
        }
    });

    std::thread t2([&]() {
        int arg1, arg2;
        while (true) {
            std::cin >> arg1 >> arg2;
            if (!queries.empty()) {
                auto task = std::move(queries.front());
                queries.pop();
                task(arg1, arg2);
                results.push(task.get_future());
            }
        }
    });

    std::thread t3([&]() {
        if (!results.empty()) {
            auto task = std::move(queries.front());
            queries.pop();
            std::cout << task.get_future().get() << std::endl;
        }
    });

    t1.join();
    t2.join();
    t3.join();
}
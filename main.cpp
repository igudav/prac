#include <iostream>
#include <unordered_map>
#include <string>
#include "pbs 12/7.cpp"
#include <functional>
#include <fstream>

int incr(int a)
{
    return a + 1;
}

void print(const std::vector<int> &outs)
{
    for (auto v : outs) {
        std::cout << v << std::endl;
    }
}

int main()
{
    using namespace std::literals::chrono_literals;

    std::vector<int> ins{1, 2, 3, 4, 5};
    async_vector<int, int>(ins, std::function(incr), std::function(print));
    std::this_thread::sleep_for(500ms);
}
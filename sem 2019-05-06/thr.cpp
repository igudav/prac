#include <thread>
#include <iostream>

void func(int a, int b) {
    std::cout << a << ", " << b << std::endl;
}

int main() {
    std::thread r(func, 100, 200);
    r.join();
}
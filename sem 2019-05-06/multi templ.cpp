#include <iostream>
#include <string>

void g(int x, int &y, int &&z, int dummy, double d, const std::string &a) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<typename C1, typename ...C2>
void func(C1 x, C2 &&...args) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    g(x, std::forward<C2>(args)...);
}

int main() {
    int x;
    int &&y = std::move(0);
    func(0, x, std::move(y), 100, 200.0, std::string("zero"));
}
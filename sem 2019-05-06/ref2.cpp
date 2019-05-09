#include <iostream>

void g(int &r) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void g(int &&r) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void g(const int &r) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

// при принятии аргумента по && подставится тот тип, который нужен. Universal reference
template <typename C>
void func (C &&value) {
//    std::cout << __PRETTY_FUNCTION__ << std::endl;
//    g(value); // не робит. Теряеется rvalue
//    g(std::move(value)); // не робит. Теряется lvalue

    g(std::forward<C>(value)); // perfect forwarding
}

int main() {
    int a = 0;
    const int b = 0;
    int &c = a;
    const int &d = b;
    int e = 2;
    int &&f = std::move(e);

    func(a);
    func(b);
    func(c);
    func(d);
    func(std::move(e));
    func(std::move(f));
    func(300);
    func(0);
}
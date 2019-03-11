#include <iostream>

using namespace std;

auto f(int s)
{
    cout << s << endl;
    /*
     * так нельзя, потому что разные типы
     * if (labla) {
     *      return (int) 10;
     * }
     */
    return (double) s;
}

auto g(int s) -> double // удобно для lambda и шаблонов
{
    cout << s << endl;
    return s;
}

// тут осторожно
auto h(auto a, auto b)
{
    return a + b;
}

int main()
{
    auto x = 10;
    f(x); // auto = void
    cout << f(x) << endl;
    cout << h(1, 2) << endl;
}
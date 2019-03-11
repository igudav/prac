#include <iostream>
#include <vector>
#include <list>
#include <set>
#include<functional>

template <typename T>
auto sum(const T &v, typename T::value_type s = {})
{
    for (const auto &x : v) {
        s += x;
    }
    return s;
}

template <typename T, typename F>
auto accum(const T &v, F f, typename T::value_type s = {}) // f - любая вещь, к которой применима
// операция ()
{
    for (const auto &x : v) {
        f(s, x);
    }
    return s;
}

using namespace std;

void func(int &s, int x)
{
    s += x;
}

template <class T>
void func2(T &s, T x)
{
    s += x;
}

struct Z {
    void operator()(int &s, int x) const
    {
        s += x;
    }
};

template <typename T>
struct Y {
    void operator()(T &s, T x) const
    {
        s += x;
    }
};

int main()
{
    vector v1{1, 2, 3, 4};
    cout << sum(v1, 300) << endl;

    list v2{1.4, 3.4};
    cout << sum(v2) << endl;

    set v3{string("qwe"), string("rty")};
    cout << sum(v3) << endl;

    cout << accum(v1, func) << endl;
    cout << accum(v1, func2<int>) << endl;
    cout << accum(v1, Z{}) << endl; // просто Z нельзя, нужен объект
    cout << accum(v1, Y<int>{}) << endl;
    cout << accum(v1, [](int &s, int x) {s += x;}) << endl; // лямбды
    cout << accum(v1, [](auto &s, auto x) {s += x;}) << endl; // магия auto
    cout << accum(v1, std::function<void (int &s, int x)>(func)) << endl; // совсем жесть
    // класс std::function - обертка для всего, что можно вызывать
}
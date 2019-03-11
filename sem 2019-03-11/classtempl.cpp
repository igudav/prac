template <typename T>
struct is_int
{
    static constexpr auto value = false;
};

template <>
struct is_int<int>
{
    static constexpr auto value = true;
};

#include <iostream>

using namespace std;

int main()
{
    cout << is_int<double>::value << endl;
    cout << is_int<int>::value << endl; // is_int<int>::value - константное выражение времени
    // компиляции

    int x;
    static_assert(is_int<decltype(x)>::value); // не скомпилируется, если x не int

    if constexpr (is_int<decltype(x)>::value) {
        cout << x << endl;
    }
}
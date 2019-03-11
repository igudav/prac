#include <iostream>
#include <vector>
#include <list>
#include <set>
#include<functional>

template <typename T>
auto sum(T beg, T end, typename T::value_type s = {})
{
    for (; beg != end; ++beg) {
        s += *beg;
    }
    return s;
}

// специализируем под массивы
template <typename T>
auto sum(T *beg, T *end, T s = {})
{
    for (; beg != end; ++beg) {
        s += *beg;
    }
    return s;
}



using namespace std;

int main()
{
    vector v1{1, 2, 3, 4, 5, 6, 7};

    cout << sum(v1.begin(), v1.end(), 300) << endl;
    cout << sum(v1.begin() + 1, v1.end() - 1, 300) << endl;

    double v4[]{1, 2, 3, 4, 5, 6, 7};
     cout << sum(v4, v4 + 5) << endl; // вызовем специализированную функцию
}
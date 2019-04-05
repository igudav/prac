#include <iostream>

using namespace std;

/*
 * k == 0 - сумма
 * k == 1 - умножение
 * k == 2 - возведение в степень
 * дальше - производим предыдущую операцию над a b раз.
 * Типа обобщаем арифметические операции.
 */

struct Result {
    long long res{};
    Result(long long r) : res{r} {}
};

void func(long long a, long long b, unsigned k)
{
    if (k == 0) {
        throw Result(a + b);
    }
    if (b == 1) {
        throw Result(a);
    }
    try {
        func(a, b - 1, k);
    } catch (Result &r) {
        func(a, r.res, k - 1);
    }
}

int main()
{
    long long a, b;
    unsigned k;
    while (cin >> a) {
        cin >> b;
        cin >> k;
        try {
            func(a, b, k);
        } catch (Result &r) {
            cout << r.res << endl;
        }
    }
}
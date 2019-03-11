const int N = 10; // Переменная N размещается в read-only памяти. И константа периода компиляции
constexpr int M = 5; // Вот так правильно писать константы времени компиляции
int arr[N];

/*
 * const - оюъект нельзя модифицировать
 * constexpr - во время компиляции
 */

constexpr int f(int a)
{
    if (a <= 0) return 1;
    return a * f(a - 1);
}

char c [f(N)]; // f считается во время компиляции

#include <iostream>

using namespace std;

int main()
{
    cout << sizeof(c) << endl;
}
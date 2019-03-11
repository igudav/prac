#include <iostream>

using namespace std;

struct Func
{
    int operator()(int a) const
    {
        return a + 1;
    }

    double operator()(int a, int b) const
    {
        return (a + b + 0.0) / 2;
    }
};

int main()
{
    Func f;

    cout << f(10) << endl << f(4, 5) << endl;
}
#include "pbs 4 2019-04-01/3.cpp"
#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Pos {
    bool operator()(int a)
    {
        return a > 0;
    }
};

struct Neg {
    int operator()(int a)
    {
        return -a;
    }
};

int main()
{
    list l = {-30, -20, 1, 2, 3, -10, 0};
    vector v = myfilter2(l.begin(), l.end(), Pos{});
    myapply(v.begin(), v.end(), Neg{});
    return 0;
}
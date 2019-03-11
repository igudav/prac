#include "pbs 2 2019-03-13/5.cpp"
#include <iostream>

using namespace std;

void func(S v)
{
    if (v) {
        func(move(v));
    }
}

int main()
{
    func(S());
}
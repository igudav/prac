#include "pbs 2 2019-03-13/2.cpp"
#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;
using namespace numbers;

int main()
{
    complex_stack cs{};
    complex_stack cs1 = cs << complex{1, 0};
    complex_stack cs2 = cs1 << complex{3, 2};
    complex_stack cs3 = ~cs2;
    cs2[1] = complex(0, 5);
    char buf[100];
    (+cs2).to_string(buf, sizeof(buf));
    cout << string(buf) << endl;
}
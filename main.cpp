#include "pbs 6/5.cpp"
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
    String a = "aaa";
    String b = a;
    a.~String();
    cout << string(b) << endl;
    return 0;
}
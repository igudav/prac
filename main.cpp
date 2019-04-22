#include "pbs 7/5.cpp"
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <complex>

using namespace std;

int main()
{

    cout << "100" << endl;
    cout << "1 26 1" << endl;
    for (int y = 2; y <= 25; ++y) {
        cout << "1 " << y << " 4" << endl;
    }
    for (int x = 1; x <= 25; ++x) {
        cout << x << " 1 2" << endl;
    }
    for (int y = 1; y <= 25; ++y) {
        cout << "26 " << y << " 3" << endl;
    }
    for (int x = 1; x <= 26; ++x) {
        cout << x << " 26 1" << endl;
    }

    return 0;
}
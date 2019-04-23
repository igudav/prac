#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool next(string &s) {

    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        if (*it == '1') {
            *it = '2';
            return true;
        }
        if (*it == '2') {
            if (it != s.rend() && (*(it + 1) == '3' || *(it + 1) == '4')) {
                *it = '3';
            } else if (it == s.rend() - 1) {
                *it = '3';
            } else {
                *it = '1';
                continue;
            }
            return true;
        }
        if (*it == '3') {
            *it = '4';
            return true;
        } else if (*it == '4') {
            *it = '1';
        }
    }
    return false;
}
int main() {
    unsigned len;
    cin >> len;

    string s(len, '1');
    cout << s << endl;
    while (next(s)) {
        cout << s << endl;
    }
}
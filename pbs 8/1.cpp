#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    while (cin >> s) {
        int index = 0;
        char c = s[0];
        bool flag = true;
        if (c == '3' || c == '4') {
            while (flag && (s[index] == '3' || s[index] == '4')) {
                if (index == (int) s.size() - 1) {
                    cout << 1 << endl;
                    flag = false;
                }
                ++index;
            }
        }
        c = s[index];
        if (flag && (c == '1' || c == '2')) {
            while (flag && (s[index] == '1' || s[index] == '2')) {
                if (index == (int) s.size() - 1) {
                    cout << 1 << endl;
                    flag = false;                }
                ++index;
            }
        }
        if (flag) {
            cout << 0 << endl;
        }
    }
}
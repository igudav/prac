#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int index = -1;
    int cnt = 0;
    for (int i = 0; i < (int) s.size(); ++i) {
        if (s[i] == '1') {
            if (index == -1) {
                index = i;
            }
            cnt = 1 - cnt;
        }
    }
    if (cnt == 1) {
        s[index] = '0';
    }
    cout << s;
}
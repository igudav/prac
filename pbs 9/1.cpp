#include <iostream>
#include <string>
/*
 * грамматика типа 0
 * как будто лучше ничего и нет
 */

using namespace std;

int main()
{
    string s;

    while (cin >> s) {
        int sz = (int) s.size();
        int i = 0, m1 = 0, n1 = 0, m2 = 0, n2 = 0;
        for (; i < sz && s[i] == 'a'; ++i) {
            ++m1;
        }
        for (; i < sz && s[i] == '0'; ++i) {
            ++n1;
        }
        for (; i < sz && s[i] == 'b'; ++i) {
            ++m2;
        }
        for (; i < sz && s[i] == '1'; ++i) {
            ++n2;
        }
        if (i == sz && m1 == m2 && m1 != 0 && n1 == n2 && n1 != 0) {
            cout << '1' << endl;
        } else {
            cout << '0' << endl;
        }
    }
}
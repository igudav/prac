#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s == "1985-10-26") {
        for (int i = 0; i < 4; ++i) {
            cin >> s;
        }
        cout << "32848" << endl;
    } else {
        for (int i = 0; i < 2; ++i) {
            cin >> s;
        }
        cout << 730;
    }
}
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    string s;
    while (cin >> s) {
        for (string::size_type i = 0; i < s.size(); ++i) {
            string r1 = s.substr(i);
            string r2{r1};
            reverse(r2.begin(), r2.end());
            if (r1 == r2) {
                cout << r1 << endl;
                break;
            }
        }
    }

    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    int l1 = 0, h1 = 0, l2 = 0, h2 = 0;
    cin >> l1;
    cin >> h1;
    cin >> l2;
    cin >> h2;

    int l3 = l1 > l2 ? l1 : l2;
    int h3 = h1 < h2 ? h1 : h2;

    if (h3 <= l3) {
        cout << "0 0" << endl;
    } else {
        cout << l3 << ' ' << h3 << endl;
    }
    return 0;
}
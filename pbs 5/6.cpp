#include <iostream>

using namespace std;

int main() {

    enum {
        LEFT = 1,
        RIGHT,
        UP,
        DOWN,
        HOLD,
        SZ = 8
    };

    int x, y;
    char mem[SZ];

    cin >> x >> y;

    for (auto &it : mem) {
        cin >> (int &) it;
    }

    if (x <= 0) {
        cout << LEFT << endl;
    } else if (y >= 2) {
        cout << DOWN << endl;
    } else if (y <= -2) {
        cout << UP << endl;
    }


    for (const auto &it : mem) {
        cout << it << " ";
    }
    cout << endl;

    return 0;

}
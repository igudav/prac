#include <iostream>
#include <cctype>

using namespace std;

void B(int len) {
    if (len == 1) {
        cout << 'b' << 'c';
    } else {
        cout << 'b';
        B(len - 1);
        cout << 'c';
    }
}

void A(int len, int step) {
    if (step == 0) {
        B(len);
    } else {
        cout << 'a';
        A(len - 1, step - 1);
        cout << 'd';
    }
}

void S(int len, int step) {
    if (step == 0) {
        return;
    }
    cout << 'a';
    A(len - 1, step - 1);
    cout << 'd' << endl;
    S(len, step - 1);
}

int main() {

    int k;
    cin >> k;
    if (k < 4 || k % 2 != 0) {
        return 0;
    }
    S(k / 2, k / 2 - 1);
}
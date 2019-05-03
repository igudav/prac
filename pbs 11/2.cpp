#include <iostream>
#include <cctype>

/*
 * S -> 1A0
 * A -> 1A0 | 0B1
 * B -> 0B1 | eps
 */

using namespace std;

int c;

void gc()
{
    c = getchar();
}

void B()
{
    if (c == '1') {
        return;
    }
    cout << '1';
    gc();
    B();
    gc();
    cout << '0';
}

void A()
{
    if (c == '0') {
        cout << '1';
        gc();
        B();
    } else if (c == '1') {
        gc();
        A();
    }
    gc();
    cout << '0';
}

void S()
{
    while (isspace(c)) {
        gc();
    }
    if (c == EOF) {
        exit(0);
    }
    gc();
    A();
}

int main()
{
    while (true) {
        gc();
        S();
        cout << '0' << endl;
    }
}
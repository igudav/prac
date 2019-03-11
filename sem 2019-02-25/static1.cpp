#include <iostream>
using namespace std;

struct X
{
    X() {cout << "X::X" << endl;}
    ~X() { cout << "~X" << endl; }
};

void foo()
{
    static struct X x; // Конструктор не вызывается вообще. Только при первом использовании.
    // Деструктор вызовется в сакмом конце, вместе с глобальными.
    struct X x5;
}

X x1; // Конструктор глоб объекта вызывается до main
static X x2;

int main()
{
    cout << "before foo" << endl;
    foo();
    cout << "after foo" << endl;
}
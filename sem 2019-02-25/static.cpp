#include <iostream>
 using namespace std;

struct X
{
    static int a; // Не видна в глобальной области видимости. Но живет без объекта
    // static int d = 4; - нельзя инициальизировать классе
    int b;

    static int foo()
    {
        // b++; - нельзя. Только к статическим
        a = 300;
        return 1;
    }
    int bar();
};

int X::a = 10;

int main()
{
    X::a = 5;

    X::foo();
    X x, *ps, &rx;
    x.foo();
    px->foo();
    rx.foo();
}
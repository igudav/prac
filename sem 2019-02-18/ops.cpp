#include <iostream>

using namespace std;

struct B
{
    int b;

    B(int b) : b(b) {}
};

struct A
{
private:
    int a;

public:
    A(int a) : a(a) {}

    A(const B &b) : a(10) {}

    // простые унарные операции + - ~ !
    int operator +() const // унарный плюс
    {
        cout << "A::operator +()" << endl;
        return a;
    }

    int operator -() const; // так разделяем декларацию и реализацию

    // простые бинарные + - = >=
    int operator +(const A &a) const
    {
        cout << "A::operator +(const A &a)" << endl;
        return 0;
    }
};

int A::operator-() const
{
    cout << "A::operator -()" << endl;
    return -a;
}

int A::operator -(const A &a, const B &b) const {}

// в чем разница? См ниже
int operator !(const A &a)
{
    cout << "A::operator !()" << endl;
    return 1;
}

int main()
{
    A a(1);
    +a;
    -a;
    !a;
    a + a;

    B b(2);
    !b; // сработает
    // +b; а это уже не сработает
}
#include "pbs 7/5.cpp"
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <complex>

using namespace std;

struct A {
    int a;
    A (int n) : a(n) {}
    virtual void f() { cout << "f()_A\n"; }
    virtual int g() = 0;
};

struct T {
    int a, b;
    T (int x = 0, int y = 0) {
        a = x;
        b = y;
    }
};

struct B : public A {
    B() : A(5) {}
    void f() { cout << "f()_B\n"; }
    int g() { return 0; }
};

struct P {
    T *ptr;
    bool flag = false;
    P(T *pt)
    {
        if (pt) {
            ptr = pt;
        } else {
            ptr = new T();
            flag = true;
        }
    }
    T *operator->()
    {
        return ptr;
    }
    ~P()
    {
        if (flag) {
            delete ptr;
        }
    }
};

int main()
{

    B b;
    A *pa = &b;
    pa->f();
    cout << pa->a << endl;
    T t;
    P p(&t);
    p->a = p->b = 3;
    cout << t.a << ' ' << t.b << endl;
    P p1(NULL);
    cout << p1->a << ' ' << p1->b << endl;
    return 0;
}
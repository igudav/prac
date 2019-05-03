#include <iostream>

using namespace std;

struct B {
    virtual int f() {
        cout << "f_from_B\n";
        return 0;
    }

    virtual void g() const {
        cout << "g_from_B\n";
    }
};

struct T : B {
    int f() {
        cout << "f_from_Т\n";
        return 0;
    }

    void g() const {
        cout << "g_from_Т\n ";
    }
};

int main() {
    int n;
    const T ct;
    T t;
    B *pb = &t;
    n = pb->f();
    pb->g();
    ct.g();
    return 0;
}
#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct A {
    A() = default;
    // конструкторы копирования и переноса по умолчанию
    // если явно написали хоть один из этих конструктоов, 2-й не генерируется автоматически
    A(const A &a) = default;
    A(A &&a) = default;

    void f() &
    {
        cout << "A::f &" << endl;
    }

    void f() const &
    {
        cout << "const A::f" << endl;
    }

    void f() &&
    {
        cout << "A::f &&" << endl;
    }
};

int main()
{
//    vector<string> vs;
//    string s;
//
//    while(cin >> s) {
//        // vs.push_back(s); юзаем копирование, а нафига?
//        vs.push_back(move(s));
//    }
//
//    for (const auto &z: vs) {
//        cout << z << endl;
//    }

    A a;
    A b(move(a));
    A c(a);

    a.f();
    const A &ra = a;
    ra.f();
    move(a).f();
}
#include <memory>
#include <iostream>
#include <vector>
#include <array>
#include <cstdio>

using namespace std;

struct A {
    int a{};
    ~A()
    {
        cout << "~A()" << endl;
    }
};

struct B : A{
    int b{};
    ~B()
    {
        cout << "~B()" << endl;
    }
};

int main()
{
//    shared_ptr<A> sha = make_shared<A>();
//    auto psha = sha;
//
//    char buf[10] = {};
//    A *pa5 = new (buf) A;

//    pa5->~A(); // delete нельзя, так как он вызывает free, а мы на стеке память выделили

    shared_ptr<A> pa3 = make_shared<B>();
    shared_ptr<B> p4 = static_pointer_cast<B>(pa3);

}
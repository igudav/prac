#include <memory>
#include <iostream>

using namespace std;

struct A {
    int a;
    ~A()
    {
        cout << "~A()" << endl;
    }
};

void f(A *pa)
{
    delete pa;
}

int main()
{
    unique_ptr<A> pa = unique_ptr<A>(new A{});
    f(pa.release()); // снова тупой указатель
}
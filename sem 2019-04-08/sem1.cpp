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
    // в хорошем с++ коде нет указателей
//    A *pa = new A();
//    f(pa);

    unique_ptr<A> pa = unique_ptr<A>(new A{});
    f(pa.get());
} // 2 раза вызывается деструктор, ub
struct A {
    void f(int);
};

struct B : A {
    void f(double)
};

int main()
{
    /*
     * ищем начиная с самой вложенной области видимости. Перегрузка решается на уровне одной
     * области видимости
     */
    A a;
    B b;
    a.f(1.5); // f(int)
    b.f(1); // f(double)
}
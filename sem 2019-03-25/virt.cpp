/*
 * у каждого указателя есть 2 типа: статический тип (тип, который видит компилястер при
 * компиляции) и динамический тип (тип объекта, но который указывает).
 */

struct A {
    void f(double) {}
    virtual void f(int x, int y = 0) {} // теперь она перестала быть виртуальной. Fragile base
    // class, чтобы такого не было, нужно писать override
    void g(int) {}
};

struct B : A {
    void f(int) {}
    void g(int) {}
};

int main()
{
    B *b = new B;
    A *a = new B;

    a->g(1);
    a->f(1);

}
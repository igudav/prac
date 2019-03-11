#include <iostream>

void f(int a, int b)
{
    std::cout << "f(int, int)" << std::endl; // \n + fflush()
}

void f(double a, double b)
{
    std::cout << "f(double, double)" << std::endl;
}

void f(const char *a, double b) // Просто целые числя не преобразуются в const, поэтому компилястер
// отбросит сразу. Но ноль неявно преобразуется в любой указатель, поэтому 0 прокатит
{
    std::cout << "f(const char *, double)" << std::endl;
}

struct A
{
    A(int z) // Конструктор преобразования типов
    {
        std::cout << "A::A(int)" << std::endl;
    }

    explicit A(double z) // explicit запрещает неявное преобразовние типов.
    {
        std::cout << "explicit" << std::endl;
    }

    // Мб любые типы
    operator const char *() const
    {
        std::cout << "исходящее преобразование" << std::endl;
        return "OK";
    }

    operator int() const
    {
        std::cout << "исходящее преобразование int" << std::endl;
        return 42;
    }
};

void f(const A &a) // неконстантная ссылка не сработает, а по значению можно
{
    std::cout << "f(const &a)" << std::endl;
}

void g(double z)
{
    std::cout << "g(double)" << std::endl;
}

int main()
{
    f(1, 2);
    f(1.3, 2.3);

    // f(1, 2.3) - не скомпилится

    short z = 4;
    f(z, 0);

    f(nullptr, 5.6);

    f(10); // Преобразовали int к A (создали временный объект), и передали в f
    f(z); // short -> int -> A
    f(1.4); // double -> int -> A, но если добавить конструктор для лонга, то уже не прокатит
    f(A(1.4)); // А так можно дернуть explicit конструктор

    std::cout << std::endl;

    A a{1.5};
    f(a, 9);
    g(a);


}
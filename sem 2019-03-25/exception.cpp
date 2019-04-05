#include <iostream>

/*
 * как передать и возвращаемое значение, и код об ошибке?
 */

[[nodiscard]] // нельзя игнорить возвращаемое значение
int func(int z)
{
    return -1;
}

[[nodiscard]]
int func2(int z, int &res)
{
}

[[nodiscard]]
std::pair<bool, int> func3(int x) {}

struct Except {
    int z[10000000];
};

int foo(int z)
{
    if (z > 0) {
        return foo(z - 1);
    }
    throw Except();
}

int funcfoo(int x) noexcept // для функций, которые ничего не выбрасывают
{
    return 1;
}

class A {
    char *a{};
    char *b{};
    size_t az{};
    size_t bz{};

public:
    // утечка памяти, если bad_alloc, а какая-то память уже выделена. Деструктор не сработает.
    A(char *a, size_t az, char *b, size_t bz) : a(new char[az]), az{az}, b(new char[bz])б bz(bz) {}
};

A &operator =(const A &q)
{
    // из-за исключения объект мб уже разрушен, но еще не создан.
    // правильно через swap
    if (&a == this)
        return *this;
    delete[] a;
    delete[] b;
    a = new char[]; // ...
    b = new char[]; // ...
}

A &operator =(A a)
{
    swap(a); // хорошо
}

int main()
{
    func(10);

    auto [res, val] = func3(10);

    try {
        foo(10);
    } catch (const Except &z) { // принимаем по константной ссылке, чтобы стек не закончился
        throw; // перевыбрасывает тупо текущее исключение
    }
}
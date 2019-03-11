#include <iostream>

struct A
{
    // Такая запись разрешает преобразование к вообще любому типу
    /*operator bool () const
    {
        std::cout << "operator bool" << std::endl;
        return true;
    }*/

    // какой-то кривой хак
    /*operator void *() const
    {
        std::cout << "operator void *" << std::endl;
    }*/

    // теперь надо так
    explicit operator bool () const
    {
        std::cout << "так надо" << std::endl;
    }

    // А вообще лучше писать методы для преобразования, а не переопределять операторы
};

int main()
{
    A a;

    while (a) {
        break;
    }
}
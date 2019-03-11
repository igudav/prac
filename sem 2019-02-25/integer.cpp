#include <cstdlib>

class Integer
{
    int value;

public:

    const Integer &operator ++() // Перегруз префиксного
    {
        if (/*__builtin_add_owerflow(&value, 1, &value)*/ false) {
            abort();
        }
        return *this;
    }

    // Тут плохо возвращать ссылку на локальную переменную. Локальные переменные долго не живут
    Integer operator ++(int dummy) // Перегруз постфиксного, в параметрах обяз ненужный инт
    {
        Integer tmp = *this;
        ++*this;
        return tmp;
    }
};

int main()
{
    Integer g;



    // ++++g; // так можно из-за того, что возвращаем ссылку? если константную, то уже так нельзя
}
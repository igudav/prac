#include <iostream>

class Proxy
{
    // Переопределенная -> должна свестись к обычной стреловки в смысле си
    struct Holder
    {
        int value = 4;
    };

    Holder *data{};
public:

    // делигируем доступ к value
    const Holder *operator -> () const
    {
        return data;
    }
};

int main()
{
    Proxy p{};

    std::cout << p->value << std::endl;
}
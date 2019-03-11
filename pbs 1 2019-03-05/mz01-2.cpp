#include <iostream>

class A
{
    int n;
    bool no_out = true;

public:
    A()
    {
        std::cin >> n;
    }

    A(const A &a) : no_out{false}
    {
        std::cin >> n;
        n += a.get();
    }

    int get() const
    {
        return n;
    }

    ~A()
    {
        if (!no_out) {
            std::cout << n << std::endl;
        }
    }
};

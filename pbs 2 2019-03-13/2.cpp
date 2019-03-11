#include "mz02-1.cpp"
#include <new>
#include <algorithm>

namespace numbers {

    class complex_stack {

        size_t sz;
        complex *stack;

    public:

        complex_stack()
        {
            sz = 0;
            stack = nullptr;
        }

        complex_stack(const complex_stack &other)
        {

        }

        size_t size() const
        {
            return sz;
        }

        complex operator [](size_t index) const
        {
            return stack[index];
        }

        complex &operator [](size_t index)
        {
            return stack[index];
        }

        friend complex_stack &operator <<(const complex_stack &cs, complex z);

        friend complex &operator +(complex_stack &cs);

        friend complex_stack &operator ~(complex_stack &cs);

        ~complex_stack()
        {
            delete[] stack;
        }
    };

    complex_stack &operator <<(const complex_stack &cs, complex z)
    {
        complex_stack *st = new complex_stack(cs);

        return *st;
    }

    complex &operator +(complex_stack &cs)
    {

    }

    complex_stack &operator ~(complex_stack &cs)
    {
        complex_stack *newcs = new complex_stack(cs);

        return *newcs;
    }
}
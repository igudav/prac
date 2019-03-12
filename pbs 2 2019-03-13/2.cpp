#include "mz02-1.cpp"
#include <cstdlib>
#include <new>

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

        complex_stack(const complex_stack &other, int ext = 0)
        {
            sz = other.sz + ext;
            stack = new complex[sz];
            for (size_t i = 0; i < sz; ++i) {
                stack[i] = i < other.sz ? other.stack[i] : complex();
            }
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

        friend complex operator +(const complex_stack &cs);

        friend complex_stack &operator ~(const complex_stack &cs);

        ~complex_stack()
        {
            delete[] stack;
        }
    };

    complex_stack &operator <<(const complex_stack &cs, complex z)
    {
        auto *st = new complex_stack(cs, 1);
        new (&st->stack[st->sz - 1]) complex(z);
        return *st;
    }

    complex &operator +(complex_stack &cs)
    {
        return cs.stack[cs.sz - 1];
    }

    complex operator +(const complex_stack &cs)
    {
        return cs.stack[cs.sz - 1];
    }

    complex_stack &operator ~(const complex_stack &cs)
    {
        auto *newcs = new complex_stack(cs, -1);

        return *newcs;
    }
}
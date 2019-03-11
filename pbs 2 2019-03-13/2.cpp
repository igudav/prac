#include "mz02-1.cpp"
#include <new>
#include <algorithm>

namespace numbers {

    constexpr size_t init_cap = 8;

    class complex_stack {

        size_t size;
        size_t capacity;
        complex *stack

    public:

        complex_stack(size_t capacity = init_cap) : capacity{capacity}
        {
            stack = new complex[capacity];
            size1 = 0;
        }

        complex_stack(const complex_stack &other)
        {
            capacity = other.capacity;
            stack = new complex[capacity];
            for (int i = 0; i < other.size1; ++i) {
                stack[i] = other.stack[i];
            }
            size1 = other.size1;
        }

        size_t size() const
        {
            return size1;
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
        st->push(std::move(z));

        return *st;
    }

    complex &operator +(complex_stack &cs)
    {
        return cs[cs.size1 - 1];
    }

    complex_stack &operator ~(complex_stack &cs)
    {
        complex_stack *newcs = new complex_stack(cs);

        return *newcs;
    }
}
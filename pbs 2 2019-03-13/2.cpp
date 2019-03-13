#include "mz02-1.cpp"
#include <cstdlib>

namespace numbers {
    class complex_stack {

        enum {
            INIT_CAP = 8,
            EXT = 2
        };

        size_t sz;
        size_t cap;
        complex *stack;

        void extend()
        {
            cap *= EXT;
            auto *newst = new complex[cap];
            for (size_t i = 0; i < sz; ++i) {
                newst[i] = stack[i];
            }
            delete[] stack;
            stack = newst;
        }

        void append(const complex &z)
        {
            if (sz >= cap) {
                extend();
            }
            stack[sz++] = z;
        }

    public:

        complex_stack() : sz{0}, cap{INIT_CAP}
        {
            stack = new complex[cap];
        }

        complex_stack(const complex_stack &other) : sz{other.sz}, cap{other.cap}
        {
            stack = new complex[cap];
            for (size_t i = 0; i < sz; ++i) {
                stack[i] = other.stack[i];
            }
        }

        complex_stack operator=(const complex_stack &other)
        {
            if (this != &other) {
                sz = other.sz;
                cap = other.cap;
                delete[] stack;
                stack = new complex[cap];
                for (size_t i = 0; i < sz; ++i) {
                    stack[i] = other.stack[i];
                }
            }
            return *this;
        }

        size_t size() const
        {
            return sz;
        }

        complex &operator[](size_t index) const
        {
            return stack[index];
        }

        complex_stack operator<<(const complex &z) const
        {
            auto newcs = complex_stack(*this);
            newcs.append(z);
            return newcs;
        }

        complex &operator+() const
        {
            return stack[sz - 1];
        }

        complex_stack operator~() const
        {
            auto newcs = complex_stack(*this);
            --newcs.sz;
            return newcs;
        }

        ~complex_stack()
        {
            delete[] stack;
        }
    };
}
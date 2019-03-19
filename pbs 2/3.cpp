#include <cstdlib>
#include <cstdio>
#include <math.h>

namespace numbers {

    class complex {
        double re, im;

    public:
        complex(double real = 0, double imaginary = 0) : re{real}, im{imaginary} {}

        explicit complex(const char *str) {
            str++;
            re = atof(str);
            while (*str != ',') {
                ++str;
            }
            ++str;
            im = atof(str);
        }

        double get_re() const {
            return re;
        }

        double get_im() const {
            return im;
        }

        double abs2() const {
            return re * re + im * im;
        }

        double abs() const {
            return sqrt(abs2());
        }
        void to_string(char *buf, size_t size) const {
            snprintf(buf, size, "(%.10g,%.10g)", re, im);
        }

        friend complex operator +(const complex &a, const complex &b);
        friend complex operator -(const complex &a, const complex &b);
        friend complex operator *(const complex &a, const complex &b);
        friend complex operator /(const complex &a, const complex &b);
        friend complex operator~(const complex &z);
        friend complex operator-(const complex &z);
    };

    complex operator -(const complex &z) {
        return complex{-z.re, -z.im};
    }

    complex operator ~(const complex &z) {
        return complex{z.re, -z.im};
    }

    complex operator +(const complex &a, const complex &b) {
        return complex{a.re + b.re, a.im + b.im};
    }

    complex operator -(const complex &a, const complex &b) {
        return complex{a.re - b.re, a.im - b.im};
    }

    complex operator *(const complex &a, const complex &b) {
        return complex{a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re};
    }

    complex operator /(const complex &a, const complex &b) {
        double q = b.re * b.re + b.im * b.im;
        return complex{(a.re * b.re + a.im * b.im) / q, (b.re * a.im - b.im * a.re) / q};
    }

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

    complex eval(char **args, const complex &z)
    {
        complex_stack cs;
        char *in;
        while ((in = *args++) != nullptr) {
            complex z1, z2;
            switch (*in) {
            case '(':
                cs = cs << complex(in);
                break;
            case 'z':
                cs = cs << z;
                break;
            case '+':
                z2 = +cs;
                cs = ~cs;
                z1 = +cs;
                cs = ~cs;
                cs = cs << z1 + z2;
                break;
            case '-':
                z2 = +cs;
                cs = ~cs;
                z1 = +cs;
                cs = ~cs;
                cs = cs << z1 - z2;
                break;
            case '*':
                z2 = +cs;
                cs = ~cs;
                z1 = +cs;
                cs = ~cs;
                cs = cs << z1 * z2;
                break;
            case '/':
                z2 = +cs;
                cs = ~cs;
                z1 = +cs;
                cs = ~cs;
                cs = cs << z1 / z2;
                break;
            case '!':
                cs = cs << +cs;
                break;
            case ';':
                cs = ~cs;
                break;
            case '~':
                z1 = +cs;
                cs = ~cs;
                cs = cs << ~z1;
                break;
            case '#':
                z1 = +cs;
                cs = ~cs;
                cs = cs << -z1;
                break;
            }
        }
        return +cs;
    }
}
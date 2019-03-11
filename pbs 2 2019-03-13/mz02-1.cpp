#include <cmath>
#include <cstdio>

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

        void *operator new[](size_t i) {
            return nullptr;
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
}


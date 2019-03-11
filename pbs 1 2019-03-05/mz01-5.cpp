#include <string>

class Rational
{
    int a, b;

    void normalize()
    {
        int sgn = 1;
        if (a == 0) {
            b = 1;
            return;
        }
        if (b < 0) {
            a = -a;
            b = -b;
        }
        if (a < 0) {
            sgn = -1;
            a = -a;
        }
        int m = a, n = b, r = 1;
        while (r > 0) {
            r = m % n;
            m = n;
            n = r;
        }
        a /= m;
        b /= m;
        a = sgn < 0 ? -a : a;
    }

public:

    Rational(int m = 0, int n = 1) : a{m}, b{n}
    {
        normalize();
    }

    Rational(const Rational &r) = default;

    Rational &Add(const Rational &r)
    {
        a = a * r.b + r.a * b;
        b = b * r.b;
        normalize();
        return *this;
    }

    Rational &Substract(const Rational &r)
    {

        a = a * r.b - r.a * b;
        b = b * r.b;
        normalize();
        return *this;
    }

    Rational &Multiply(const Rational &r)
    {
        a *= r.a;
        b *= r.b;
        normalize();
        return *this;
    }

    Rational &Divide(const Rational &r)
    {
        int rb = r.b, ra = r.a;
        a *= rb;
        b *= ra;
        normalize();
        return *this;
    }

    bool EqualTo(const Rational &r) const
    {
        return a == r.a && b == r.b;
    }

    int CompareTo(const Rational &r) const
    {
        Rational t{*this};
        t.Substract(r);
        return t.a;
    }

    bool IsInteger() const
    {
        return b == 1;
    }

    std::string ToString() const
    {
        return std::to_string(a) + ":" + std::to_string(b);
    }

};
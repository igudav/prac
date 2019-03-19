#include "3.cpp"
#include <string>
#include <cstdio>
#include <cmath>
#include <sstream>

class Rectangle : public Figure {
    double a, b;
public:
    static Rectangle *make(const std::string params)
    {
        auto *rect = new Rectangle();
        std::sscanf(params.c_str(), "%lf%lf", &rect->a, &rect->b);
        return rect;
    }

    double get_square() const
    {
        return a * b;
    }

    std::string to_string()
    {
        std::string s;
        std::ostringstream oss(s);
        oss << "R " << a << ' ' << b << std::endl;
        return oss.str();
    }
};

class Square : public Figure {
    double a;
public:
    static Square *make(const std::string params)
    {
        auto *sq = new Square();
        std::sscanf(params.c_str(), "%lf", &sq->a);
        return sq;
    }

    double get_square() const
    {
        return a * a;
    }

    std::string to_string()
    {
        std::string s;
        std::ostringstream oss(s);
        oss << "S " << a  << std::endl;
        return oss.str();
    }
};

class Circle : public Figure {
    double radius;
public:
    static Circle *make(const std::string params)
    {
        auto *c = new Circle();
        sscanf(params.c_str(), "%lf", &c->radius);
        return c;
    }

    double get_square() const
    {
        return M_PI * radius * radius;
    }

    std::string to_string()
    {
        std::string s;
        std::ostringstream oss(s);
        oss << "C " << radius << std::endl;
        return oss.str();
    }
};
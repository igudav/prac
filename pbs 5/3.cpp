#include <string>

class Figure {
public:
    virtual double get_square() const = 0;
    virtual ~Figure() {}
    virtual std::string to_string() = 0;
};
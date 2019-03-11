class Sum
{
    int a, b;

public:

    Sum(int a, int b) : a{a}, b{b} {}

    Sum(const Sum &other, int x) : a{other.get()}, b{x} {}

    int get() const
    {
        return a + b;
    }
};
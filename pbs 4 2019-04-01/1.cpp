template <class T>
auto process(const T &v)
{
    typename T::value_type s = {};
    auto it = v.rbegin();
    auto beg = v.rend();
    for (int i = 0; i < 5 && it != beg; ++it, ++i) {
        if (i % 2 == 0) {
            s += *it;
        }
    }
    return s;
}
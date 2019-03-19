template <class T>
auto process(const T &v)
{
    constexpr int LIM = 5;
    constexpr int STEP = 2;
    typename T::value_type s = {};
    auto it = v.rbegin();
    auto beg = v.rend();
    for (int i = 0; i < LIM && it != beg; ++it, ++i) {
        if (i % STEP == 0) {
            s += *it;
        }
    }
    return s;
}
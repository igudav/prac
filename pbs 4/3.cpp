#include <vector>
#include <functional>

template <class T, class F>
void myapply(T beg, T end, F f)
{
    for (; beg != end; ++beg) {
        f(*beg);
    }
}

template <class T, class F>
void myapply(T *beg, T *end, F f)
{
    for (; beg != end; ++beg) {
        f(*beg);
    }
}

template <class T, class F>
auto myfilter2(T beg, T end, F f)
{
    auto v = std::vector<std::reference_wrapper<typename T::value_type>>();
    for (; beg != end; ++beg) {
        if (f(*beg)) {
            v.insert(v.end(), std::reference_wrapper<typename T::value_type>(*beg));
        }
    }

    return v;
}

template <class T, class F>
auto myfilter2(T *beg, T *end, F f)
{
    auto v = std::vector<std::reference_wrapper<T>>();
    for (; beg != end; ++beg) {
        if (f(*beg)) {
            v.insert(v.end(), std::reference_wrapper<T>(*beg));
        }
    }

    return v;
}

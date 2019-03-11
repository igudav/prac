/*
#include <vector>

template <class T, class F>
void myapply(T beg, T end, F f)
{
    while (beg != end) {
        f(*beg);
        ++beg;
    }
}

template <class T, class F>
void myapply(T *beg, T *end, F f)
{
    while (beg != end) {
        f(beg);
        ++beg;
    }
}

template <class T, class F>
auto &myfilter2(T beg, T end, F f)
{
    auto *v = new std::vector<std::reference_wrapper<typename T::value_type>>();
    while (beg != end) {
        if (f(*beg)) {
            v->insert(v->end(), *beg);
        }
        ++beg;
    }

    return *v;
}

template <class T, class F>
auto &myfilter2(T *beg, T *end, F f)
{
    auto *v = new std::vector<std::reference_wrapper<T>>();
    while (beg != end) {
        if (f(beg)) {
            v->insert(v->end(), beg);
        }
    }

    return *v;
}*/

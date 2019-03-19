template <class T, class F>
T myfilter(const T &v, F f)
{
    T out;
    for (auto it_v : v) {
        if (f(it_v)) {
            out.insert(out.end(), it_v);
        }
    }
    return out;
}
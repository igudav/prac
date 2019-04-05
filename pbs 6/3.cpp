#include <vector>
#include <algorithm>

template<typename T>
struct Coord {

    typedef T value_type;
    T row, col;

    Coord() : row{T()}, col{T()} {}

    Coord(T sz) : row{sz}, col{sz} {}

    Coord(T r, T c) : row{r}, col{c} {}
};

template<typename T>
T max(T a, T b) {
    return a > b ? a : b;
}

template<typename T>
T min(T a, T b) {
    return a < b ? a : b;
}

template <typename T>
T abs(T a) {
    return a > 0 ? a : -a;
}

template<typename T>
T dist(Coord<T> sz, Coord<T> a, Coord<T> b) {

    T d_row = min(abs(a.row - b.row), sz.row - abs(a.row - b.row));
    T d_col = min(abs(a.col - b.col), sz.col - abs(a.col - b.col));

    return max(d_row, d_col);
}
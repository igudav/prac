namespace Game {

    template<typename T>
    struct Coord {

        typedef T value_type;
        T row, col;

        Coord() : row{T()}, col{T()} {}

        Coord(T sz) : row{sz}, col{sz} {}

        Coord(T r, T c) : row{r}, col{c} {}
    };

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

        T d_row = abs(a.row - b.row);
        T d_col = abs(a.col - b.col);
        T res = d_row + d_col;

        T corr;
        if ((a.col % 2 == 0 && b.row > a.row) || (a.col % 2 > 0 && b.row <= a.row)) {
            T absol = abs(a.col - b.col);
            T f = absol % 2 == 0 ? absol / 2 : absol / 2 + 1;
            corr = min(f, abs(a.row - b.row));
        } else {
            corr = min(abs(a.col - b.col) / 2, abs(a.row - b.row));
        }
        res -= corr;
        return res;
    }
}
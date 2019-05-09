#include <utility>


// шаблон инстанциируется рекурсивно
template <typename C0, typename ...C1>
struct MyTuple/* : MyTuple<C1...>*/ {
    C0 arg0;
    MyTuple<C1...> argz;

    MyTuple(C0 &&c0, C1 &&...c1) : arg0{c0}, argz{std::forward<C1...>(c1...)} {}
};

template <typename C>
struct MyTuple<C> {
    C arg0;

    MyTuple(C &&arg0) : arg0{arg0} {}
};

template <typename T>
T get(int index) {
    // как достать элемент
}

// развернуть Tuple в аргументы функции

int main() {
    MyTuple<double> a{1.0};
    MyTuple<double, int> b{1.0, 3};
}
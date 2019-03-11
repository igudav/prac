#include <iostream>

using namespace std;

/*
 * параметры шаблона бывают 3 типов:
 *      1. Типы typename C
 *      2. Обычные типы, кроме double и указателей
 *      3. ... (сложно, но можно)
 */
template <typename C>
void myswap(C &a, C &b)
{
    cout << "C&" << endl;
    auto tmp{move(a)};
    a = move(b);
    b = move(tmp);
}

/*
void myswap(int &a, int &b) // обычные ф-ции приоритетнее шаблонных, а мы хотим уточнить шаблон
{

}
*/

template <>
void myswap(int &a, int &b) // вот так уточняем
{

}

template <class C>
void myswap(C *a, C *b)
{
    auto tmp{*a};
    *a = *b;
    *b = tmp;
}

int main()
{
    int a = 10, b = 20;

    myswap<int>(a, b);

    cout << a << " " << b << endl;

    double p = 1.1, q = 4.5;
    myswap(p, q);

    cout << p << " " << q << endl;

    double *pp = &p, *pq = &q;
    cout << pp << " " << pq << endl;
    myswap(pp, pq);
    // myswap<double *>(pp, pq);
    cout << pp << " " << pq << endl;
}
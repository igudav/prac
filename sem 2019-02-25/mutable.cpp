#include <iostream>
using namespace std;
// mutable не нужен никогда. Костыль.

struct S
{
    mutable int x; // mutable-поля можно модифицировать в константном объекте
};

int main()
{
    const S z{10};

    ++z.x; // Опа
    cout << z.x << endl;

}
#include <iostream>
#include <string>

using namespace std;


int main()
{
    int a{};

    int &ra = a;
    const int &cra = a;
    // ++cra нельзя

    // int &rra = a; ошибка. нельзя присвоить lvalue к rvalue
    int &&rra = a + 1; // ссылка на временный объект, который можно изменять
    const int &cc = a + 1; // константная ссылка на временный объект
    ++rra;
    cout << rra << endl;

    int &&rra2 = move(a); // из lvalue магическим образом сделали rvalue, причем адрес не изменился
}
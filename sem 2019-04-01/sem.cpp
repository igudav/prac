#include <iostream>

using namespace std;

//void f(int a)
//{
//    cout << "f(int)" << endl;
//}

void f(int &&a)
{
    cout << "f(int &&)" << endl;
}

void f(int &a)
{
    cout << "f(int &)" << endl;
}

void f(const int &a)
{
    cout << "f(const int &)" << endl;
}

// получили 3 непересекающиеся категории параметров.

int main()
{
    int a = 0;
    const int b = 0;
    f(1);
    f(a);
    f(b);
}
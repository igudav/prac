#include <iostream>

using namespace std;

int main()
{
    int z;
    // Это переменная, кот является лямбда-функцией
    // [z] - замыкание
    // Смысл в том, что мы f можем вернуть и z будет… Короче
    /*
     * контекст - некоторые переменные
     * функция видит контекст, то есть все локальные переменные
     * после завершения функции контекст оохраняется
     * это и есть замыкание
     */
    // lambda-формы транслируются в структуры с перегруденным оператором ()
    cin >> z;
    auto f = [z](int a) { return z + a; };

    int x;
    cin >> x;
    cout << f(x) << endl;

    struct Lambda
    {
        int z_;

        Lambda(int z_) : z_(z_) {}
        int operator()(int a)
        {
            return z_ + a;
        }
    };

    Lambda ff(z);
    cout << ff(x) << endl;
}
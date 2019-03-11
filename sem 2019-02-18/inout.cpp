#include <iostream>
#include <iomanip>

// using namespace std; тянет за собой все. Такое "не приветствуется". Можно притащить много функций
// если задание написать класс, то юзинг вообще низзья писать

using std::cin;
using std::cout;
using std::endl;

int main()
{
    /*double z;
    int a, b;
    // (cin >> a) >> b; считали сразу 2 числа
    while (cin >> z) { // результат - объект потока. Неявно приводится к bool
        cout << "z: " << z << endl;
        // чтобы рулить выводом, нужны манипуляторы
        cout << setprecision(10) << setw(32) << setfill('0') << z << endl;
    }*/
    char c;
    int n = 4;
    char k = 4;
    cin >> std::noskipws; // теперь не съедаются
    while (cin >> c) {
        cout << c << endl; // пробельные символы съедаются
        cout << "(" << (n + '0') << ")" << endl; // n + '0' имеет тип int
        cout << "(" << (k + '0') << ")" << endl; // тоже не робит, потому что нет операции + для
        // char
        cout << "(" << char(n + '0') << ")" << endl;
        n = (n + 1) % 10;
    }
}
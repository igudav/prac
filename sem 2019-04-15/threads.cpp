#include <thread>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void func(int a, double b, const string &s)
{
    ostringstream oss;
//    cout << 1 << 2 << 3 <<endl;
    oss << a << b << s <<endl;
    cout << oss.str();
}

int main()
{
    std::thread thr;
    string s{"qwer"};
    // нить существует, пока сущность, к оторой применима () и которую передаем, выполняется
    cout << 4 << 5 << 6 <<endl; // комбинация из неск cout несинхронизирована
    thr = std::thread(func, 10, 13.5, s); // сложная передача параметров через ядро


    thr.join(); // только после этого безопасно вызывать деструктор.
    thr.detach(); // тоже можно. Переводит нить в фоновый режим. Нить живет сама по себе
}
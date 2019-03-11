#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyVector {

    // int buf[10];
    string *buf;
    int size;
    int capacity;

public:

    /*MyVector(std::initializer_list<int> val)
    {
        int i = 0;
        for (auto elem : val) {
            buf[i] = elem;
            ++i;
        }
        size = val.size();
    }*/

    MyVector()
    {
        size = 0;
    }

    void push_back(const string &s)
    {
        if (size >= capacity) {
            // Шестимиров сказал никогда так не делать. Оч криво
            capacity *= 2;
            ++capacity;
            string *tmp = malloc(sizeof(string) * capacity); // new плохо, так как конструкторы
            // вызывать не нежно
            for (int i = 0; i < size; ++i) {
                new(tmp + i) string(buf[i]); // конструктор вызывает здесь
            }
            for (int i = 0; i < size; ++i) {
                buf[i].~string();
            }
            free(buf);
            buf = tmp;
        }
        new (buf + size) string(s);
    }

    /*int *begin() {
        return buf;
    }

    int *end() {
        return buf + size;
    }*/
};

int main()
{

    // std::vector<int> v(4); 4 - число эл-тов
    std::vector<int> v{1, 4, 5};
    // std::vector v{1, 2, 3}; компилястер сам поймет тип

    for (auto elem : v) {
        std::cout << elem << endl;
    }

    v.push_back(5);

    for (auto elem : v) {
        std::cout << elem << endl;
    }
/*

    MyVector v1{3, 2, 1};
    for (auto elem : v1) { // для такого нужны методы begin и end
        cout << elem;
    }

    std::sort(v1.begin(), v1.end());

    for (auto elem : v1) {
        cout << elem;
    }
*/

    cout << endl << endl;

    sort(v.rbegin(), v.rend());

    for (auto elem : v) {
        cout << elem;
    }

    cout << endl << endl;

    // auto разворачивается в vector<int>::reverse_iterator
    for (auto it = v.rbegin(); it < v.rend(); it += 2) {
        cout << *it;
    }

    cout << endl << endl;

    auto it = v.begin();
    v.push_back(5);
    cout << *it; // вектор может переехать и итератор побьется

    cout << endl << endl;

    cout << v.size() << endl; // размер
    cout << v.capacity() << endl; // сколько памяти

    v.reserve(1000);
    cout << v.capacity() << endl; // сколько памяти
    v.resize(1); // изменил size а не capacity
    cout << v.capacity() << endl; // сколько памяти
    v.shrink_to_fit();
    cout << v.capacity() << endl;

    return 0;
}
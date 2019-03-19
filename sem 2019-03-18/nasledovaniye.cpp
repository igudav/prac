#include <iostream>
using namespace std;
class Base {
public:
    virtual ~Base()
    {
        cout << "B" << endl;
    }
};
class Der : public Base {
public:
    virtual  ~Der()
    {
        cout << "D" << endl;
    }
};

class Shape {
    virtual void draw() = 0; // Нельзя вызвать. Чисто абстрактный класс
};

int main()
{
    Base *p = new Der();
    delete p;
}
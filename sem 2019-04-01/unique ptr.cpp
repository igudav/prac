#include <memory>
#include <iostream>
#include <vector>

using namespace std;

struct A {
    int z{};
    A() : z{} {};
    A(int z) : z{z} {}
    A (const A &a) = delete;
    A (A &&a) = delete;
    auto getz() { return z; }
};

int main()
{
    unique_ptr<A> up1(new A(1)); // smart pointer, умный указатель
    if (up1) {
        cout << up1->getz() << endl;
    }
    auto up2 = move(up1); // move и только move
    if (up1) { // false
        cout << up1->getz() << endl;
    }
    if (up2) {
        cout << up2->getz() << endl;
    }

    vector<unique_ptr<A>> va;
    va.push_back(move(up2)); // снова move
    // как только указатель up2 перестанет на него указывать, память автоматически освободится

    unique_ptr<A[]> ma1(new A[3]{1, 2, 3});
    cout << ma1[1].getz() << endl;

    auto zz = make_unique<A>(100); // никакого new, тупо форвардим в конструктор A
    cout << zz->getz() << endl;
}
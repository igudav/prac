#include <memory>
#include <iostream>
#include <vector>
#include <array>
#include <cstdio>

using namespace std;

struct A {
    int a{};
    ~A()
    {
        cout << "~A()" << endl;
    }
};

void f(unique_ptr<A> pa)
{
    cout << pa->a << endl;
}

void g(unique_ptr<A> pa1, unique_ptr<A> pa2)
{
    cout << "Y" << endl;
}

struct Deleter {
    void operator()(FILE *f) {
        fclose(f);
        cout << "close" << endl;
    }
};

int main()
{
    unique_ptr<A> pa = unique_ptr<A>(new A{});
    f(move(pa)); // move важно

    vector<unique_ptr<A>> va;
    va.push_back(unique_ptr<A>(new A{}));

    g(unique_ptr<A>(new A{}), unique_ptr<A>(new A{})); // проблема. Сначала левый new, а во время
    // правого new - ошибка => утечка памяти вариант

   unique_ptr<A> pa1(new A{});
   unique_ptr<A> pa2(new A{});
   g(move(pa1), move(pa2)); // решили проблему

   // еще вариант, который тоже не допускает утечки памяти
   g(make_unique<A>(), make_unique<A>());

   // указатель на массив
   // unique_ptr<A> paa = unique_ptr<A>(new A[10]); // плохо так
   unique_ptr<A[]> paa = unique_ptr<A[]>(new A[10]);

   cout << "!!!!!!!!!!!!!!!!" << endl;

   // плохо так делать
   FILE *ff = fopen("sem1.cpp", "r");
   unique_ptr<FILE> pf (ff); // нелья просто так взять и делитнуть FILE *

   unique_ptr<FILE, Deleter> goodff(ff);
}
struct A {
    virtual bool equals(A *pa) = 0; // бинарная ф-ция от 2 объектов иерархии наследования
};

struct B : A {
    // void equals(B *pb); // так писать нельзя: это совершенно другая функция

    int value;
    bool equals(A *pa) override
    {
        if (!pa) {
            return false;
        } else if (B *pb = dynamic_cast<B*>(pa); pb) { // если по факту не B*, то pb будет nullptr
            return value == pb->value;
        } else {
            return false;
        }
    }
};

struct

struct S{};

int main()
{
    (T) v; // обычный сишный cast. Не очень.

    T(v) // если конструктор не explicit, то робит как каст

    for(ssize_t z = ssize_t(v.size()) - 1; z >= o; --z) {

    }

   // static cast
    static_cast<T>(v); // робит, когда c++ считает, что каст безопасный: int <-> float <-> bool и
    // базовый <-> производный

    const_cast<T>(v); // константный тип в неконстантный

    reinterpret_cast<T>(v) // int <-> pointer; преобразования указателей разных типов друг к другу

}
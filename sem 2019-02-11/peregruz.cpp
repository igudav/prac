#include <stdio.h>

void f()
{
    printf("f\n");
}

void f(int z)
{
    printf("int: %d\n", z);
}

void f(double z)
{
    printf("dbl: %f\n", z);
}

void f(unsigned char c) {
    printf("u char: %c\n");
}

void f(long &l)
{
    printf("long\n");
}

void f(const long &rl) // без const нельзя перегружать
{
    printf("ref long\n");
}

int main()
{
    f();

    int z = 4;
    double d = 5.5;

    char c = 'a'; // скомпилится как integer promotion. double promotion скомпилится
    f(c); // char приведется не к u char, а к int

    /*
     * А это не скомпилится, так как просто convertion
     * непонятно, к какому типу приводить: double или int
    long l;
    f(l);
    */

    long l = 5;
    long &rl = l;

    f('z'); // все еще int

    // преобразование const к не-const еще более приоритетно, чем int promotion

    // f(NULL); вызовется f(int) - Оба-на
    // f(nullptr); без warning вызовется f(const char *), везде суем nullptr ЖБ
    // f(nullptr): непонятно, к какому именно указателю приводить, если все перегружено.
}

/*
 * иерархия преобразований типов
 * одинаковый тип
 * +const, +volatile,…
 * promotion
 * convertion
 * user
 * ... ellipsis (переменное число аргументов)
 *
 *
 * шаблоны совсем магия
 */
int f(int x, int y = 1, int z = 2); // Аргументы по умолчанию только в конце

int f(double x);

int f(double x, double y);

int main()
{
    f(10); // Вызовется f(int) как точное совпадение
    f(10, 11);
    f(10, 11, 12);

    f(1.2, 4.4);
    /*
     * выбор перегруженной функции компилястер делает раньше, чем подстановку параметров по
     * умолчанию
     */


}
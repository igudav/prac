#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
    double a, sigma = 0, avg = 0;
    cin >> a;
    avg = a;
    sigma = a * a;
    int n = 1;
    while (cin >> a) {
        avg += a;
        sigma += a * a;
        n++;
    }
    avg /= n;
    sigma = sqrt(sigma / n - avg * avg);
    cout << setprecision(10) << avg << endl << sigma << endl;
}
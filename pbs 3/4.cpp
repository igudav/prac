#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct F
{
    double sum;

    F() : sum{0.0} {}

    void operator()(double a)
    {
        sum += a;
    }
};

int main()
{
    constexpr int norm = 10;
    vector<double> v;
    double a;

    while (cin >> a) {
        v.push_back(a);
    }

    size_t del = v.size() / norm;
    v.erase(v.begin(), v.begin() + del);
    v.erase(v.end() - del, v.end());

    sort(v.begin(), v.end());
    del = v.size() / norm;
    v.erase(v.begin(), v.begin() + del);
    v.erase(v.end() - del, v.end());

    F out = for_each(v.begin(), v.end(), F());
    cout << out.sum / v.size() << endl;
}
#include <iostream>
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::gregorian;

int main()
{
    string cur, prev;
    cin >> prev;
    date dp = from_string(prev);
    long long res = 0;
    while (cin >> cur) {
        date dc = from_string(cur);
        date_duration dd = dc - dp;
        res += abs(dd.days());
        prev = cur;
    }
    cout << res << endl;
}
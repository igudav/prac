#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::gregorian;

int main()
{
    int y, m, d;
    cin >> y >> m >> d;
    m = -m;
    d = -d;
    date dp = date(y, m, d);
    long long res = 0;
    while (cin >> y >> m >> d) {
        m = -m;
        d = -d;
        date dc = date(y, m, d);
        date_duration dd = dc - dp;
        res += abs(dd.days());
        dp = dc;
    }
    cout << res << endl;
}
#include <vector>
#include <iostream>

using std::vector, std::cout, std::endl;

void process(const vector<int> &src, vector<int> &dst, int step)
{
    auto it_src = src.begin();
    auto it_dst = dst.begin();

    int i = 0;
    while (it_src != src.end() && it_dst != dst.end()) {
        if (i++ % step == 0) {
            *it_dst++ = *it_src;
        }
        ++it_src;
    }

    for (auto it = dst.rbegin(); it < dst.rend(); ++it) {
        cout << *it << endl;
    }
}
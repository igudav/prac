#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>

using namespace std;

struct Cmp {
    string s;

    bool operator()(int a, int b) {
        return strcmp(s.c_str() + a, s.c_str() + b) < 0;
    }

};

int main()
{
    Cmp c;
    getline(cin, c.s);

    while (isspace(c.s[c.s.size() - 1])) {
        c.s.erase(c.s.size() - 1, 1);
    }

    vector<int> v;
    v.reserve(c.s.size());

    for (int i = 0; i < (int) c.s.size(); ++i) {
        v.push_back(i);
    }

    sort(v.begin(), v.end(), c);

    for (auto &it : v) {
        cout << it << endl;
    }

}
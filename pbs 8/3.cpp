#include <iostream>
#include <cctype>
#include <string>

using namespace std;

struct Res {
    int r;

    Res() : r{3} {}

    void lvl_down(int lvl)
    {
        if (r > lvl) {
            r = lvl;
        }
    }
};

int main()
{
    string sl, sr;
    Res res;

    if (!(cin >> sl)) {
        cout << -1 << endl;
        return 0;
    }

    cin >> sr;
    bool flag = false;
    bool check_eps_r = false;
    bool check_S_r = false;

    do {
        if (sl.size() != 1) {
            res.lvl_down(1);
        }

        if (sr == "_") {
            check_eps_r = true;
        }

        for (const auto &it : sr) {
            if (it == 'S') {
                check_S_r = true;
            }
        }

        bool no_gram = true;
        for (const auto &it : sl) {
            if (isupper(it)) {
                no_gram = false;
            }
            if (it == '_') {
                res.lvl_down(0);
                break;
            }
        }
        if (no_gram) {
            res.lvl_down(0);
        }

        if (sl == "S") {
            flag = true;
        }

        if (sl != "S" && sr == "_") {
            res.lvl_down(2);
        }

        if (sl.size() > sr.size()) {
            res.lvl_down(2);
        }

        if (sl.size() > 1) {
            res.lvl_down(1);
        }
    } while (cin >> sl >> sr);

    if (!flag) {
        res.lvl_down(0);
    }

    if (check_eps_r && check_S_r) {
        res.lvl_down(2);
    }

    switch (res.r) {
    case 3:
        cout << 23 << endl;
        break;
    case 2:
        cout << 2 << endl;
        break;
    case 1:
        cout << 10 << endl;
        break;
    case 0:
        cout << -1 << endl;
        break;
    }
}
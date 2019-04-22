#include <iostream>
#include <vector>

using namespace std;

enum {
    LEFT = 1,
    RIGHT,
    UP,
    DOWN
};

struct Tractor
{
    int x{};
    int y{};
    int mv{};
    bool backed{false};

    Tractor(int x, int y, int m) : x{x}, y{y}, mv{m}, backed{false} {}

    void move(vector<Tractor> &v)
    {
        switch (mv) {
        case LEFT:
            --x;
            break;
        case RIGHT:
            ++x;
            break;
        case UP:
            ++y;
            break;
        case DOWN:
            --y;
            break;
        }
        if (x == 0 && y != 0) {
            back(v);
        }
    }

    void back(vector<Tractor> &v)
    {
        switch (mv) {
        case LEFT:
            ++x;
            break;
        case RIGHT:
            --x;
            break;
        case UP:
            --y;
            break;
        case DOWN:
            ++y;
            break;
        }
        backed = true;

        for (auto &it : v) {
            if (&it != this && it.x == this->x && it.y == this->y) {
                it.back(v);
            }
        }
    }
};


int main()
{

    int n;
    cin >> n;
    vector<Tractor> t;
    t.reserve(n);

    for (int i = 0; i < n; ++i) {
        int x, y, mv;
        cin >> x >> y >> mv;
        t.emplace_back(x, y, mv);
    }

    for (auto &it : t) {
        it.move(t);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (i != j && t[i].x == t[j].x && t[i].y == t[j].y) {
                if (!t[i].backed) {
                    t[i].back(t);
                }
                if (!t[j].backed) {
                    t[j].back(t);
                }
            }
        }
    }

    for (const auto &it : t) {
        cout << it.x << " " << it.y << endl;
    }
}
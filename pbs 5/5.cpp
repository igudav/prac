#include "4.cpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Creator {
    static Creator &factory_instance()
    {
        static Creator cr;
        return cr;
    }

    Figure *create(const string &s) const
    {
        istringstream iss(s);
        string type, par1, par2;
        iss >> type;
        iss >> par1;
        if (type[0] == 'R') {
            iss >> par2;
            return Rectangle::make(par1 + " " + par2);
        } else if (type[0] == 'C') {
            return Circle::make(par1);
        } else {
            return Square::make(par1);
        }
    }
};

struct Cmp {
    bool operator()(const Figure *f1, const Figure *f2)
    {
        return f1->get_square() < f2->get_square();
    }
};

int main()
{
    std::ifstream in("in");
    std::cin.rdbuf(in.rdbuf());

    string s;
    vector<Figure *> v;
    Creator cr = Creator::factory_instance();

    while(getline(cin, s)) {
        v.push_back(cr.create(s));
    }

    stable_sort(v.begin(), v.end(), Cmp());

    for (auto iter : v) {
        cout << iter->to_string();
        delete iter;
    }
}
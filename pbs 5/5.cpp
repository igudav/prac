#include "4.cpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <memory>

using namespace std;

struct Factory {

    static Factory &factory_instance()
    {
        static Factory fctr;
        return fctr;
    }

    unique_ptr<Figure> create(const string &s) const
    {
        istringstream iss(s);
        string type, par1, par2;
        iss >> type;
        iss >> par1;
        if (type[0] == 'R') {
            iss >> par2;
            return unique_ptr<Figure>(Rectangle::make(par1 + " " + par2));
        } else if (type[0] == 'C') {
            return unique_ptr<Figure>(Circle::make(par1));
        } else {
            return unique_ptr<Figure>(Square::make(par1));
        }
    }

private:

    Factory() = default;

};

struct Cmp {
    bool operator()(const unique_ptr<Figure> &f1, const unique_ptr<Figure> &f2)
    {
        return f1->get_square() < f2->get_square();
    }
};

int main()
{
    std::ifstream in("in.txt");
    std::cin.rdbuf(in.rdbuf());
    /*
     *
     * УБРАТЬ ЭТО НАФИГ !!!!!11
     *
     * И ИНКЛЮД 4.CPP ТОЖЕ!!!!!11
     *
     *
     */

    string s;
    vector<unique_ptr<Figure>> v;
    Factory fctr{Factory::factory_instance()};

    while(getline(cin, s)) {
        v.push_back(fctr.create(s));
    }

    stable_sort(v.begin(), v.end(), Cmp());

    for (const auto &iter : v) {
        cout << iter->to_string();
    }
}
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct Rule {
    string cur_state;
    char c;
    string new_state;

    Rule(const string &curState, char c, const string &newState) : cur_state(curState), c(c),
                                                                   new_state(newState) {}
};

int main() {
    unordered_multimap<string, Rule> umm;

    umm.insert(make_pair("A", Rule("A", 'a', "A")));
    umm.insert(make_pair("A", Rule("A", 'b', "B")));
    umm.insert(make_pair("B", Rule("B", 'a', "A")));

    auto [from, to] = umm.equal_range("A");

    for (; from != to; ++from) {
        cout << from->first << '\t' << from->second.c << endl;
    }

    return 0;
}
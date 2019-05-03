#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>

struct Rule {
    char left;
    std::string right;

    Rule() : left{}, right{} {}

    Rule(const char c, std::string &&s) : left{c}, right{s} {}

    friend bool operator==(const Rule &r1, const Rule &r2);

    void print() const {
        std::cout << left << ' ' << right << std::endl;
    }
};

namespace std {
    template <>
    struct hash<Rule> {
        typedef Rule argument_type;
        typedef size_t result_type;
        result_type operator()(const argument_type &r) const {
            return hash<string>()(r.right + r.left);
        }
    };
}

bool operator==(const Rule &r1, const Rule &r2) {
    return r1.left == r2.left && r1.right == r2.right;
}

int main()
{
    std::unordered_set<Rule> rules;
    std::unordered_set<char> vprev, vcur;

    char left = 0;
    std::string right;

    while (std::cin >> left >> right) {
        rules.insert(Rule(left, std::move(right)));
    }

    vcur.insert('S');

    while (vcur != vprev) {
        vprev = vcur;
        vcur = vprev;
        for (char vl : vprev) {
            for (const Rule &r : rules) {
                if (r.left == vl) {
                    for (char sym : r.right) {
                        vcur.insert(sym);
                    }
                }
            }
        }
    }

    for (const Rule &r : rules) {
        bool prt = (vcur.find(r.left) != vcur.end());
        for (char c : r.right) {
            prt = (prt && (vcur.find(c) != vcur.end() || c == '_'));
        }
        if (prt) {
            r.print();
        }
    }

    return 0;
}
#include <iostream>
#include <cctype>
#include <string>
#include <map>
#include <set>

using namespace std;

bool isterm(char c) {
    return !isupper(c) && c >= 33 && c <= 126;
}

struct Noterm {
    char c;
    set<char> first;
    set<char> follow;

    Noterm() : c{}, first{}, follow{} {}

    Noterm(int ch) : c{(char) ch}, first{}, follow{} {}

    Noterm(const Noterm &other) : c{other.c}, first{other.first}, follow{other.follow} {}

    void find_first(const multimap<char, string> &rules, char ch, set<char> recurs,
            const set<Noterm> &nullable) {
        auto [from, to] = rules.equal_range(ch);
        for (; from != to; ++from) {
            for (int i = 0; i < (int) from->second.size(); ++i) {
                if (isterm(from->second[i])) {
                    first.insert(from->second[i]);
                    break;
                } else {
                    if (recurs.find(from->second[i]) == recurs.end()) {
                        recurs.insert(ch);
                        this->find_first(rules, from->second[i], recurs, nullable);
                    }
                    if (nullable.find(from->second[i]) == nullable.end()) {
                        break;
                    }
                }
            }
        }
    }

    void find_follow(const multimap<char, string> &rules, const set<Noterm> &noterms, char ch,
            char init, const set<Noterm> &nullable) {
        for (const auto &r : rules) {

            int i;
            for (i = r.second.size() - 1; i >= 0; --i) {
                if (r.second[i] == ch) {
                    auto left = noterms.find(r.first);
                    Noterm l = *left;
                    if (r.first != init && r.first != ch) {
                        l.find_follow(rules, noterms, r.first, init, nullable);
                        follow.insert(l.follow.begin(), l.follow.end());
                    }
                }
                if (nullable.find(r.second[i]) == nullable.end()) {
                    break;
                }
            }

            if (r.second.size() > 0 && i >= 0 && r.second[i] == ch) {
                auto left = noterms.find(r.first);
                Noterm l = *left;
                if (r.first != init && r.first != ch) {
                    l.find_follow(rules, noterms, r.first, init, nullable);
                    follow.insert(l.follow.begin(), l.follow.end());
                }
            }

            size_t pos = r.second.find(ch);
            if (pos != string::npos) {
                if (pos == r.second.size() - 1) {
                    continue;
                } else {
                    for (; pos < r.second.size() - 1; ++pos) {
                        if (r.second[pos] != ch && (isterm(r.second[pos]) ||
                                nullable.find(r.second[pos]) == nullable.end())) {
                            break;
                        }
                        if (isterm(r.second[pos + 1])) {
                            follow.insert(r.second[pos + 1]);
                        } else {
                            auto nt = noterms.find(r.second[pos + 1]);
                            follow.insert(nt->first.begin(), nt->first.end());
                        }
                    }
                }
            }
        }
    }

    void print_first() const {
        for (const auto &item : first) {
            cout << item;
        }
        cout << endl;
    }

    void print_follow() const {
        for (const auto &item : follow) {
            cout << item;
        }
        cout << endl;
    }

};

bool operator<(const Noterm &t1, const Noterm &t2) {
    return t1.c < t2.c;
}

bool operator==(const Noterm &t1, const Noterm &t2) {
    return t1.c == t2.c;
}

int main() {
    multimap<char, string> rules;
    set<Noterm> noterms;
    set<Noterm> nullable;

    int c;
    string s;
    while ((c = cin.get()) >= 0) {
        noterms.insert(c);
        int sp;
        sp = cin.get();
        if (sp < 0 || sp == '\n') {
            rules.insert(make_pair(c, string()));
            nullable.insert(c);
        } else {
            cin >> s;
            rules.insert(make_pair(c, s));
            cin.get();
        }
    }

    set<Noterm> new_nullable = nullable;
    do {
        nullable = new_nullable;
        for (const auto &item : rules) {
            bool res = true;
            for (const auto &c : item.second) {
                res = res && (isupper(c) && nullable.find(c) != nullable.end());
            }
            if (res) {
                new_nullable.insert(item.first);
            }
        }
    } while (new_nullable != nullable);

    for (auto it = noterms.begin(); it != noterms.end(); ++it) {
        Noterm nt = *it;
        nt.find_first(rules, nt.c, set<char>(), nullable);
        noterms.erase(it);
        noterms.insert(nt);
    }

    for (auto it = noterms.begin(); it != noterms.end(); ++it) {
        Noterm nt = *it;
        nt.find_follow(rules, noterms, nt.c, nt.c, nullable);
        noterms.erase(it);
        noterms.insert(nt);
    }

    for (const auto &item : noterms) {
        cout << item.c << " " << (nullable.find(item.c) != nullable.end()) << endl;
    }

    for (const auto &item : noterms) {
        cout << item.c << " ";
        item.print_first();
    }

    for (const auto &item : noterms) {
        cout << item.c << " ";
        item.print_follow();
    }

    return 0;
}
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <fstream>

using namespace std;

struct Result {
    bool res;
    int sym_cnt;

    Result() : res{}, sym_cnt{} {}

    Result(bool res, int symCnt) : res(res), sym_cnt(symCnt) {}

    void print() const {
        cout << res << endl << sym_cnt << endl;
    }
};

class State {

    friend struct StateHasher;

    unordered_set<string> us;

public:
    State() : us{} {}

    State(const State &other) : us{other.us} {}

    State(const char *s) : us{} {
        us.insert(string(s));
    }

    State(const string &s) : us{} {
        us.insert(string(s));
    }

    State &operator=(const State &other) {
        us = other.us;
        return *this;
    }

    State &operator+=(const State &other) {
        us.insert(other.us.begin(), other.us.end());
        return *this;
    }

    State &operator=(const string &s) {
        us.clear();
        us.insert(s);
        return *this;
    }

    friend bool operator==(const State &lhs, const State &rhs);

    friend bool operator!=(const State &lhs, const State &rhs);

    friend istream &operator>>(istream &is, State &st);
};

bool operator==(const State &lhs, const State &rhs) {
    return lhs.us == rhs.us;
}

bool operator!=(const State &lhs, const State &rhs) {
    return lhs.us != rhs.us;
}

istream &operator>>(istream &is, State &st) {
    string s;
    cin >> s;
    st.us.clear();
    st.us.insert(s);
    return is;
}

struct StateHasher {
    size_t operator()(const State &st) const {
        size_t res = 0;
        for (const auto &e : st.us) {
            res ^= hash<string>()(e);
        }
        return res;
    }
};

class DetFiniteMachine {

    struct Rule {
        string cur_state;
        char c;
        string new_state;
    };

    unordered_multimap<string, Rule> rules;
    unordered_set<string> final_states;
    string initial_state;

public:
    DetFiniteMachine() : rules{}, final_states{}, initial_state{} {}

    void read() {
        string in;
        cin >> in;
        while (in != "END") {
            Rule r;
            r.cur_state = in;
            cin >> r.c >> r.new_state >> in;
            rules.insert(make_pair(r.cur_state, r));
        }

        cin >> in;
        while (in != "END") {
            final_states.insert(in);
            cin >> in;
        }

        cin >> initial_state;
    }

    Result check(const string &input) const {
        int i = 0;
        char c = input[i];
        string st = initial_state;

        do {
            auto [from, to] = rules.equal_range(st);
            for (; from != to && from->second.c != c; ++from) {}
            if (from == to) {
                return Result(false, i, st);
            }
            ++i;
            st = from->second.new_state;
            c = input[i];
        } while (i < (int) input.size());

        for (const auto &s : final_states) {
            if (st == s) {
                return Result(true, i, st);
            }
        }

        return Result(false, i, st);
    }
};

class NondetFiniteMachine {

    struct Rule {
        State cur_state;
        string c;
        State new_state;
    };

    unordered_multimap<State, Rule, StateHasher> rules;
    unordered_set<State, StateHasher> final_states;
    State initial_state;

public:
    NondetFiniteMachine() : rules{}, final_states{}, initial_state{} {}

    void read() {
        State in;
        cin >> in;
        while (in != "END") {
            Rule r;
            r.cur_state = in;
            cin >> r.c >> r.new_state >> in;
            rules.insert(make_pair(r.cur_state, r));
        }

        cin >> in;
        while (in != "END") {
            final_states.insert(in);
            cin >> in;
        }

        cin >> initial_state;
    }

    void make_det() {



    }

    Result check(const string &input) const {
        int i = 0;
        char c = input[i];
        State st = initial_state;

        do {
            auto [from, to] = rules.equal_range(st);
            //for (; from != to && from->second.c != c; ++from) {}
            if (from == to) {
                return Result(false, i);
            }
            ++i;
            st = from->second.new_state;
            c = input[i];
        } while (i < (int) input.size());

        for (const auto &s : final_states) {
            if (st == s) {
                return Result(true, i);
            }
        }

        return Result(false, i);
    }
};

int main() {
    ifstream is("in.txt");
    cin.rdbuf(is.rdbuf());

    NondetFiniteMachine fm;
    fm.read();
    string input;
}
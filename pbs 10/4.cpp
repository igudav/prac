#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Result {
    bool res;
    int sym_cnt;
    string state;

    Result() : res{}, sym_cnt{}, state{} {}

    Result(bool res, int symCnt, const string &state) : res(res), sym_cnt(symCnt), state(state) {}

    void print() const {
        cout << res << endl << sym_cnt << endl << state << endl;
    }
};

class FiniteMachine {

    struct Rule {
        string cur_state;
        char c;
        string new_state;
    };

    unordered_multimap<string, Rule> rules;
    unordered_set<string> final_states;
    string initial_state;

public:
    FiniteMachine() : rules{}, final_states{}, initial_state{} {}

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

int main() {
    FiniteMachine fm;
    fm.read();
    string input;
    cin >> input;
    fm.check(input).print();
}
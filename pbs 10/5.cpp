#include <string>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <memory>

// Зря что ли про shared_ptr слушал?

using namespace std;

struct State {
    unordered_set<string> us;
    bool is_final;

    explicit State() : us{}, is_final{false} {}

    State(const State &other) : us{other.us}, is_final{other.is_final} {}

    State(const string &s) : us{}, is_final{false} {
        us.insert(s);
    }
};

shared_ptr<State> operator+(const shared_ptr<State> &lhs, const shared_ptr<State> &rhs) {
    auto pst = make_shared<State>();
    pst->is_final = (lhs->is_final || rhs->is_final);
    pst->us.insert(lhs->us.begin(), lhs->us.end());
    pst->us.insert(rhs->us.begin(), rhs->us.end());
    return pst;
}


struct StatePtrHasher {
    size_t operator()(const shared_ptr<State> &pst) const {
        size_t res = 0;
        for (const string &item : pst->us) {
            res ^= hash<string>()(item);
        }
        return res;
    }
};

struct StatePtrEqual {
    bool operator()(const shared_ptr<State> &lhs, const shared_ptr<State> &rhs) const {
        return lhs->us == rhs->us;
    }
};


struct Key {
    shared_ptr<State> pst;
    char c;

    Key() : pst{}, c{} {}

    Key(const shared_ptr<State> &ptr_st, char ch) : pst{ptr_st}, c{ch} {}
};

struct KeyHasher {
    size_t operator()(const Key &k) const {
        return StatePtrHasher()(k.pst) ^ hash<char>()(k.c);
    }
};

struct KeyEqual {
    bool operator()(const Key &lhs, const Key &rhs) const {
        return StatePtrEqual()(lhs.pst, rhs.pst) && lhs.c == rhs.c;
    }
};


struct Rule {
    shared_ptr<State> cur_state;
    char c{};
    shared_ptr<State> new_state;
    bool is_eps{};
};

struct RuleHasher {
    size_t operator()(const Rule &r) const {
        return StatePtrHasher()(r.cur_state) ^ hash<char>()(r.c) ^
                StatePtrHasher()(r.new_state) ^ hash<bool>()(r.is_eps);
    }
};


class NondetFiniteStateMachine {

    unordered_set<shared_ptr<State>, StatePtrHasher, StatePtrEqual> states;
    unordered_multimap<Key, Rule, KeyHasher, KeyEqual> rules;
    shared_ptr<State> init_state;
    unordered_set<Key, KeyHasher, KeyEqual> keys;

    void make_det() {

        unordered_multimap<shared_ptr<State>, Rule, StatePtrHasher, StatePtrEqual> eps_rules;
        unordered_set<shared_ptr<State>, StatePtrHasher, StatePtrEqual> added_states;

        for (auto it = rules.begin(); it != rules.end(); ++it) {
            if(it->second.is_eps) {
                eps_rules.insert(make_pair(it->second.cur_state, it->second));
                rules.erase(it);
            }
        }

        for (auto &r : rules) {
            auto [from, to] = eps_rules.equal_range(r.second.new_state);
            if (from != eps_rules.end()) {
                shared_ptr<State> st = make_shared<State>(r.second.new_state);
                for (; from != to; ++from) {
                    st = st + from->second.new_state;
                }
                auto [it, ins] = states.insert(st);
                r.second.new_state = st;
                if (ins) {
                    added_states.insert(st);
                }
            }
        }

        for (auto &k : keys) {
            Rule r;
            r.cur_state = k.pst;
            r.c = k.c;
            auto [from, to] = rules.equal_range(k);
            for (; from != to; ++from) {
                r.new_state = r.new_state + from->second.new_state;
                rules.erase(from);
            }
            rules.insert(make_pair(k, r));
            if (r.new_state->us.size() > 1) {
                added_states.insert(r.new_state);
            }
        }

        while (!added_states.empty()) {
            for (const auto &k : keys) {
                for (auto it = added_states.begin(); it != added_states.end(); ++it) {
                    Rule r;
                    r.cur_state = *it;
                }
            }
        }
    }

public:
    NondetFiniteStateMachine() : states{}, rules{}, init_state{} {}

    void read() {
        string in;
        cin >> in;

        while (in != "END") {

            shared_ptr<State> pst = make_shared<State>(in);
            Rule r;

            r.cur_state = pst;
            states.insert(pst);

            cin >> in;
            if (in == "eps") {
                r.is_eps = true;
            } else {
                r.is_eps = false;
                r.c = in[0];
                keys.emplace(r.cur_state, r.c);
            }

            cin >> in;
            pst = make_shared<State>(in);
            states.insert(pst);
            r.new_state = pst;

            cin >> in;
        }

        cin >> in;
        while (in != "END") {
            shared_ptr<State> pst = make_shared<State>(in);
            (*states.find(pst))->is_final = true;
        }

        cin >> in;
        shared_ptr<State> pst = make_shared<State>(in);
        init_state = *states.find(pst);

        this->make_det();
    }

    pair<bool, int> process() {}
};

int main() {
    ifstream in("in.txt");
    cin.rdbuf(in.rdbuf());

}
#include "pbs 3/5.cpp"
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>


struct T {
    constexpr static size_t DATA_SIZE = 4;
    constexpr static size_t SYMBOLS = 8;
    uint32_t data[DATA_SIZE];

    T()
    {
        for (size_t i = 0; i < DATA_SIZE; ++i) {
            data[i] = 0;
        }
    }

    T(const std::string &s) : T()
    {
        if (s.size() != 0 && s != "0") {
            std::string p{s};
            p.erase(0, 2);
            if (DATA_SIZE * SYMBOLS > p.size()) {
                p.insert(p.begin(), DATA_SIZE * SYMBOLS - p.size(), '0');
            }
            for (size_t i = 0; i < DATA_SIZE; ++i) {
                std::istringstream iss(p.substr(p.size() - (i + 1) * SYMBOLS, SYMBOLS));
                iss >> std::hex >> data[i];
            }
        }
    }

    std::string to_string() const
    {
        if (data[0] == data[1] == data[2] == data[3] == 0) {
            return std::string{"0"};
        }
        std::ostringstream oss;
        std::string s, res{"0x"};
        for (size_t i = 0; i < DATA_SIZE; ++i) {
            s = "";
            oss.str(s);
            oss << std::hex << std::setfill('0') << std::setw(SYMBOLS) << data[DATA_SIZE - i - 1];
            res += oss.str();
        }
        return res;
    }
};

size_t hash1(const T &t) {
    return std::hash<std::string>()(t.to_string());
}

size_t hash2(const T &t) {
    size_t res = 0;
    for (int i = 0; i < 4; ++i) {
        res ^= std::hash<uint32_t>()(t.data[i]);
    }
    return res;
}

using namespace std;

int main()
{
    Account a{"0x000031241341231"}, b{"0x000031241341231"}, c{"0x000031241F41231"};
    hash<Account>()(a);
}
#include <cstdint>
#include <string>
#include <sstream>
#include <iomanip>

class Account {
    constexpr static size_t DATA_SIZE = 4;
    constexpr static size_t SYMBOLS = 8;
    uint32_t data[DATA_SIZE];

public:

    Account()
    {
        for (size_t i = 0; i < DATA_SIZE; ++i) {
            data[i] = 0;
        }
    }

    Account(const Account &other)
    {
        for (size_t i = 0; i < DATA_SIZE; ++i) {
            data[i] = other.data[i];
        }
    }

    Account(const std::string &s) : Account()
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

    Account(const uint32_t *arr)
    {
        for (size_t i = 0; i < DATA_SIZE; ++i) {
            data[i] = arr[i];
        }
    }

    explicit operator bool() const
    {
        for (auto i : data) {
            if (i != 0) {
                return true;
            }
        }
        return false;
    }

    Account operator !() const
    {
        Account res;
        if (!bool(*this)) {
            res.data[0] = 1;
        }
        return res;
    }

    std::string to_string() const
    {
        if (!*this) {
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

    const uint32_t *cdata() const
    {
        return data;
    }

    friend bool operator ==(const Account &a, const Account &b);
    friend bool operator !=(const Account &a, const Account &b);
    friend bool operator >=(const Account &a, const Account &b);
    friend bool operator <=(const Account &a, const Account &b);
    friend bool operator >(const Account &a, const Account &b);
    friend bool operator <(const Account &a, const Account &b);

};

bool operator ==(const Account &a, const Account &b)
{
    for (size_t i = 0; i < Account::DATA_SIZE; ++i) {
        if (a.data[i] != b.data[i]) {
            return false;
        }
    }
    return true;
}

bool operator !=(const Account &a, const Account &b)
{
    return !(a == b);
}

bool operator >=(const Account &a, const Account &b)
{
    for (size_t i = 0; i < Account::DATA_SIZE; ++i) {
        if (a.data[Account::DATA_SIZE - i - 1] > b.data[Account::DATA_SIZE - i - 1]) {
            return true;
        }
        if (a.data[Account::DATA_SIZE - i - 1] < b.data[Account::DATA_SIZE - i - 1]) {
            return false;
        }
    }
    return true;
}

bool operator <=(const Account &a, const Account &b)
{
    for (size_t i = 0; i < Account::DATA_SIZE; ++i) {
        if (a.data[Account::DATA_SIZE - i - 1] < b.data[Account::DATA_SIZE - i - 1]) {
            return true;
        }
        if (a.data[Account::DATA_SIZE - i - 1] > b.data[Account::DATA_SIZE - i - 1]) {
            return false;
        }
    }
    return true;
}

bool operator >(const Account &a, const Account &b)
{
    return !(a <= b);
}

bool operator <(const Account &a, const Account &b)
{
    return !(a >= b);
}

namespace std {
    template <>
    struct hash<Account> {
        size_t operator()(const Account &acc) const
        {
            return hash<std::string>()(acc.to_string());
        }
    };
}
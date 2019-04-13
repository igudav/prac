#include <string>
#include <vector>

struct StringService {

    int cnt{};
    std::vector<char> buf{};

    StringService() : cnt{1} {}

    explicit StringService(const char *c_str) : cnt{1} {
        for (int i = 0; c_str[i] != '\0'; ++i) {
            buf.push_back(c_str[i]);
        }
    }

    StringService(const StringService &other) : cnt{1}, buf{other.buf} {}

    void append(const StringService *other)
    {
        for (auto it : other->buf) {
            buf.push_back(it);
        }
    }

    void append(const char *c_str)
    {
        for (int i = 0; c_str[i] != '\0'; ++i) {
            buf.push_back(c_str[i]);
        }
    }
};

class String {
    StringService *pss;

public:

    String();

    String(const char *c_str);

    String(const String &other);

    String &operator=(const String &other);

    String &operator=(const char *c_str);

    String &operator+=(const String &other);

    String &operator+=(const char *c_str);

    char operator[](int index) const;

    char &operator[](int index);

    explicit operator std::string();

    ~String();
};

String::String() : pss{new StringService{}} {}

String::String(const char *c_str) : pss{new StringService{c_str}} {}

String::String(const String &other) : pss{other.pss}
{
    ++pss->cnt;
}

String &String::operator=(const String &other)
{
    if (this != &other) {
        if (--pss->cnt <= 0) {
            delete pss;
        }
        pss = other.pss;
        ++pss->cnt;
    }
    return *this;
}

String &String::operator=(const char *c_str)
{
    if (--pss->cnt <= 0) {
        delete pss;
    }
    pss = new StringService{c_str};
    return *this;
}

String& String::operator+=(const String &other)
{
    if (pss->cnt == 1) {
        pss->append(other.pss);
    } else {
        --pss->cnt;
        pss = new StringService{*pss};
        pss->append(other.pss);
    }

    return *this;
}

String& String::operator+=(const char *c_str)
{
    if (pss->cnt == 1) {
        pss->append(c_str);
    } else {
        --pss->cnt;
        pss = new StringService{*pss};
        pss->append(c_str);
    }

    return *this;
}

char String::operator[](int index) const
{
    return pss->buf[index];
}

char& String::operator[](int index)
{
    if (pss->cnt == 1) {
        return pss->buf[index];
    }
    --pss->cnt;
    pss = new StringService{*pss};
    return pss->buf[index];
}

String::operator std::string()
{
    std::string s{};

    for (auto it : pss->buf) {
        s.push_back(it);
    }

    return s;
}

String::~String()
{
    if (--pss->cnt <= 0) {
        delete pss;
    }
}

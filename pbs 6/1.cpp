#include <iostream>
#include <string>

using namespace std;

struct S {

    string s{};

    S()
    {
        if (!(cin >> s)) {
            throw 1;
        }
    }

    ~S()
    {
        cout << s << endl;
    }
};

void proc()
{
    S a = S();
    proc();
}

int main()
{
    try {
        proc();
    } catch (int exc) {}
    return 0;
}
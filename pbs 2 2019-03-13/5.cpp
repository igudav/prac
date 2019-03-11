#include <iostream>

using namespace std;

class S {

    int num;
    bool read, write;

public:

    S() : num{0}, read{false}, write{false}
    {
        int a;
        if (cin >> a) {
            num += a;
            read = true;
        }
    }

    S(S &&src) : num{src.num}, read{false}, write{true}
    {
        int a;
        if (cin >> a) {
            read = true;
            write = false;
            num += a;
        }
    }

    operator bool()
    {
        return read;
    }

    ~S()
    {
        if (write) {
            cout << num << endl;
        }
    }
};
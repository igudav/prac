#include <thread>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<thread> vt;

    for (int i = 0; i < 20; ++i) {
        thread th{[](int val) { cout << val; }, i};
        vt.push_back(move(th));
    }

    for (auto &it : vt) {
        it.join();
    }
}
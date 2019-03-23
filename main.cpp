#include "pbs 4/4.cpp"
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct T {
    int num{};

    explicit T(int a = 0) : num{a} {}

    T(const T &other) = delete;

};

int main()
{
    vector<T> arr(10);
    for (int i = 0; i < 10; ++i) {
        arr[i].num = i;
    }

    set<int> nums{-1, -2, -3, -5, 0, 1, 9, 14};
    auto end_it = myremove(nums.begin(), nums.end(), arr.begin(), arr.end());

    for (auto it = arr.begin(); it != end_it; ++it) {
        cout << it->num << endl;
    }

}
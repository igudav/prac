#include <vector>
#include <algorithm>

using namespace std;

void process(const vector<int> &v_num, vector<int> &v_del)
{
    vector<int> v_c{v_num};

    sort(v_c.begin(), v_c.end());
    auto end_iter = unique(v_c.begin(), v_c.end());

    auto num_iter = v_c.begin();
    auto del_iter1 = v_del.begin();
    auto del_iter2 = v_del.begin();

    while (num_iter != end_iter && *num_iter < 0) {
        ++num_iter;
    }

    for (int i = 0; i < (int) v_del.size() && del_iter2 != v_del.end() && num_iter != end_iter;
            ++i, ++del_iter2) {

        if (i != *num_iter) {
            *del_iter1 = *del_iter2;
            ++del_iter1;
        } else {
            ++num_iter;
        }
    }
    v_del.erase(del_iter1, del_iter2);
}
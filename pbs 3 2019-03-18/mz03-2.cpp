#include <vector>
#include <algorithm>

using namespace std;

void process(const vector<int> &v_num, vector<int> &v_del)
{
    vector<int> v_c{v_num};

    sort(v_c.begin(), v_c.end());
    auto end_iter = unique(v_c.begin(), v_c.end());

    auto num_iter = v_c.begin();
    auto del_iter = v_del.begin() + *num_iter;



}
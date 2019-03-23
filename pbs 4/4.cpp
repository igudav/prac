#include <vector>
#include <algorithm>

template <typename Iter_nums, typename Iter_elem>
Iter_elem myremove(Iter_nums nums_beg, Iter_nums nums_end, Iter_elem elem_beg, Iter_elem elem_end)
{
    std::vector<typename Iter_nums::value_type> v(nums_beg, nums_end);
    std::sort(v.begin(), v.end());
    auto end_v = std::unique(v.begin(), v.end());
    auto beg_v = v.begin();
    for (; beg_v != end_v && *beg_v < 0; ++beg_v) {}

    int i = 0;
    auto it1 = elem_beg;

    for (; elem_beg != elem_end; ++i, ++elem_beg) {
        if (i != *beg_v) {
            *it1 = std::move(*elem_beg);
            ++it1;
        } else {
            ++beg_v;
        }
    }
    return it1;
}
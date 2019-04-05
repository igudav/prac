#include <complex>
#include <vector>
#include <array>

namespace Equations {
    template <typename T>
    std::pair<bool, std::vector<T>> quadratic(std::array<T> v)
    {
        if (v[1] == v[2] == 0) {
            if (v[0] == 0) {
                return std::pair<bool, std::vector<T>>(false, nullptr);
            } else {
                return std::pair<bool, std::vector<T>>(true, std::vector<T>{});
            }
        }
        if ()
    }
}
#include <complex>
#include <vector>
#include <array>

namespace Equations {

    enum { SZ = 3 };

    template <typename T>
    std::pair<bool, std::vector<T>> quadratic(const std::array<T, SZ> &v)
    {
//        typename T::value_type EPS = std::abs(32.0 * std::numeric_limits<T>::epsilon());

        if (v[1] == (typename T::value_type) 0.0 && v[2] == (typename T::value_type) 0.0) {
            if (v[0] == (typename T::value_type) 0.0) {
                return std::make_pair<bool, std::vector<T>>(false, std::vector<T>{});
            } else {
                return std::make_pair<bool, std::vector<T>>(true, std::vector<T>{});
            }
        }
        if (v[2] == (typename T::value_type) 0.0) {
            std::vector<T> vec{};
            vec.push_back(-v[0] / v[1]);
            return std::make_pair<bool, std::vector<T>>(true, std::move(vec));
        }
        T d = v[1] * v[1] - (typename T::value_type) 4.0 * v[2] * v[0];
        T x1 = (-v[1] + sqrt(d)) / ((typename T::value_type) 2.0 * v[2]);
        T x2 = (-v[1] - sqrt(d)) / ((typename T::value_type) 2.0 * v[2]);
        std::vector<T> vec{};
        vec.push_back(x1);
        vec.push_back(x2);
        return std::make_pair<bool, std::vector<T>>(true, std::move(vec));
    }
}
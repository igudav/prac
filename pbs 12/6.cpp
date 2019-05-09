#include <thread>

template <class F1, class F2, class ...Args>
void async_launch(F1 &&f1, F2 &&f2, Args &&...args)
{
    auto thr = std::thread([](F1 &&f1, F2 &&f2, Args &&...args) {
        auto res = f1(std::forward<Args>(args)...);
        f2(std::forward<typeof(res)>(res));
    }, std::forward<F1>(f1), std::forward<F2>(f2), std::forward<Args>(args)...);
    thr.detach();
}
#pragma once
#include <memory>

namespace utils
{
    template <typename T>
    struct cp_ptr : public std::unique_ptr<T>
    {
        using std::unique_ptr<T>::unique_ptr;
    };
}
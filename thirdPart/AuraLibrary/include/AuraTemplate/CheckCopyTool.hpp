#pragma once

#include <type_traits>

template<typename T>
struct HasCopyConstructFunction{
    static constexpr bool value = std::is_copy_constructible<T>::value;
};

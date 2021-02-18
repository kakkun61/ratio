#pragma once

#include <string>

namespace ratio
{
    template<typename T>
    struct ratio
    {
        T numerator;

        T denominator;

        ratio(T n, T d, bool reduce = true);

        ratio(T n);

        auto negate() -> ratio;

        auto reduce() -> ratio;

        auto inverse() -> ratio;

        auto to_double() -> double;

        template<typename CharT, typename Traits = std::char_traits<CharT>, typename Allocator = std::allocator<CharT>>
        auto to_string() -> std::basic_string<CharT, Traits, Allocator>;
    };

    template<typename T>
    auto operator==(ratio<T> l, ratio<T> r) -> bool;

    template<typename T>
    auto operator!=(ratio<T> l, ratio<T> r) -> bool;

    template<typename T>
    auto operator<(ratio<T> l, ratio<T>r) -> bool;

    template<typename T>
    auto operator<=(ratio<T> l, ratio<T>r) -> bool;

    template<typename T>
    auto operator>(ratio<T> l, ratio<T>r) -> bool;

    template<typename T>
    auto operator>=(ratio<T> l, ratio<T>r) -> bool;

    template<typename T>
    auto operator-(ratio<T> r) -> ratio<T>;

    template<typename T>
    auto operator+(ratio<T> l, ratio<T> r) -> ratio<T>;

    template<typename T>
    auto operator-(ratio<T> l, ratio<T> r) -> ratio<T>;

    template<typename T>
    auto operator*(ratio<T> l, ratio<T> r) -> ratio<T>;

    template<typename T>
    auto operator/(ratio<T> l, ratio<T> r) -> ratio<T>;

    template<typename T>
    auto reduce(ratio<T> f) -> ratio<T>;

    template<typename T>
    auto inverse(ratio<T> f) -> ratio<T>;

    template<typename T>
    auto to_double(ratio<T> f) -> double;

    template<typename T, typename CharT, typename Traits = std::char_traits<CharT>, typename Allocator = std::allocator<CharT>>
    auto to_string(ratio<T> f) -> std::basic_string<CharT, Traits, Allocator>;
}

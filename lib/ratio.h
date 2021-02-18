#pragma once

#include <string>

/// \mainpage
/// Rational number.

/// Rational number.
namespace ratio
{
    /// Rational type.
    /// \tparam T a type of this numerator and denominator.
    ///
    /// Named Requirements:
    /// - move constructive
    /// - copy constructive
    /// - move assignable
    /// - copy assignable
    /// - destructible
    /// - trivially copyable
    /// - standard layout type
    /// - equality comparable
    /// - less than comparable
    template<typename T>
    struct ratio
    {
        /// Numerator.
        /// A number over a bar.
        T numerator;

        /// Denominator.
        /// A number under a bar.
        T denominator;

        /// Base constructor.
        /// \param n numerator.
        /// \param d denominator
        /// \param reduce reduce or not.
        ratio(T n, T d = 1, bool reduce = true);

        /// Negate this value.
        auto negate() -> ratio;

        /// Reduce this value.
        /// a denominator of this result is always positive.
        auto reduce() -> ratio;

        /// Invert this value.
        auto invert() -> ratio;

        /// Approximate this into a double-precision floating point number.
        auto to_double() -> double;

        /// Convert this to its string representation.
        /// \tparam CharT
        /// \tparam Traits
        /// \tparam Allocator
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

    /// Return a new reduced value.
    /// a denominator of result is always positive.
    /// \tparam T
    /// \param r
    template<typename T>
    auto reduce(ratio<T> r) -> ratio<T>;

    /// Return a new inverted value.
    /// \tparam T
    /// \param r
    template<typename T>
    auto invert(ratio<T> r) -> ratio<T>;

    /// Approximate this into a double-precision floating point number.
    /// \tparam T
    /// \param r
    template<typename T>
    auto to_double(ratio<T> r) -> double;

    /// Convert this to its string representation.
    /// \tparam T
    /// \tparam CharT
    /// \tparam Traits
    /// \tparam Allocator
    /// \param r
    template<typename T, typename CharT, typename Traits = std::char_traits<CharT>, typename Allocator = std::allocator<CharT>>
    auto to_string(ratio<T> r) -> std::basic_string<CharT, Traits, Allocator>;
}

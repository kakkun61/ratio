#pragma once

#include <exception>
#include <string>
#include <type_traits>

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
        constexpr ratio(T n, T d = 1, bool reduce = true) noexcept;

        /// Negate this value.
        auto negate() noexcept(std::is_signed<T>()) -> ratio;

        /// Reduce this value.
        /// a denominator of this result is always positive.
        auto constexpr reduce() noexcept -> ratio;

        /// Invert this value.
        auto constexpr invert() noexcept -> ratio;

        /// Make this absolute.
        auto constexpr absolute() noexcept -> ratio;

        /// Approximate this into a double-precision floating point number.
        auto constexpr to_double() noexcept -> double;

        /// Approximate this into a nearest integer not less than this.
        auto constexpr ceil() noexcept -> T;

        /// Approximate this into a nearest integer not greater than this.
        auto constexpr floor() noexcept -> T;

        /// Approximate this into a nearest integer not greater in magnitude than this.
        auto constexpr truncate() noexcept -> T;

        /// Approximate this into a nearest integer, rounding away from zero in halfway cases.
        auto constexpr round() noexcept -> T;

        /// Convert this to its string representation.
        /// \tparam CharT
        /// \tparam Traits
        /// \tparam Allocator
        template<typename CharT, typename Traits = std::char_traits<CharT>, typename Allocator = std::allocator<CharT>>
        auto constexpr to_string() noexcept -> std::basic_string<CharT, Traits, Allocator>;
    };

    template<typename T>
    auto constexpr operator==(ratio<T> l, ratio<T> r) noexcept -> bool;

    template<typename T>
    auto constexpr operator!=(ratio<T> l, ratio<T> r) noexcept -> bool;

    template<typename T>
    auto constexpr operator<(ratio<T> l, ratio<T>r) noexcept -> bool;

    template<typename T>
    auto constexpr operator<=(ratio<T> l, ratio<T>r) noexcept -> bool;

    template<typename T>
    auto constexpr operator>(ratio<T> l, ratio<T>r) noexcept -> bool;

    template<typename T>
    auto constexpr operator>=(ratio<T> l, ratio<T>r) noexcept -> bool;

    template<typename T>
    auto constexpr operator-(ratio<T> r) noexcept -> ratio<T>;

    template<typename T>
    auto constexpr operator+(ratio<T> l, ratio<T> r) noexcept -> ratio<T>;

    template<typename T>
    auto constexpr operator-(ratio<T> l, ratio<T> r) noexcept -> ratio<T>;

    template<typename T>
    auto constexpr operator*(ratio<T> l, ratio<T> r) noexcept -> ratio<T>;

    template<typename T>
    auto constexpr operator/(ratio<T> l, ratio<T> r) noexcept -> ratio<T>;

    /// Return a new reduced value.
    /// a denominator of result is always positive.
    /// \tparam T
    /// \param r
    template<typename T>
    auto constexpr reduce(ratio<T> r) noexcept -> ratio<T>;

    /// Return a new inverted value.
    /// \tparam T
    /// \param r
    template<typename T>
    auto constexpr invert(ratio<T> r) noexcept -> ratio<T>;

    /// Return a new absolute value.
    /// \tparam T
    /// \param r
    template<typename T>
    auto constexpr absolute(ratio<T> r) noexcept -> ratio<T>;

    /// Approximate this into a double-precision floating point number.
    /// \tparam T
    /// \param r
    template<typename T>
    auto constexpr to_double(ratio<T> r) noexcept -> double;

    /// Approximate this into a nearest integer not less than this.
    /// \tparam T
    /// \param r
    template<typename T>
    auto constexpr ceil(ratio<T> r) noexcept -> T;

    /// Approximate this into a nearest integer not greater than this.
    /// \tparam T
    /// \param r
    template<typename T>
    auto constexpr floor(ratio<T> r) noexcept -> T;

    /// Approximate this into a nearest integer not greater in magnitude than this.
    /// \tparam T
    /// \param r
    template<typename T>
    auto constexpr truncate(ratio<T> r) noexcept -> T;

    /// Approximate this into a nearest integer, rounding away from zero in halfway cases.
    /// \tparam T
    /// \param r
    template<typename T>
    auto constexpr round(ratio<T> r) noexcept -> T;

    /// Convert this to its string representation.
    /// \tparam T
    /// \tparam CharT
    /// \tparam Traits
    /// \tparam Allocator
    /// \param r
    template<typename T, typename CharT, typename Traits = std::char_traits<CharT>, typename Allocator = std::allocator<CharT>>
    auto constexpr to_string(ratio<T> r) noexcept -> std::basic_string<CharT, Traits, Allocator>;

    struct exception : public std::exception
    {
        exception(char const* const message);

        char const* what() const override;

    private:
        char const* message;
    };
}

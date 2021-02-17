#include "ratio.h"

#include <numeric>
#include <string>

#include <iostream>

using namespace std::literals;

namespace ratio
{
    template struct ratio<int>;

    template<typename T>
    ratio<T>::ratio(T n, T d, bool reduce) : numerator(n), denominator(d)
    {
        if (reduce) this->reduce();
    }

    template<typename T>
    ratio<T>::ratio(T n) : ratio(n, 1, false) {}

    template<typename T>
    auto ratio<T>::negate() -> ratio<T>
    {
        numerator = - numerator;
        return *this;
    }

    template<typename T>
    auto operator-(ratio<T> r) -> ratio<T>
    {
        return r.negate();
    }

    template auto operator-(ratio<int>) -> ratio<int>;

    template<typename T>
    auto operator==(ratio<T> l, ratio<T> r) -> bool
    {
        return l.numerator == r.numerator && l.denominator == r.denominator;
    }

    template auto operator==<int>(ratio<int>, ratio<int> r) -> bool;

    template<typename T>
    auto operator!=(ratio<T> l, ratio<T> r) -> bool
    {
        return !(l == r);
    }

    template<typename T>
    auto operator+(ratio<T> l, ratio<T> r) -> ratio<T>
    {
        return ratio<T>(l.numerator * r.denominator + r.numerator * l.denominator, l.denominator * r.denominator).reduce();
    }

    template auto operator+<int>(ratio<int>, ratio<int>) -> ratio<int>;

    template<typename T>
    auto operator-(ratio<T> l, ratio<T> r) -> ratio<T>
    {
        return l + - r;
    }

    template auto operator-<int>(ratio<int>, ratio<int>) -> ratio<int>;

    template<typename T>
    auto operator*(ratio<T> l, ratio<T> r) -> ratio<T>
    {
        return ratio<T>(l.numerator * r.numerator, l.denominator * r.denominator).reduce();
    }

    template auto operator*<int>(ratio<int>, ratio<int>) -> ratio<int>;

    template<typename T>
    auto operator/(ratio<T> l, ratio<T> r) -> ratio<T>
    {
        return l * r.inverse();
    }

    template auto operator/<int>(ratio<int>, ratio<int>) -> ratio<int>;

    template<typename T>
    auto ratio<T>::reduce() -> ratio<T>
    {
        if (denominator < 0) { numerator *= -1; denominator *= -1; }
        auto m = std::gcd(denominator, numerator);
        numerator /= m;
        denominator /= m;
        return *this;
    }

    template auto ratio<int>::reduce() -> ratio<int>;

    template<typename T>
    auto reduce(ratio<T> r) -> ratio<T>
    {
        return r.reduce();
    }

    template auto reduce<int>(ratio<int>) -> ratio<int>;

    template<typename T>
    auto ratio<T>::inverse() -> ratio<T>
    {
        std::swap(this->numerator, this->denominator);
        return *this;
    }

    template auto ratio<int>::inverse() -> ratio<int>;

    template<typename T>
    auto inverse(ratio<T> r) -> ratio<T>
    {
        return r.inverse();
    }

    template auto inverse<int>(ratio<int>) -> ratio<int>;

    template<typename T>
    auto ratio<T>::to_double() -> double
    {
        return static_cast<double>(this->numerator) / static_cast<double>(this->denominator);
    }

    template auto ratio<int>::to_double() -> double;

    template<typename T>
    auto to_double(ratio<T> r) -> double
    {
        return r.to_double();
    }

    template auto to_double<int>(ratio<int>) -> double;

    template<typename T> template<typename CharT, typename Traits, typename Allocator>
    auto ratio<T>::to_string() -> std::basic_string<CharT, Traits, Allocator>
    {
        return static_cast<double>(this->numerator) / static_cast<double>(this->denominator);
    }

    template auto ratio<int>::to_double() -> double;

    template<typename T, typename CharT, typename Traits, typename Allocator>
    auto to_string(ratio<T> r) -> std::basic_string<CharT, Traits, Allocator>
    {
        return std::to_string(r.numerator) + "/"s + std::to_string(r.denominator);
    }

    template auto to_string<int>(ratio<int>) -> std::string;
}

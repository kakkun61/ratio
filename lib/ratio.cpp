#include "ratio.h"

#include <cmath>
#include <exception>
#include <numeric>
#include <string>

using namespace std::literals;

namespace ratio
{
    template<typename T>
    constexpr ratio<T>::ratio(T n, T d, bool reduce) noexcept : numerator(n), denominator(d)
    {
        if (reduce) this->reduce();
    }

    template<typename T>
    auto constexpr operator==(ratio<T> l, ratio<T> r) noexcept -> bool
    {
        l.reduce();
        r.reduce();
        return l.numerator == r.numerator && l.denominator == r.denominator;
    }

    template auto operator==(ratio<short int>, ratio<short int>) -> bool;
    template auto operator==(ratio<unsigned short int>, ratio<unsigned short int>) -> bool;
    template auto operator==(ratio<int>, ratio<int>) -> bool;
    template auto operator==(ratio<unsigned int>, ratio<unsigned int>) -> bool;
    template auto operator==(ratio<long int>, ratio<long int>) -> bool;
    template auto operator==(ratio<unsigned long int>, ratio<unsigned long int>) -> bool;
    template auto operator==(ratio<long long int>, ratio<long long int>) -> bool;
    template auto operator==(ratio<unsigned long long int>, ratio<unsigned long long int>) -> bool;

    template<typename T>
    auto constexpr operator!=(ratio<T> l, ratio<T> r) noexcept -> bool
    {
        return !(l == r);
    }

    template auto operator!=(ratio<short int>, ratio<short int>) -> bool;
    template auto operator!=(ratio<unsigned short int>, ratio<unsigned short int>) -> bool;
    template auto operator!=(ratio<int>, ratio<int>) -> bool;
    template auto operator!=(ratio<unsigned int>, ratio<unsigned int>) -> bool;
    template auto operator!=(ratio<long int>, ratio<long int>) -> bool;
    template auto operator!=(ratio<unsigned long int>, ratio<unsigned long int>) -> bool;
    template auto operator!=(ratio<long long int>, ratio<long long int>) -> bool;
    template auto operator!=(ratio<unsigned long long int>, ratio<unsigned long long int>) -> bool;

    template<typename T>
    auto constexpr operator<(ratio<T> l, ratio<T> r) noexcept -> bool
    {
        l.reduce();
        r.reduce();
        return l.numerator * r.denominator < r.numerator * l.denominator;
    }

    template auto operator<(ratio<short int>, ratio<short int>) -> bool;
    template auto operator<(ratio<unsigned short int>, ratio<unsigned short int>) -> bool;
    template auto operator<(ratio<int>, ratio<int>) -> bool;
    template auto operator<(ratio<unsigned int>, ratio<unsigned int>) -> bool;
    template auto operator<(ratio<long int>, ratio<long int>) -> bool;
    template auto operator<(ratio<unsigned long int>, ratio<unsigned long int>) -> bool;
    template auto operator<(ratio<long long int>, ratio<long long int>) -> bool;
    template auto operator<(ratio<unsigned long long int>, ratio<unsigned long long int>) -> bool;

    template<typename T>
    auto constexpr operator<=(ratio<T> l, ratio<T> r) noexcept -> bool
    {
        return l < r || l == r;
    }

    template auto operator<=(ratio<short int>, ratio<short int>) -> bool;
    template auto operator<=(ratio<unsigned short int>, ratio<unsigned short int>) -> bool;
    template auto operator<=(ratio<int>, ratio<int>) -> bool;
    template auto operator<=(ratio<unsigned int>, ratio<unsigned int>) -> bool;
    template auto operator<=(ratio<long int>, ratio<long int>) -> bool;
    template auto operator<=(ratio<unsigned long int>, ratio<unsigned long int>) -> bool;
    template auto operator<=(ratio<long long int>, ratio<long long int>) -> bool;
    template auto operator<=(ratio<unsigned long long int>, ratio<unsigned long long int>) -> bool;

    template<typename T>
    auto constexpr operator>(ratio<T> l, ratio<T> r) noexcept -> bool
    {
        return r < l;
    }

    template auto operator>(ratio<short int>, ratio<short int>) -> bool;
    template auto operator>(ratio<unsigned short int>, ratio<unsigned short int>) -> bool;
    template auto operator>(ratio<int>, ratio<int>) -> bool;
    template auto operator>(ratio<unsigned int>, ratio<unsigned int>) -> bool;
    template auto operator>(ratio<long int>, ratio<long int>) -> bool;
    template auto operator>(ratio<unsigned long int>, ratio<unsigned long int>) -> bool;
    template auto operator>(ratio<long long int>, ratio<long long int>) -> bool;
    template auto operator>(ratio<unsigned long long int>, ratio<unsigned long long int>) -> bool;

    template<typename T>
    auto constexpr operator>=(ratio<T> l, ratio<T> r) noexcept -> bool
    {
        return l > r || l == r;
    }

    template auto operator>=(ratio<short int>, ratio<short int>) -> bool;
    template auto operator>=(ratio<unsigned short int>, ratio<unsigned short int>) -> bool;
    template auto operator>=(ratio<int>, ratio<int>) -> bool;
    template auto operator>=(ratio<unsigned int>, ratio<unsigned int>) -> bool;
    template auto operator>=(ratio<long int>, ratio<long int>) -> bool;
    template auto operator>=(ratio<unsigned long int>, ratio<unsigned long int>) -> bool;
    template auto operator>=(ratio<long long int>, ratio<long long int>) -> bool;
    template auto operator>=(ratio<unsigned long long int>, ratio<unsigned long long int>) -> bool;

    template<typename T>
    auto ratio<T>::negate() noexcept(std::is_signed<T>()) -> ratio<T>
    {
        numerator = - numerator;
        return *this;
    }

    template<> auto ratio<unsigned short int>::negate() noexcept(std::is_signed<unsigned short int>()) -> ratio<unsigned short int> { throw exception("unsigned values cannot be negated"); }
    template<> auto ratio<unsigned int>::negate() noexcept(std::is_signed<unsigned int>()) -> ratio<unsigned int> { throw exception("unsigned values cannot be negated"); }
    template<> auto ratio<unsigned long int>::negate() noexcept(std::is_signed<unsigned long int>()) -> ratio<unsigned long int> { throw exception("unsigned values cannot be negated"); }
    template<> auto ratio<unsigned long long int>::negate() noexcept(std::is_signed<unsigned long long int>()) -> ratio<unsigned long long int> { throw exception("unsigned values cannot be negated"); }

    template<typename T>
    auto constexpr operator-(ratio<T> r) noexcept -> ratio<T>
    {
        return r.negate();
    }

    template auto operator-(ratio<short int>) -> ratio<short int>;
    template auto operator-(ratio<int>) -> ratio<int>;
    template auto operator-(ratio<long int>) -> ratio<long int>;
    template auto operator-(ratio<long long int>) -> ratio<long long int>;

    template<typename T>
    auto constexpr operator+(ratio<T> l, ratio<T> r) noexcept -> ratio<T>
    {
        return ratio<T>(static_cast<T>(l.numerator * r.denominator + r.numerator * l.denominator), static_cast<T>(l.denominator * r.denominator)).reduce();
    }

    template auto operator+<short int>(ratio<short int>, ratio<short int>) -> ratio<short int>;
    template auto operator+<unsigned short int>(ratio<unsigned short int>, ratio<unsigned short int>) -> ratio<unsigned short int>;
    template auto operator+<int>(ratio<int>, ratio<int>) -> ratio<int>;
    template auto operator+<unsigned int>(ratio<unsigned int>, ratio<unsigned int>) -> ratio<unsigned int>;
    template auto operator+<long int>(ratio<long int>, ratio<long int>) -> ratio<long int>;
    template auto operator+<unsigned long int>(ratio<unsigned long int>, ratio<unsigned long int>) -> ratio<unsigned long int>;
    template auto operator+<long long int>(ratio<long long int>, ratio<long long int>) -> ratio<long long int>;
    template auto operator+<unsigned long long int>(ratio<unsigned long long int>, ratio<unsigned long long int>) -> ratio<unsigned long long int>;

    template<typename T>
    auto constexpr operator-(ratio<T> l, ratio<T> r) noexcept -> ratio<T>
    {
        return l + r.negate();
    }

    template auto operator-<short int>(ratio<short int>, ratio<short int>) -> ratio<short int>;
    template auto operator-<unsigned short int>(ratio<unsigned short int>, ratio<unsigned short int>) -> ratio<unsigned short int>;
    template auto operator-<int>(ratio<int>, ratio<int>) -> ratio<int>;
    template auto operator-<unsigned int>(ratio<unsigned int>, ratio<unsigned int>) -> ratio<unsigned int>;
    template auto operator-<long int>(ratio<long int>, ratio<long int>) -> ratio<long int>;
    template auto operator-<unsigned long int>(ratio<unsigned long int>, ratio<unsigned long int>) -> ratio<unsigned long int>;
    template auto operator-<long long int>(ratio<long long int>, ratio<long long int>) -> ratio<long long int>;
    template auto operator-<unsigned long long int>(ratio<unsigned long long int>, ratio<unsigned long long int>) -> ratio<unsigned long long int>;

    template<typename T>
    auto constexpr operator*(ratio<T> l, ratio<T> r) noexcept -> ratio<T>
    {
        return ratio<T>(static_cast<T>(l.numerator * r.numerator), static_cast<T>(l.denominator * r.denominator)).reduce();
    }

    template auto operator*<short int>(ratio<short int>, ratio<short int>) -> ratio<short int>;
    template auto operator*<unsigned short int>(ratio<unsigned short int>, ratio<unsigned short int>) -> ratio<unsigned short int>;
    template auto operator*<int>(ratio<int>, ratio<int>) -> ratio<int>;
    template auto operator*<unsigned int>(ratio<unsigned int>, ratio<unsigned int>) -> ratio<unsigned int>;
    template auto operator*<long int>(ratio<long int>, ratio<long int>) -> ratio<long int>;
    template auto operator*<unsigned long int>(ratio<unsigned long int>, ratio<unsigned long int>) -> ratio<unsigned long int>;
    template auto operator*<long long int>(ratio<long long int>, ratio<long long int>) -> ratio<long long int>;
    template auto operator*<unsigned long long int>(ratio<unsigned long long int>, ratio<unsigned long long int>) -> ratio<unsigned long long int>;

    template<typename T>
    auto constexpr operator/(ratio<T> l, ratio<T> r) noexcept -> ratio<T>
    {
        return l * r.invert();
    }

    template auto operator/<short int>(ratio<short int>, ratio<short int>) -> ratio<short int>;
    template auto operator/<unsigned short int>(ratio<unsigned short int>, ratio<unsigned short int>) -> ratio<unsigned short int>;
    template auto operator/<int>(ratio<int>, ratio<int>) -> ratio<int>;
    template auto operator/<unsigned int>(ratio<unsigned int>, ratio<unsigned int>) -> ratio<unsigned int>;
    template auto operator/<long int>(ratio<long int>, ratio<long int>) -> ratio<long int>;
    template auto operator/<unsigned long int>(ratio<unsigned long int>, ratio<unsigned long int>) -> ratio<unsigned long int>;
    template auto operator/<long long int>(ratio<long long int>, ratio<long long int>) -> ratio<long long int>;
    template auto operator/<unsigned long long int>(ratio<unsigned long long int>, ratio<unsigned long long int>) -> ratio<unsigned long long int>;

    template<typename T>
    auto constexpr ratio<T>::reduce() noexcept -> ratio<T>
    {
        if (denominator < 0) { numerator *= static_cast<T>(-1); denominator *= static_cast<T>(-1); }
        auto m = std::gcd(denominator, numerator);
        numerator /= m;
        denominator /= m;
        return *this;
    }

    template<typename T>
    auto constexpr reduce(ratio<T> r) noexcept -> ratio<T>
    {
        return r.reduce();
    }

    template auto reduce<short int>(ratio<short int>) -> ratio<short int>;
    template auto reduce<unsigned short int>(ratio<unsigned short int>) -> ratio<unsigned short int>;
    template auto reduce<int>(ratio<int>) -> ratio<int>;
    template auto reduce<unsigned int>(ratio<unsigned int>) -> ratio<unsigned int>;
    template auto reduce<long int>(ratio<long int>) -> ratio<long int>;
    template auto reduce<unsigned long int>(ratio<unsigned long int>) -> ratio<unsigned long int>;
    template auto reduce<long long int>(ratio<long long int>) -> ratio<long long int>;
    template auto reduce<unsigned long long int>(ratio<unsigned long long int>) -> ratio<unsigned long long int>;

    template<typename T>
    auto constexpr ratio<T>::invert() noexcept -> ratio<T>
    {
        std::swap(this->numerator, this->denominator);
        return *this;
    }

    template<typename T>
    auto constexpr invert(ratio<T> r) noexcept -> ratio<T>
    {
        return r.invert();
    }

    template auto invert<short int>(ratio<short int>) -> ratio<short int>;
    template auto invert<unsigned short int>(ratio<unsigned short int>) -> ratio<unsigned short int>;
    template auto invert<int>(ratio<int>) -> ratio<int>;
    template auto invert<unsigned int>(ratio<unsigned int>) -> ratio<unsigned int>;
    template auto invert<long int>(ratio<long int>) -> ratio<long int>;
    template auto invert<unsigned long int>(ratio<unsigned long int>) -> ratio<unsigned long int>;
    template auto invert<long long int>(ratio<long long int>) -> ratio<long long int>;
    template auto invert<unsigned long long int>(ratio<unsigned long long int>) -> ratio<unsigned long long int>;

    template<typename T>
    auto constexpr abs(T i) -> T
    {
        return i < 0 ? -i : i;
    }

    template<typename T>
    auto constexpr ratio<T>::absolute() noexcept -> ratio<T>
    {
        this->numerator = abs(this->numerator);
        this->denominator = abs(this->denominator);
        return *this;
    }

    template<> auto constexpr ratio<unsigned short int>::absolute() noexcept -> ratio<unsigned short int> { return *this; }
    template<> auto constexpr ratio<unsigned int>::absolute() noexcept -> ratio<unsigned int> { return *this; }
    template<> auto constexpr ratio<unsigned long int>::absolute() noexcept -> ratio<unsigned long int> { return *this; }
    template<> auto constexpr ratio<unsigned long long int>::absolute() noexcept -> ratio<unsigned long long int> { return *this; }

    template<typename T>
    auto constexpr absolute(ratio<T> r) noexcept -> ratio<T>
    {
        return r.absolute();
    }

    template auto absolute<short int>(ratio<short int>) -> ratio<short int>;
    template auto absolute<unsigned short int>(ratio<unsigned short int>) -> ratio<unsigned short int>;
    template auto absolute<int>(ratio<int>) -> ratio<int>;
    template auto absolute<unsigned int>(ratio<unsigned int>) -> ratio<unsigned int>;
    template auto absolute<long int>(ratio<long int>) -> ratio<long int>;
    template auto absolute<unsigned long int>(ratio<unsigned long int>) -> ratio<unsigned long int>;
    template auto absolute<long long int>(ratio<long long int>) -> ratio<long long int>;
    template auto absolute<unsigned long long int>(ratio<unsigned long long int>) -> ratio<unsigned long long int>;

    template<typename T>
    auto constexpr ratio<T>::to_double() noexcept -> double
    {
        return static_cast<double>(this->numerator) / static_cast<double>(this->denominator);
    }

    template<typename T>
    auto constexpr to_double(ratio<T> r) noexcept -> double
    {
        return r.to_double();
    }

    template auto to_double<short int>(ratio<short int>) -> double;
    template auto to_double<unsigned short int>(ratio<unsigned short int>) -> double;
    template auto to_double<int>(ratio<int>) -> double;
    template auto to_double<unsigned int>(ratio<unsigned int>) -> double;
    template auto to_double<long int>(ratio<long int>) -> double;
    template auto to_double<unsigned long int>(ratio<unsigned long int>) -> double;
    template auto to_double<long long int>(ratio<long long int>) -> double;
    template auto to_double<unsigned long long int>(ratio<unsigned long long int>) -> double;

    template<typename T>
    auto constexpr ratio<T>::ceil() noexcept -> T
    {
        auto quot = static_cast<T>( this->numerator / this->denominator);
        auto rem = static_cast<T>(this->numerator % this->denominator);
        if (0 < rem) {
            quot++;
        }
        return quot;
    }

    template<typename T>
    auto constexpr ceil(ratio<T> r) noexcept -> T
    {
        return r.ceil();
    }

    template auto ceil<short int>(ratio<short int>) -> short int;
    template auto ceil<unsigned short int>(ratio<unsigned short int>) -> unsigned short int;
    template auto ceil<int>(ratio<int>) -> int;
    template auto ceil<unsigned int>(ratio<unsigned int>) -> unsigned int;
    template auto ceil<long int>(ratio<long int>) -> long int;
    template auto ceil<unsigned long int>(ratio<unsigned long int>) -> unsigned long int;
    template auto ceil<long long int>(ratio<long long int>) -> long long int;
    template auto ceil<unsigned long long int>(ratio<unsigned long long int>) -> unsigned long long int;

    template<typename T>
    auto constexpr ratio<T>::floor() noexcept -> T
    {
        auto quot = static_cast<T>(this->numerator / this->denominator);
        auto rem = static_cast<T>(this->numerator % this->denominator);
        if (rem < 0) {
            quot--;
        }
        return quot;
    }

    template<typename T>
    auto constexpr floor(ratio<T> r) noexcept -> T
    {
        return r.floor();
    }

    template auto floor<short int>(ratio<short int>) -> short int;
    template auto floor<unsigned short int>(ratio<unsigned short int>) -> unsigned short int;
    template auto floor<int>(ratio<int>) -> int;
    template auto floor<unsigned int>(ratio<unsigned int>) -> unsigned int;
    template auto floor<long int>(ratio<long int>) -> long int;
    template auto floor<unsigned long int>(ratio<unsigned long int>) -> unsigned long int;
    template auto floor<long long int>(ratio<long long int>) -> long long int;
    template auto floor<unsigned long long int>(ratio<unsigned long long int>) -> unsigned long long int;

    template<typename T>
    auto constexpr ratio<T>::truncate() noexcept -> T
    {
        return static_cast<T>(this->numerator / this->denominator);
    }

    template<typename T>
    auto constexpr truncate(ratio<T> r) noexcept -> T
    {
        return r.truncate();
    }

    template auto truncate<short int>(ratio<short int>) -> short int;
    template auto truncate<unsigned short int>(ratio<unsigned short int>) -> unsigned short int;
    template auto truncate<int>(ratio<int>) -> int;
    template auto truncate<unsigned int>(ratio<unsigned int>) -> unsigned int;
    template auto truncate<long int>(ratio<long int>) -> long int;
    template auto truncate<unsigned long int>(ratio<unsigned long int>) -> unsigned long int;
    template auto truncate<long long int>(ratio<long long int>) -> long long int;
    template auto truncate<unsigned long long int>(ratio<unsigned long long int>) -> unsigned long long int;

    template<typename T>
    auto constexpr ratio<T>::round() noexcept -> T
    {
        auto quot = static_cast<T>(this->numerator / this->denominator);
        auto rem = static_cast<T>(this->numerator % this->denominator);
        if (0 < rem) {
            quot++;
        } else if (rem < 0) {
            quot--;
        }
        return quot;
    }

    template<typename T>
    auto constexpr round(ratio<T> r) noexcept -> T
    {
        return r.round();
    }

    template auto round<short int>(ratio<short int>) -> short int;
    template auto round<unsigned short int>(ratio<unsigned short int>) -> unsigned short int;
    template auto round<int>(ratio<int>) -> int;
    template auto round<unsigned int>(ratio<unsigned int>) -> unsigned int;
    template auto round<long int>(ratio<long int>) -> long int;
    template auto round<unsigned long int>(ratio<unsigned long int>) -> unsigned long int;
    template auto round<long long int>(ratio<long long int>) -> long long int;
    template auto round<unsigned long long int>(ratio<unsigned long long int>) -> unsigned long long int;

    template<typename T> template<typename CharT, typename Traits, typename Allocator>
    auto constexpr ratio<T>::to_string() noexcept -> std::basic_string<CharT, Traits, Allocator>
    {
        return std::to_string(this->numerator) + "/"s + std::to_string(this->denominator);
    }

    template<typename T, typename CharT, typename Traits, typename Allocator>
    auto constexpr to_string(ratio<T> r) noexcept -> std::basic_string<CharT, Traits, Allocator>
    {
        return r.template to_string<CharT, Traits, Allocator>();
    }

    template auto to_string<short int>(ratio<short int>) -> std::string;
    template auto to_string<unsigned short int>(ratio<unsigned short int>) -> std::string;
    template auto to_string<int>(ratio<int>) -> std::string;
    template auto to_string<unsigned int>(ratio<unsigned int>) -> std::string;
    template auto to_string<long int>(ratio<long int>) -> std::string;
    template auto to_string<unsigned long int>(ratio<unsigned long int>) -> std::string;
    template auto to_string<long long int>(ratio<long long int>) -> std::string;
    template auto to_string<unsigned long long int>(ratio<unsigned long long int>) -> std::string;

    template struct ratio<short int>;
    template struct ratio<unsigned short int>;
    template struct ratio<int>;
    template struct ratio<unsigned int>;
    template struct ratio<long int>;
    template struct ratio<unsigned long int>;
    template struct ratio<long long int>;
    template struct ratio<unsigned long long int>;

    exception::exception(char const* const message) : message(message) {}

    char const* exception::what() const noexcept
    {
        return message;
    }
}

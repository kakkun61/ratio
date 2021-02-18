#include "ratio.h"

#include <exception>
#include <numeric>
#include <string>

using namespace std::literals;

namespace ratio
{
    template<typename T>
    ratio<T>::ratio(T n, T d, bool reduce) : numerator(n), denominator(d)
    {
        if (reduce) this->reduce();
    }

    template<typename T>
    auto operator==(ratio<T> l, ratio<T> r) -> bool
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
    auto operator!=(ratio<T> l, ratio<T> r) -> bool
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
    auto operator<(ratio<T> l, ratio<T> r) -> bool
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
    auto operator<=(ratio<T> l, ratio<T> r) -> bool
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
    auto operator>(ratio<T> l, ratio<T> r) -> bool
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
    auto operator>=(ratio<T> l, ratio<T> r) -> bool
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
    auto ratio<T>::negate() -> ratio<T>
    {
        numerator = - numerator;
        return *this;
    }

    template<> auto ratio<unsigned short int>::negate() -> ratio<unsigned short int> { throw std::exception("unsigned values cannot be negated"); }
    template<> auto ratio<unsigned int>::negate() -> ratio<unsigned int> { throw std::exception("unsigned values cannot be negated"); }
    template<> auto ratio<unsigned long int>::negate() -> ratio<unsigned long int> { throw std::exception("unsigned values cannot be negated"); }
    template<> auto ratio<unsigned long long int>::negate() -> ratio<unsigned long long int> { throw std::exception("unsigned values cannot be negated"); }

    template<typename T>
    auto operator-(ratio<T> r) -> ratio<T>
    {
        return r.negate();
    }

    template auto operator-(ratio<short int>) -> ratio<short int>;
    template auto operator-(ratio<unsigned short int>) -> ratio<unsigned short int>;
    template auto operator-(ratio<int>) -> ratio<int>;
    template auto operator-(ratio<unsigned int>) -> ratio<unsigned int>;
    template auto operator-(ratio<long int>) -> ratio<long int>;
    template auto operator-(ratio<unsigned long int>) -> ratio<unsigned long int>;
    template auto operator-(ratio<long long int>) -> ratio<long long int>;
    template auto operator-(ratio<unsigned long long int>) -> ratio<unsigned long long int>;

    template<typename T>
    auto operator+(ratio<T> l, ratio<T> r) -> ratio<T>
    {
        return ratio<T>(l.numerator * r.denominator + r.numerator * l.denominator, l.denominator * r.denominator).reduce();
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
    auto operator-(ratio<T> l, ratio<T> r) -> ratio<T>
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
    auto operator*(ratio<T> l, ratio<T> r) -> ratio<T>
    {
        return ratio<T>(l.numerator * r.numerator, l.denominator * r.denominator).reduce();
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
    auto operator/(ratio<T> l, ratio<T> r) -> ratio<T>
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
    auto ratio<T>::reduce() -> ratio<T>
    {
        if (denominator < 0) { numerator *= -1; denominator *= -1; }
        auto m = std::gcd(denominator, numerator);
        numerator /= m;
        denominator /= m;
        return *this;
    }

    template<typename T>
    auto reduce(ratio<T> r) -> ratio<T>
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
    auto ratio<T>::invert() -> ratio<T>
    {
        std::swap(this->numerator, this->denominator);
        return *this;
    }

    template<typename T>
    auto invert(ratio<T> r) -> ratio<T>
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
    auto ratio<T>::to_double() -> double
    {
        return static_cast<double>(this->numerator) / static_cast<double>(this->denominator);
    }

    template<typename T>
    auto to_double(ratio<T> r) -> double
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

    template<typename T> template<typename CharT, typename Traits, typename Allocator>
    auto ratio<T>::to_string() -> std::basic_string<CharT, Traits, Allocator>
    {
        return std::to_string(this->numerator) + "/"s + std::to_string(this->denominator);
    }

    template<typename T, typename CharT, typename Traits, typename Allocator>
    auto to_string(ratio<T> r) -> std::basic_string<CharT, Traits, Allocator>
    {
        return r.to_string<CharT, Traits, Allocator>();
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
}

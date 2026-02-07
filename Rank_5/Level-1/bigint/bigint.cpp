#include "bigint.hpp"

bigint::bigint(unsigned long long n)
{
    if (n == 0)
    {
        digits = "0";
        return;
    }
    while (n > 0)
    {
        digits += (n % 10) + '0';
        n /= 10;
    }
}

bigint bigint::operator+(const bigint& other) const
{
    bigint result;
    result.digits = "";
    int carry = 0;
    size_t max_len = std::max(digits.size(), other.digits.size());
    
    for (size_t i = 0; i < max_len || carry; i++)
    {
        int sum = carry;
        if (i < digits.size())
            sum += digits[i] - '0';
        if (i < other.digits.size())
            sum += other.digits[i] - '0';
        
        result.digits += (sum % 10) + '0';
        carry = sum / 10;
    }
    return (result);
}

bigint& bigint::operator+=(const bigint& other)
{
    *this = *this + other;
    return (*this);
}

bigint& bigint::operator++()
{
    *this += bigint(1);
    return (*this);
}

bigint bigint::operator++(int)
{
    bigint temp = *this;
    ++(*this);
    return (temp);
}

bigint bigint::operator<<(const bigint& shift) const
{
    bigint result = *this;
    unsigned long long n = 0;

    for (int i = shift.digits.size() - 1; i >= 0; i--)
        n = n * 10 + (shift.digits[i] - '0');
    
    if (result.digits != "0")
    {
        for (unsigned long long i = 0; i < n; i++)
            result.digits = "0" + result.digits;
    }
    return (result);
}

bigint bigint::operator>>(const bigint& shift) const
{
    bigint result = *this;
    unsigned long long n = 0;

    for (int i = shift.digits.size() - 1; i >= 0; i--)
        n = n * 10 + (shift.digits[i] - '0');
    
    if (n >= result.digits.size())
        result.digits = "0";
    else
    {
        result.digits = result.digits.substr(n);
        if (result.digits.empty())
            result.digits = "0";
    }
    return (result);
}

bigint& bigint::operator<<=(const bigint& shift)
{
    *this = *this << shift;
    return (*this);
}

bigint& bigint::operator>>=(const bigint& shift)
{
    *this = *this >> shift;
    return (*this);
}

bool bigint::operator==(const bigint& other) const
{
    return (digits == other.digits);
}

bool bigint::operator!=(const bigint& other) const
{
    return !(*this == other);
}

bool bigint::operator<(const bigint& other) const
{
    if (digits.size() != other.digits.size())
        return (digits.size() < other.digits.size());
    
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        if (digits[i] != other.digits[i])
            return (digits[i] < other.digits[i]);
    }
    return (false);
}

bool bigint::operator==(const bigint& other) const
{
    return (digits == other.digits);
}

bool bigint::operator!=(const bigint& other) const
{
    return !(*this == other);
}

bool bigint::operator<=(const bigint& other) const
{
    return (*this < other || *this == other);
}

bool bigint::operator>(const bigint& other) const
{
    return !(*this <= other);
}

bool bigint::operator>=(const bigint& other) const
{
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const bigint& b)
{
    for (int i = b.digits.size() - 1; i >= 0; i--)
    {
        os << b.digits[i];
    }
    return (os);
}
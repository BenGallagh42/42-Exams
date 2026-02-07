#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <iostream>

class bigint
{
    private:
        std::string digits;

    public:
        bigint(unsigned long long n = 0);
    
        bigint operator+(const bigint& other) const;
        bigint& operator+=(const bigint& other);
        bigint& operator++();
        bigint operator++(int);
        
        bigint operator<<(const bigint& shift) const;
        bigint operator>>(const bigint& shift) const;
        bigint& operator<<=(const bigint& shift);
        bigint& operator>>=(const bigint& shift);
        
        bool operator<(const bigint& other) const;
        bool operator<=(const bigint& other) const;
        bool operator>(const bigint& other) const;
        bool operator>=(const bigint& other) const;
        bool operator==(const bigint& other) const;
        bool operator!=(const bigint& other) const;
        
        friend std::ostream& operator<<(std::ostream& os, const bigint& b);
};

#endif
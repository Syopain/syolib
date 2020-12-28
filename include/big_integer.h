#ifndef BIGINTEGER_H
#define BIGINTEGER_H
#include <iostream>
#include <vector>
#include <string>

namespace syo {

    class BigInteger {
        private:
        static int const WIDTH = 8;
        static int const BASE = 100000000;
        std::vector<long long> number;
        bool negative = 0;

        void carry_bit();

    public:
        using sz = std::vector<long long>::size_type;
        BigInteger() = default;
        BigInteger(long long val);
        BigInteger(std::string const& str);
        BigInteger(char const* str) { *this = std::string(str); }
        bool is_negative() const { return negative; }
        BigInteger abs(){
            if(is_negative())
                return -*this;
            return *this;
        }

        sz size() const
        {
            return number.size();
        }

        BigInteger &operator+=(BigInteger const& rhs);
        BigInteger &operator-=(BigInteger const& rhs);
        BigInteger &operator*=(BigInteger const& rhs);
        BigInteger &operator/=(BigInteger const& rhs);
        BigInteger &operator%=(BigInteger const& rhs);
        BigInteger &operator++();
        BigInteger &operator--();
        BigInteger operator++(int);
        BigInteger operator--(int);
        long long &operator[](sz sub)
        {
            return number[sub];
        }
        const long long &operator[](sz sub) const
        {
            return number[sub];
        }
        BigInteger operator+() const
        {
            BigInteger ret(*this);
            return ret;
        }
        BigInteger operator-() const
        {
            BigInteger ret(*this);
            ret.negative = !negative;
            return ret;
        }

        friend BigInteger operator+(BigInteger const& lhs, BigInteger const& rhs);
        friend BigInteger operator-(BigInteger const& lhs, BigInteger const& rhs);
        friend BigInteger operator*(BigInteger const& lhs, BigInteger const& rhs);
        friend BigInteger operator/(BigInteger const& lhs, BigInteger const& rhs);
        friend BigInteger operator%(BigInteger const& lhs, BigInteger const& rhs);
        friend bool operator<(BigInteger const& lhs, BigInteger const& rhs);
        friend bool operator>(BigInteger const& lhs, BigInteger const& rhs);
        friend bool operator<=(BigInteger const& lhs, BigInteger const& rhs);
        friend bool operator>=(BigInteger const& lhs, BigInteger const& rhs);
        friend bool operator==(BigInteger const& lhs, BigInteger const& rhs);
        friend bool operator!=(BigInteger const& lhs, BigInteger const& rhs);
        friend std::istream &operator>>(std::istream &is, BigInteger &num);
        friend std::ostream &operator<<(std::ostream &os, BigInteger const& num);
    };

    BigInteger operator+(BigInteger const& lhs, BigInteger const& rhs);
    BigInteger operator-(BigInteger const& lhs, BigInteger const& rhs);
    BigInteger operator*(BigInteger const& lhs, BigInteger const& rhs);
    BigInteger operator/(BigInteger const& lhs, BigInteger const& rhs);
    BigInteger operator%(BigInteger const& lhs, BigInteger const& rhs);
    bool operator<(BigInteger const& lhs, BigInteger const& rhs);
    bool operator>(BigInteger const& lhs, BigInteger const& rhs);
    bool operator<=(BigInteger const& lhs, BigInteger const& rhs);
    bool operator>=(BigInteger const& lhs, BigInteger const& rhs);
    bool operator==(BigInteger const& lhs, BigInteger const& rhs);
    bool operator!=(BigInteger const& lhs, BigInteger const& rhs);
    std::istream &operator>>(std::istream &is, BigInteger &num);
    std::ostream &operator<<(std::ostream &os, BigInteger const& num);
}

#endif

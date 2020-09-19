#ifndef BIGINTEGER_H
#define BIGINTEGER_H
#include <iostream>
#include <vector>
#include <string>

namespace syo {
    class BigInteger{
    public:
        static const int WIDTH = 8;
        static const int BASE = 100000000;
        std::vector<long long> number;
        bool negative = 0;

        void carry_bit();

    public:
        using sz = std::vector<long long>::size_type;
        BigInteger() = default;
        BigInteger(long long val);
        BigInteger(const std::string &str);
        BigInteger(const char *str) { *this = std::string(str); }
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

        BigInteger &operator+=(const BigInteger &rhs);
        BigInteger &operator-=(const BigInteger &rhs);
        BigInteger &operator*=(const BigInteger &rhs);
        BigInteger &operator/=(const BigInteger &rhs);
        BigInteger &operator%=(const BigInteger &rhs);
        BigInteger &operator++();
        BigInteger &operator--();
        BigInteger operator++(int);
        BigInteger operator--(int);
        long long &operator[](const sz sub)
        {
            return number[sub];
        }
        const long long &operator[](const sz sub) const
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

        friend BigInteger operator+(const BigInteger &lhs, const BigInteger &rhs);
        friend BigInteger operator-(const BigInteger &lhs, const BigInteger &rhs);
        friend BigInteger operator*(const BigInteger &lhs, const BigInteger &rhs);
        friend BigInteger operator/(const BigInteger &lhs, const BigInteger &rhs);
        friend BigInteger operator%(const BigInteger &lhs, const BigInteger &rhs);
        friend bool operator<(const BigInteger &lhs, const BigInteger &rhs);
        friend bool operator>(const BigInteger &lhs, const BigInteger &rhs);
        friend bool operator<=(const BigInteger &lhs, const BigInteger &rhs);
        friend bool operator>=(const BigInteger &lhs, const BigInteger &rhs);
        friend bool operator==(const BigInteger &lhs, const BigInteger &rhs);
        friend bool operator!=(const BigInteger &lhs, const BigInteger &rhs);
        friend std::istream &operator>>(std::istream &is, BigInteger &num);
        friend std::ostream &operator<<(std::ostream &os, const BigInteger &num);
    };

    BigInteger operator+(const BigInteger &lhs, const BigInteger &rhs);
    BigInteger operator-(const BigInteger &lhs, const BigInteger &rhs);
    BigInteger operator*(const BigInteger &lhs, const BigInteger &rhs);
    BigInteger operator/(const BigInteger &lhs, const BigInteger &rhs);
    BigInteger operator%(const BigInteger &lhs, const BigInteger &rhs);
    bool operator<(const BigInteger &lhs, const BigInteger &rhs);
    bool operator>(const BigInteger &lhs, const BigInteger &rhs);
    bool operator<=(const BigInteger &lhs, const BigInteger &rhs);
    bool operator>=(const BigInteger &lhs, const BigInteger &rhs);
    bool operator==(const BigInteger &lhs, const BigInteger &rhs);
    bool operator!=(const BigInteger &lhs, const BigInteger &rhs);
    std::istream &operator>>(std::istream &is, BigInteger &num);
    std::ostream &operator<<(std::ostream &os, const BigInteger &num);

}

    #endif

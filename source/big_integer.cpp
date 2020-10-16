#include "big_integer.h"
#include <algorithm>
#include <cstdio>

namespace syo {


    BigInteger::BigInteger(std::string const& str)
    {
        long long begin = 0, end = str.length();
        if(str[0] == '-'){
            negative = 1;
            begin = 1;
        }
        long long len = (end - 1) / WIDTH + 1;
        for(long long i = 0; i < len; ++i){
            auto subEnd = end - i * WIDTH;
            auto subBegin = std::max(begin, subEnd - WIDTH);
            auto val = std::stol(str.substr(subBegin, subEnd - subBegin));
            sscanf(str.substr(subBegin, subEnd - subBegin).c_str(), "%ld", &val);
            number.push_back(val);
        }
        carry_bit();
    }

    BigInteger::BigInteger(long long val)
    {
        if(val < 0){
            negative = 1;
            val = -val;
        }
        while(val > 0){
            number.push_back(val % BASE);
            val /= BASE;
        }
    }

    BigInteger &BigInteger::operator+=(BigInteger const& rhs)
    {
        if(rhs.is_negative())
            return *this -= -rhs;
        if(is_negative())
            return *this = -(-*this - rhs);

        number.resize(std::max(size(), rhs.size()) + 1);	//???¦Ë??
        for(sz i = 0; i < rhs.size(); ++i){
            number[i] += rhs[i];
        }
        carry_bit();
        return *this;
    }

    BigInteger &BigInteger::operator-=(BigInteger const& rhs)
    {
        if(rhs.is_negative())
            return *this += -rhs;
        if(is_negative())
            return *this = -(-*this + rhs);
        if(*this < rhs)
            return *this = -(rhs - *this);

        for(sz i = 0; i < rhs.size(); ++i){
            number[i] -= rhs[i];
        }
        carry_bit();
        return *this;
    }

    BigInteger &BigInteger::operator*=(BigInteger const& rhs)
    {
        return *this = *this * rhs;
    }

    BigInteger &BigInteger::operator/=(BigInteger const& rhs)
    {
        return *this = *this / rhs;
    }

    BigInteger &BigInteger::operator%=(BigInteger const& rhs)
    {
        return *this = *this % rhs;
    }

    BigInteger &BigInteger::operator++()
    {
        return *this += 1;
    }

    BigInteger &BigInteger::operator--()
    {
        return *this -= 1;
    }

    BigInteger BigInteger::operator++(int)
    {
        BigInteger ret(*this);
        ++*this;
        return ret;
    }

    BigInteger BigInteger::operator--(int)
    {
        BigInteger ret(*this);
        --*this;
        return ret;
    }

    void BigInteger::carry_bit()
    {
        long remainder = 0;
        for(auto &it : number){
            it += remainder;
            if(it >= 0)
                remainder = it / BASE;
            else
                remainder = (it + 1) / BASE - 1;	//???????
            it -= remainder * BASE;
        }
        while(number.back() == 0)
            number.pop_back();
    }

    BigInteger operator+(BigInteger const& lhs, BigInteger const& rhs)
    {
        BigInteger ret(lhs);
        ret += rhs;
        return ret;
    }
    BigInteger operator-(BigInteger const& lhs, BigInteger const& rhs)
    {
        if(lhs < rhs)
            return -(rhs - lhs);
        BigInteger ret(lhs);
        ret -= rhs;
        return ret;
    }
    BigInteger operator*(BigInteger const& lhs, BigInteger const& rhs)
    {
        BigInteger ret;
        ret.number.resize(lhs.size() + rhs.size());

        for(BigInteger::sz i = 0; i < lhs.size(); ++i)
            for(BigInteger::sz j = 0, remainder = 0; j < rhs.size(); ++j){
                ret[i+j] += lhs[i] * rhs[j];
                ret[i+j+1] += ret[i+j] / BigInteger::BASE;
                ret[i+j] %= BigInteger::BASE;
            }
        ret.carry_bit();
        return ret;
    }
    BigInteger operator/(BigInteger const& lhs, BigInteger const& rhs)
    {
        BigInteger begin, end, step(1);

        while(true){
            end = begin;
            while(end * rhs <= lhs){
                begin = end;
                end += step;
                step *= 2;
            }

            if(step == 2){		//end - begin == 1 this moment
                return begin;
            }
            step = 1;
        }
    }
    BigInteger operator%(BigInteger const& lhs, BigInteger const& rhs)
    {
        return lhs - lhs/rhs * rhs;
    }

    bool operator<(BigInteger const& lhs, BigInteger const& rhs)
    {
        if(lhs.size() != rhs.size())
            return lhs.size() < rhs.size();
        for(long long i = lhs.size() - 1; i >= 0; --i){
            if(lhs.number[i] != rhs[i])
                return lhs[i] < rhs[i];
        }
        return false;
    }
    bool operator>(BigInteger const& lhs, BigInteger const& rhs)
    {
        return rhs < lhs;
    }
    bool operator<=(BigInteger const& lhs, BigInteger const& rhs)
    {
        return !(lhs > rhs);
    }
    bool operator>=(BigInteger const& lhs, BigInteger const& rhs)
    {
        return !(lhs < rhs);
    }
    bool operator==(BigInteger const& lhs, BigInteger const& rhs)
    {
        return !(lhs < rhs) && !(lhs > rhs)           ;
    }
    bool operator!=(BigInteger const& lhs, BigInteger const& rhs)
    {
        return lhs < rhs || lhs > rhs;
    }

    std::istream &operator>>(std::istream &is, BigInteger &num)
    {
        std::string input;
        if(is >> input)
            num = input;
        return is;
    }
    std::ostream &operator<<(std::ostream &os, BigInteger const& num)
    {
        if(num.number.empty()){
            os << 0;
            return os;
        }
        if(num.is_negative())
            os << '-';
        os << num.number.back();
        for(long long i = num.size() - 2; i >= 0; --i){
            char buf[BigInteger::WIDTH+1];
            std::sprintf(buf, "%08lld", num[i]);
            buf[BigInteger::WIDTH] = 0;
            std::string output(buf);
            os << output;
        }
        return os;
    }

}

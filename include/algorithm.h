#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <string>
#include "vector.h"
#include <iostream>

namespace syo {

    double calculate(std::string const& expr);
    std::string toSuffix(std::string const& infix);

    template <typename T>
    inline T const& max(T const& a, T const& b) { return a < b ? b : a; }
    template <typename T>
    inline T const& min(T const& a, T const& b) { return a < b ? a : b; }

    inline std::string toString(int num, int base = 10)
    {
        std::string ret;
        while (num) {
            int mod = num % base;
            ret = static_cast<char>((mod < 9) ? (mod + '0') : (mod - 10 + 'A')) + ret;
            num /= base;
        }
        return ret;
    }

    inline std::string toHex(int num)
    {
        return toString(num, 16);
    }

    inline std::string toOct(int num)
    {
        return toString(num, 8);
    }

    inline std::string toBin(int num)
    {
        return toString(num, 2);
    }

}

#endif // ALGORITHM_H

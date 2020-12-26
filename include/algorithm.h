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

    std::string toString(int num, int base = 10);
    std::string toString(double num, int base = 10, int place = 7);
    inline std::string toHex(int num) { return toString(num, 16); }
    inline std::string toHex(double num) { return toString(num, 16); }
    inline std::string toOct(int num) { return toString(num, 8); }
    inline std::string toOct(double num) { return toString(num, 8); }
    inline std::string toBin(int num) { return toString(num, 2); }
    inline std::string toBin(double num) { return toString(num, 2); }

    void print_permutation(int s[], int n);
    void print_combination(int n, int r);
}

#endif // ALGORITHM_H

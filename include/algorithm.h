#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <string>

namespace syo {

    double calculate(std::string const& expr);
    std::string toSuffix(std::string const& infix);

    template <typename T>
    inline T const& max(T const& a, T const& b) { return a < b ? b : a; }
    template <typename T>
    inline T const& min(T const& a, T const& b) { return a < b ? a : b; }

}

#endif // ALGORITHM_H

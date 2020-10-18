#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <string>

namespace syo {

    double calculate(std::string const& expr);
    std::string toSuffix(std::string const& infix);

}

#endif // ALGORITHM_H

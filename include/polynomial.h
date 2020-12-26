#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <map>
#include <iostream>

namespace syo {

    class Polynomial
    {
    public:
        Polynomial();
        Polynomial(double coefficient, int exponent);
        Polynomial& operator+=(Polynomial const& rhs);
        Polynomial &operator*=(Polynomial const& rhs);
        void clear() { terms.clear(); }
    private:
        std::map<int, double> terms;

        friend Polynomial operator+(Polynomial const& lhs, Polynomial const& rhs);
        friend Polynomial operator*(Polynomial const& lhs, Polynomial const& rhs);
        friend std::ostream& operator<<(std::ostream& os, Polynomial const& poly);
    };

    //Non-member function:
    Polynomial operator+(Polynomial const& lhs, Polynomial const& rhs);
    Polynomial operator*(Polynomial const& lhs, Polynomial const& rhs);
    std::ostream& operator<<(std::ostream& os, Polynomial const& poly);
}


#endif // POLYNOMIAL_H

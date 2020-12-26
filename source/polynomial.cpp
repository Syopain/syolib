#include "polynomial.h"

namespace syo {

    Polynomial::Polynomial()
    {

    }

    Polynomial::Polynomial(double coefficient, int exponent)
    {
        terms.insert(std::make_pair(exponent, coefficient));
    }


    Polynomial &Polynomial::operator+=(const Polynomial &rhs)
    {
        for (auto const& iter : rhs.terms) {
            terms[iter.first] += iter.second;
        }
        return *this;
    }

    Polynomial &Polynomial::operator*=(const Polynomial &rhs)
    {
        Polynomial lhs = *this;
        clear();
        for (auto const& l : lhs.terms) {
            for (auto const& r : rhs.terms) {
                *this += Polynomial(l.second * r.second, l.first + r.first);
            }
        }
        return *this;
    }

    Polynomial operator+(Polynomial const& lhs, Polynomial const& rhs)
    {
        Polynomial sum = lhs;
        sum += rhs;
        return sum;
    }

    Polynomial operator*(Polynomial const& lhs, Polynomial const& rhs)
    {
        Polynomial product = lhs;
        product *= rhs;
        return product;
    }

    std::ostream& operator<<(std::ostream& os, Polynomial const& poly)
    {
        auto crbegin = poly.terms.crbegin();
        auto crend = poly.terms.crend();
        for (auto r_iter = crbegin; r_iter != crend; ++r_iter) {
            if (r_iter->second == 0)
                continue;
            os << (r_iter->second > 0 ? (r_iter != crbegin ? "+ " : "") : "- ");
            if (std::abs(r_iter->second) != 1) {
                os << std::abs(r_iter->second);
            }
            if (r_iter->first != 0) {
                os << "x";
                if (r_iter->first != 1)
                    os << "^" << r_iter->first;
                os << " ";
            }
        }
        return os;
    }

}


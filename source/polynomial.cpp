#include "polynomial.h"
#include <cmath>

namespace syo {

    Polynomial::Polynomial()
    {

    }

    Polynomial::Polynomial(double coefficient, int exponent)
    {
        if (coefficient)
            terms.insert(std::make_pair(exponent, coefficient));
    }

    Polynomial::Polynomial(const std::pair<int, double> &term)
    {
        if (term.first)
            terms.insert(term);
    }

    Polynomial &Polynomial::operator+=(const Polynomial &rhs)
    {
        for (auto const& iter : rhs.terms) {
            terms[iter.first] += iter.second;
            if (terms[iter.first] == 0) {
                terms.erase(iter.first);
            }
        }
        return *this;
    }

    Polynomial &Polynomial::operator-=(const Polynomial &rhs)
    {
        return *this += (-rhs);
    }

    Polynomial &Polynomial::operator*=(const Polynomial &rhs)
    {
        return *this = *this * rhs;
    }

    Polynomial &Polynomial::operator/=(const Polynomial &rhs)
    {
        return *this = *this / rhs;
    }

    Polynomial &Polynomial::operator%=(const Polynomial &rhs)
    {
        return *this -= *this / rhs * rhs;
    }

    const Polynomial operator+(Polynomial const& lhs, Polynomial const& rhs)
    {
        Polynomial result = lhs;
        result += rhs;
        return result;
    }

    const Polynomial operator*(Polynomial const& lhs, Polynomial const& rhs)
    {
        Polynomial result;
        for (auto const& l : lhs.terms) {
            for (auto const& r : rhs.terms) {
                result += Polynomial(l.second * r.second, l.first + r.first);
            }
        }

        return result;
    }

    const Polynomial operator-(Polynomial const& lhs, Polynomial const& rhs)
    {
        return lhs + (-rhs);
    }

    const Polynomial operator+(Polynomial const& rhs)
    {
        return rhs;
    }

    const Polynomial operator-(Polynomial const& rhs)
    {
        Polynomial result = rhs;
        for (auto& i : result.terms) {
            i.second = -i.second;
        }
        return result;
    }

    const Polynomial operator/(Polynomial const& lhs, Polynomial const& rhs)
    {
        if ((lhs.terms.crbegin()->first) < (rhs.terms.crbegin()->first)) {
            return Polynomial();
        }
        Polynomial result = Polynomial(lhs.terms.crbegin()->second / rhs.terms.crbegin()->second,
                                       lhs.terms.crbegin()->first - rhs.terms.crbegin()->first);

        return result + (lhs - result * rhs) / rhs;
    }

    const Polynomial operator%(Polynomial const& lhs, Polynomial const& rhs)
    {
        Polynomial result = lhs;
        result %= rhs;
        return result;
    }

    double Polynomial::evaluate(double x) const
    {
        double result = 0;
        for (auto const& term : terms) {
            result += term.second * std::pow(x, term.first);
        }
        return result;
    }


    const Polynomial pow(const Polynomial &base, int exponent)
    {
        if (exponent < 0)
            std::cerr << "exponent cannot be less than 0" << std::endl;
        if (exponent == 0)
            return Polynomial(1, 0);
        if (exponent == 1)
            return base;

        Polynomial result = pow(base, exponent/2);
        result *= result;
        if (exponent & 1)
            result *= base;

        return result;
    }

    std::ostream& operator<<(std::ostream& os, Polynomial const& poly)
    {
        if (poly.terms.size() == 0){
            return os << 0;
        }
        auto crbegin = poly.terms.crbegin();
        auto crend = poly.terms.crend();
        for (auto r_iter = crbegin; r_iter != crend; ++r_iter) {
            if (r_iter->second == 0)
                continue;
            os << (r_iter->second > 0 ? (r_iter != crbegin ? "+ " : "") : "- ");
            if (std::abs(r_iter->second) != 1 || r_iter->first == 0) {
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

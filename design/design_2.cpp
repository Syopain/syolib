#include <iostream>
#include <algorithm>
#include <sstream>
#include "polynomial.h"

using syo::Polynomial;

static void design_2_1()
{
    std::cout << "Design_2_1:\n" << std::endl;

    Polynomial poly = Polynomial(7, 0) + Polynomial(-1, 1) + Polynomial(2, 3) + Polynomial(3, 4);
    std::cout << "多项式的显示:\n";
    std::cout << poly << std::endl << std::endl;;

    Polynomial poly1 = Polynomial(1, 2) + Polynomial(-3, 1) + Polynomial(2, 0);
    Polynomial poly2 = Polynomial(2, 1) + Polynomial(5, 0);
    std::cout << "多项式1: " << poly1 << std::endl;
    std::cout << "多项式2: " << poly2 << std::endl;
    std::cout << "它们的和: " << poly1 + poly2 << std::endl;
    std::cout << "它们的积: " << poly1 * poly2 << std::endl;
    std::cout << std::endl;
}

int gcd(int a, int b)
{
    if (b)
        printf("( %d, %d ) = ", a, b);
    else
        printf("%d\n", a);
    return b ? gcd(b, a%b) : a;
}

#ifndef NDEBUG
int lcm(int a, int b)
{
    int ans = 1;
    std::ostringstream oss;
    printf("[ %d, %d ] = ", a, b);
    for (int k = 2; k < std::min(a, b); ++k) {
        if (a % k == 0 && b % k == 0) {
            std::cout << dynamic_cast<std::ostringstream&>(oss << k << " * ").str();
            a /= k;
            b /= k;
            printf("[ %d, %d ] = ", a, b);
            ans *= k;
            k = 1;
        }
    }
    std::cout << oss.str() << a*b << " = " << (ans *= a * b) << std::endl;
    return ans;
}
#else
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
#endif


static void design_2_2()
{
    std::cout << "Design_2_2:\n" << std::endl;

    gcd(48, 36);
    lcm(36, 48);
    std::cout << std::endl;
}

void design_2()
{
    design_2_1();
    design_2_2();
}

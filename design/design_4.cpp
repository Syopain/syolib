#include <iostream>
#include "algorithm.h"
#include "polynomial.h"

using syo::Polynomial;

static void design_4_1()
{
    std::cout << "Design_4_1:\n" << std::endl;

    syo::print_yh_triangle(10);

    std::cout << std::endl;
}

static void design_4_2()
{
    std::cout << "Design_4_2:\n" << std::endl;

    Polynomial poly = Polynomial(3, 4) + Polynomial(2, 3) + Polynomial(-1, 1) + Polynomial(7, 0);
    std::cout << "多项式: " << poly << std::endl;
    std::cout << "它的 3 次方: " << syo::pow(poly, 3) << std::endl << std::endl;

    Polynomial poly1 = Polynomial(1, 1) + Polynomial(1, 0);
    std::cout << "多项式: " << poly1 << std::endl;
    std::cout << "它的 9 次方: " << syo::pow(poly1, 9) << std::endl << std::endl;

    std::cout << "多项式: " << poly << std::endl;
    std::cout << "x = 5时, 多项式的值为: " << poly.evaluate(5) << std::endl << std::endl;

    std::cout << std::endl;
}

void design_4()
{
    design_4_1();
    design_4_2();
}

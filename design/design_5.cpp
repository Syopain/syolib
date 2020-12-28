#include "polynomial.h"

using syo::Polynomial;

static void design_5_1()
{
    std::cout << "Design_5_1:\n" << std::endl;

    Polynomial poly1 = Polynomial(1, 1) + 1;
    Polynomial poly2 = Polynomial(5, 2) - Polynomial(2, 1) + 1;

    std::cout << "��������ʽ: " << poly1 << std::endl;
    std::cout << "������ʽ: " << poly2 << std::endl;
    std::cout << "�̶���ʽ: " << poly1 / poly2 << std::endl;
    std::cout << "�����ʽ: " << poly1 % poly2 << std::endl;
    std::cout << std::endl;

    poly1 = Polynomial(7, 3) - Polynomial(5, 2) + Polynomial(6, 1) - 4;
    poly2 = Polynomial(2, 1) + 3;
    std::cout << "��������ʽ: " << poly1 << std::endl;
    std::cout << "������ʽ: " << poly2 << std::endl;
    std::cout << "�̶���ʽ: " << poly1 / poly2 << std::endl;
    std::cout << "�����ʽ: " << poly1 % poly2 << std::endl;
    std::cout << std::endl;
}

void design_5()
{
    design_5_1();
}

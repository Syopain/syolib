#include <iostream>
#include "algorithm.h"

static void design_8_1()
{
    std::cout << "Design_8_1:\n" << std::endl;

    std::string str1 = "Ilovemymum";
    std::string str2 = "doyouloveme";
    std::cout << "字符串1: " << str1 << std::endl;
    std::cout << "字符串2: " << str2 << std::endl;
    std::cout << "最大公共子串: " << syo::lcstring(str1, str2) << std::endl;
    std::cout << std::endl;

    str1 = "31415926535";
    str2 = "2371592658";
    std::cout << "字符串1: " << str1 << std::endl;
    std::cout << "字符串2: " << str2 << std::endl;
    std::cout << "最大公共子串: " << syo::lcstring(str1, str2) << std::endl;
    std::cout << std::endl;
}

void design_8()
{
    design_8_1();
}

#include "algorithm.h"

static void design_1_1()
{
    std::cout << "Design_1_1\n" << std::endl;

    std::printf("十进制数%d = 二进制数%s = 八进制数%s = 十六进制数%s\n",
                586,
                syo::toBin(586).c_str(),
                syo::toOct(586).c_str(),
                syo::toHex(586).c_str()
    );
    std::printf("十进制数%d = 二进制数%s = 八进制数%s = 十六进制数%s\n",
                210,
                syo::toBin(210).c_str(),
                syo::toOct(210).c_str(),
                syo::toHex(210).c_str()
    );
    std::cout << std::endl;
}

static void design_1_2()
{
    std::cout << "Design_1_2\n" << std::endl;

    std::cout << "从1到5的数为: 1 2 3 4 5" << std::endl << std::endl;
    std::cout << "从中任取3个数的所有可能组合(不重复, 从大到小显示)是:" << std::endl;

    syo::print_combination(5, 3);
    std::cout << std::endl;
}

void design_1()
{
    design_1_1();
    design_1_2();
}

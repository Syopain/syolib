#include "algorithm.h"

static void design_1_1()
{
    std::cout << "Design_1_1\n" << std::endl;

    std::printf("ʮ������%d = ��������%s = �˽�����%s = ʮ��������%s\n",
                586,
                syo::toBin(586).c_str(),
                syo::toOct(586).c_str(),
                syo::toHex(586).c_str()
    );
    std::printf("ʮ������%d = ��������%s = �˽�����%s = ʮ��������%s\n",
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

    std::cout << "��1��5����Ϊ: 1 2 3 4 5" << std::endl << std::endl;
    std::cout << "������ȡ3���������п������(���ظ�, �Ӵ�С��ʾ)��:" << std::endl;

    syo::print_combination(5, 3);
    std::cout << std::endl;
}

void design_1()
{
    design_1_1();
    design_1_2();
}

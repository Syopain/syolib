#include "algorithm.h"


static void design_3_1()
{
    std::cout << "Design_3_1\n" << std::endl;

    double n = 0.2389;
    std::printf("ʮ������%lf = ��������%s = �˽�����%s = ʮ��������%s\n",
                n,
                syo::toBin(n).c_str(),
                syo::toOct(n).c_str(),
                syo::toHex(n).c_str()
    );

    n = 210.2389;
    std::printf("ʮ������%lf = ��������%s = �˽�����%s = ʮ��������%s\n",
                n,
                syo::toBin(n).c_str(),
                syo::toOct(n).c_str(),
                syo::toHex(n).c_str()
    );
    std::cout << std::endl;
}

static void design_3_2()
{
    std::cout << "Design_3_2\n" << std::endl;

    std::cout << "��2��8��ż��Ϊ:  2 4 6 8\n" << std::endl;
    std::cout << "�������ǿ��ܵ�������:\n";
    int s[] = {2, 4, 6, 8};
    syo::print_permutation(s, 4);
    std::cout << std::endl;
}

void design_3()
{
    design_3_1();
    design_3_2();
}

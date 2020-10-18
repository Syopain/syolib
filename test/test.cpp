#include <iostream>
#include "vector.h"
#include "forward_list.h"
#include "test.hpp"

using namespace syo;

int main_ret = 0;
int test_count = 0;
int test_pass = 0;

void test_vector();
void test_forward_list();
void exercise_6();
void exercise_3();

using namespace std;

int main()
{
    //system("chcp 65001");
    test_vector();
    test_forward_list();

    exercise_6();

    printf("test: %d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    return main_ret;
}

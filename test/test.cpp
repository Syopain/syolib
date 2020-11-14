#include <iostream>
#include "vector.h"
#include "forward_list.h"
#include "binary_tree.h"
#include "test.h"
#include "exercise/exercise.h"

int main_ret = 0;
int test_count = 0;
int test_pass = 0;

void test_vector();
void test_forward_list();
void test_binary_tree();

static void test()
{
    test_vector();
    test_forward_list();
    test_binary_tree();
}

int main()
{
    system("chcp 65001");
    test();

    exercise_11();
    printf("test: %d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    getchar();
    return main_ret;
}

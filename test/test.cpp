#include <iostream>
#include "vector.h"
#include "forward_list.h"
#include "binary_tree.h"
#include "test.h"
#include "../exercise/exercise.h"
#include "../design/design.h"

int main_ret = 0;
int test_count = 0;
int test_pass = 0;

static void test()
{
    test_vector();
    test_forward_list();
    test_binary_tree();
}

int main()
{
    test();

    design_8();
    printf("test: %d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    return main_ret;
}

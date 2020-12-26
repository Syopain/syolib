#ifndef TEST_HPP
#define TEST_HPP
#include <iostream>
#include <cassert>

extern int main_ret;
extern int test_count;
extern int test_pass;

#define EXPECT_EQ_BASE(expect, actual) \
    do {\
        ++test_count;\
        if (expect == actual)\
            ++test_pass;\
        else {\
            std::cerr << __FILE__ << ":" << __LINE__ << ": expect: " << expect << " actual: " << actual << std::endl;\
            main_ret = 1;\
        }\
    } while(0)

void test_vector();
void test_forward_list();
void test_binary_tree();

#endif // TEST_HPP

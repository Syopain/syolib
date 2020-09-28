#include <iostream>
#include <cassert>
#include "vector.h"
#include "forward_list.h"

using namespace syo;

static int main_ret = 0;
static int test_count = 0;
static int test_pass = 0;

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

static void test_vector_constructor()
{
    Vector<int> ivec;
    EXPECT_EQ_BASE(0, ivec.size());

    ivec = Vector<int> (20, 123);
    EXPECT_EQ_BASE(20, ivec.size());
    for (size_t i = 0; i < ivec.size(); ++i) {
        EXPECT_EQ_BASE(123, ivec[i]);
        EXPECT_EQ_BASE(123, ivec.at(i));
    }

    ivec = Vector<int> (20);
    EXPECT_EQ_BASE(20, ivec.size());
    for (size_t i = 0; i < ivec.size(); ++i) {
        EXPECT_EQ_BASE(0, ivec[i]);
        EXPECT_EQ_BASE(0, ivec.at(i));
    }

    ivec = {0, 1, 2, 3, 4, 5, 6, 7 ,8 ,9 ,10, 11, 12 ,13, 14, 15, 16, 17};
    const auto ivec2 = ivec;
    EXPECT_EQ_BASE(18, ivec.size());
    for (size_t i = 0; i < ivec.size(); ++i) {
        EXPECT_EQ_BASE(static_cast<int>(i), ivec[i]);
        EXPECT_EQ_BASE(static_cast<int>(i), ivec.at(i));
        EXPECT_EQ_BASE(static_cast<int>(i), ivec2[i]);
        EXPECT_EQ_BASE(static_cast<int>(i), ivec2.at(i));
    }
}

static void test_vector_alter()
{

    Vector<int> ivec;
    for (size_t i = 0; i != 24; ++i) {
        ivec.push_back(i);
        EXPECT_EQ_BASE(i + 1, ivec.size());
        EXPECT_EQ_BASE(static_cast<int>(i), ivec[i]);
        ivec[i] *= 2;
        EXPECT_EQ_BASE(static_cast<int>(i*2), ivec[i]);
    }

    for (size_t i = ivec.size(); i != 0; --i) {
        EXPECT_EQ_BASE(i, ivec.size());
        ivec.pop_back();
    }

    ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ivec.insert(4, 3, 15);
    EXPECT_EQ_BASE(13, ivec.size());
    for (size_t i = 4; i < 7; ++i) {
        EXPECT_EQ_BASE(15, ivec[i]);
    }

    ivec.remove(4, 3);
    EXPECT_EQ_BASE(10, ivec.size());
    for (size_t i = 0; i < ivec.size(); ++i) {
        EXPECT_EQ_BASE(static_cast<int>(i), ivec[i]);
    }
}

static void test_vector()
{
    test_vector_constructor();
    test_vector_alter();
}

static void test_forward_list_constructor()
{
    ForwardList<int> lst;
    EXPECT_EQ_BASE(0, lst.length());

    lst = ForwardList<int> (12, 15);
    EXPECT_EQ_BASE(12, lst.length());
    auto iter = lst.begin();
    for (int i = 0; i < 12; ++i) {
        EXPECT_EQ_BASE(15, *iter++);
        EXPECT_EQ_BASE(15, lst[i]);
    }
    assert(lst.end() == iter);

    lst = ForwardList<int> (10);
    EXPECT_EQ_BASE(10, lst.length());
    iter = lst.begin();
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ_BASE(0, *iter++);
        EXPECT_EQ_BASE(0, lst[i]);
    }
    assert(lst.end() == iter);

    lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ_BASE(10, lst.length());
    iter = lst.begin();
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ_BASE(i, *iter++);
        EXPECT_EQ_BASE(i, lst[i]);
    }
    assert(lst.end() == iter);
}

static void test_forward_list_alter()
{

}

static void test_forward_list()
{
    test_forward_list_constructor();
}

static void exercise_2()
{
    using std::cout;
    using std::endl;

    cout << "Exercise_2:" << endl << endl;

    Vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Original ArrayList: \n";

    cout << "Array List: " << ivec << endl << endl;;

    cout << "Insert 3 elements at index 4: \n";
    ivec.insert(4, 3, 15);
    cout << "Array List: " << ivec << endl << endl;

    cout << "Remove 2 elements at index 3: \n";
    ivec.remove(3, 2);
    cout << "Array List: " << ivec << endl << endl;
}

static void exercise_3_1()
{
    using std::cout;
    using std::endl;

    cout << "Exercise_3_1:" << endl << endl;

    Vector<int> ivec;
    cout << "Array List: " << ivec << endl << endl;

    cout << "Insert 10: \n";
    ivec.insert_in_order(10);
    cout << "Array List: " << ivec << endl << endl;

    cout << "Insert 3: \n";
    ivec.insert_in_order(3);
    cout << "Array List: " << ivec << endl << endl;

    cout << "Insert 7: \n";
    ivec.insert_in_order(7);
    cout << "Array List: " << ivec << endl << endl;

    cout << "Insert 1: \n";
    ivec.insert_in_order(1);
    cout << "Array List: " << ivec << endl << endl;

    cout << "Insert 5: \n";
    ivec.insert_in_order(5);
    cout << "Array List: " << ivec << endl << endl;

    cout << "Insert 4: \n";
    ivec.insert_in_order(4);
    cout << "Array List: " << ivec << endl << endl;
}

static void exercise_3_2()
{
    using std::cout;
    using std::endl;

    cout << "Exercise_3_2:" << endl << endl;

    Vector<int> ivec = {1, -1, 3, 4, -3, 5, -6, -2, 9, -3};
    cout << "Original ArrayList: \n" << ivec << endl << endl;

    ivec.sort_by_sign();
    cout << "Called sort_by_sign(): \n" << ivec << endl << endl;

}

static void exercise_4_1()
{
    using std::cout;
    using std::endl;

    cout << "Exercise_4_1:" << endl << endl;

    ForwardList<int> lst = {9, 3, 5, 4, 8, 5, 2, 5, 6};
    cout << "Array List: " << lst << endl << endl;

    cout << "List Length: " << lst.length() << endl << endl;

    for (auto item : {5, 12, 15}) {
        if (lst.index_of(item) >= 0)
            cout << "The first " << item << " appears in: " << lst.index_of(item)  << endl << endl;
        else
            cout << "The first " << item << " appears in: Not found!"  << endl << endl;
    }

    cout << "Index 4: " << lst[4] << endl << endl;
}

static void exercise_4_2()
{

}

int main()
{
    test_vector();
    test_forward_list();

    exercise_4_1();
    exercise_4_2();

    printf("test: %d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    return main_ret;
}

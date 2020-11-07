#include "test.h"
#include "forward_list.h"

using syo::ForwardList;

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
    ForwardList<int> lst;
    EXPECT_EQ_BASE(0, lst.length());

    auto iter = lst.end();
    for (int i = 0; i < 10; ++i) {
        lst.insert(iter, i);
        EXPECT_EQ_BASE(i, lst[i]);
        EXPECT_EQ_BASE(i + 1, static_cast<int>(lst.length()));
    }

    for (int i = 0; i < 9; ++i) {
        lst.erase(lst.begin());
        EXPECT_EQ_BASE(9 - i, static_cast<int>(lst.length()));
        EXPECT_EQ_BASE(i + 1, *lst.begin());
    }
}

void test_forward_list()
{
    test_forward_list_constructor();
    test_forward_list_alter();
}

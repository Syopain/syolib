#include "test.h"
#include "vector.h"

using syo::Vector;

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

void test_vector()
{
    test_vector_constructor();
    test_vector_alter();
}

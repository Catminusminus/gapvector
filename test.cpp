#include "gtest/gtest.h"
#include "gapvector.hpp"

TEST(test_gapvector, size)
{
    my::gapvector<int> gap_v;
    gap_v.push_back(1);
    gap_v.push_back(2);
    ASSERT_EQ(2, gap_v.size());
}

TEST(test_gapvector, subscript_operator)
{
    my::gapvector<int> gap_v;
    gap_v.push_back(1);
    gap_v.push_back(2);
    ASSERT_EQ(1, gap_v[0]);
    ASSERT_EQ(2, gap_v[1]);
}
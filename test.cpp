#include "gtest/gtest.h"
#include "gapvector.hpp"

class TestGapvector : public ::testing::Test
{
  protected:
    my::gapvector<int> gap_v;
    virtual void SetUp()
    {
        gap_v.push_back(1);
        gap_v.push_back(2);
    }
    virtual void TearDown()
    {
        gap_v.clear();
    }
};

TEST_F(TestGapvector, size)
{
    ASSERT_EQ(2, gap_v.size());
}

TEST_F(TestGapvector, subscript_operator)
{
    ASSERT_EQ(1, gap_v[0]);
    ASSERT_EQ(2, gap_v[1]);
}

TEST_F(TestGapvector, insert)
{
    gap_v.insert(1, 3);
    ASSERT_EQ(3, gap_v.size());
    ASSERT_EQ(3, gap_v[1]);
}

TEST_F(TestGapvector, erase)
{
    gap_v.insert(1, 3);
    gap_v.erase(1);
    ASSERT_EQ(2, gap_v.size());
    ASSERT_EQ(2, gap_v[1]);
}

TEST_F(TestGapvector, at)
{
    ASSERT_EQ(1, gap_v.at(0));
    ASSERT_EQ(2, gap_v.at(1));
    ASSERT_THROW(gap_v.at(2), std::out_of_range);
}

TEST_F(TestGapvector, copy)
{
    my::gapvector<int> gap_v2 = gap_v;
    ASSERT_EQ(1, gap_v2.at(0));
    ASSERT_EQ(2, gap_v2.at(1));
    gap_v.erase(1);
    ASSERT_EQ(2, gap_v2.at(1));
}
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

TEST_F(TestGapvector, front)
{
    ASSERT_EQ(1, gap_v.front());
    gap_v.front() = 3;
    ASSERT_EQ(3, gap_v[0]);
}

TEST_F(TestGapvector, back)
{
    ASSERT_EQ(2, gap_v.back());
    gap_v.back() = 3;
    ASSERT_EQ(3, gap_v[1]);
}

TEST_F(TestGapvector, begin)
{
    auto itr = gap_v.begin();
    ASSERT_FALSE(itr == gap_v.end());
    ASSERT_EQ(1, *itr);
    ++itr;
    ASSERT_EQ(2, *itr);
}

TEST_F(TestGapvector, loop)
{
    int i = 1;
    for (auto itr = gap_v.begin(); itr != gap_v.end(); ++itr)
    {
        ASSERT_EQ(i, *itr);
        ++i;
    }
    ASSERT_EQ(3, i);
}

TEST_F(TestGapvector, insert_itr)
{
    auto itr = gap_v.begin();
    itr = gap_v.insert(itr, 3);
    ASSERT_EQ(3, gap_v.size());
    ASSERT_EQ(3, gap_v[0]);
    ++itr;
    ASSERT_EQ(1, *(itr));
}

TEST_F(TestGapvector, erase_itr)
{
    auto itr = gap_v.begin();
    itr = gap_v.insert(itr, 3);
    itr = gap_v.erase(itr);
    ASSERT_EQ(2, gap_v[1]);
}

TEST_F(TestGapvector, loop_const)
{
    int i = 1;
    for (auto itr = gap_v.cbegin(); itr != gap_v.cend(); ++itr)
    {
        ASSERT_EQ(i, *itr);
        ++i;
    }
}

TEST_F(TestGapvector, insert_itr_plus)
{
    gap_v.push_back(3);
    auto itr = gap_v.insert(gap_v.begin() + 1, 4);
    ASSERT_EQ(4, *itr);
    ASSERT_EQ(4, gap_v[1]);
}

TEST_F(TestGapvector, empty)
{
    ASSERT_FALSE(gap_v.empty());
    gap_v.clear();
    ASSERT_TRUE(gap_v.empty());
}

TEST_F(TestGapvector, insert_itr_itr_itr)
{
    my::gapvector<int> gap_v2;
    gap_v2.push_back(3);
    gap_v2.push_back(4);
    gap_v.insert(gap_v.begin(), gap_v2.begin(), gap_v2.end());
    ASSERT_EQ(4, gap_v.size());
    gap_v2.insert(gap_v2.begin(), gap_v.begin(), gap_v.end());
    ASSERT_EQ(6, gap_v2.size());
}

TEST_F(TestGapvector, emplace_back)
{
    gap_v.emplace_back(3);
    ASSERT_EQ(3, gap_v[2]);
}

TEST_F(TestGapvector, constructors)
{
    my::gapvector<int> gap_v2 = gap_v;
    ASSERT_EQ(2, gap_v2.size());

    my::gapvector<int> gap_v3(gap_v);
    ASSERT_EQ(2, gap_v3.size());

    my::gapvector<int> gap_v4 = {1, 2};
    ASSERT_EQ(2, gap_v4.size());

    my::gapvector<int> gap_v5({1, 2});
    ASSERT_EQ(2, gap_v5.size());
}

TEST_F(TestGapvector, substitution)
{
    my::gapvector<int> gap_v2;
    gap_v2 = gap_v;
    ASSERT_EQ(2, gap_v2.size());

    my::gapvector<int> gap_v4;
    gap_v4 = {1, 2};
    ASSERT_EQ(2, gap_v4.size());
}

TEST_F(TestGapvector, emplace)
{
    auto itr = gap_v.cbegin();
    auto itr2 = gap_v.emplace(itr, 3, 4);
    ASSERT_EQ(4, gap_v.size());
    ASSERT_EQ(4, gap_v[1]);
    ASSERT_EQ(4, *itr2);
}

TEST_F(TestGapvector, assign)
{
    my::gapvector<int> gap_v2 = gap_v;
    gap_v2.assign({1, 2, 3, 4});
    ASSERT_EQ(4, gap_v2.size());

    my::gapvector<int> gap_v3 = gap_v;
    gap_v3.assign(5, 1);
    ASSERT_EQ(5, gap_v3.size());

    my::gapvector<int> gap_v4;
    gap_v4.assign(gap_v.begin(), gap_v.end());
    ASSERT_EQ(2, gap_v4.size());
}

TEST_F(TestGapvector, loop_reverse)
{
    int i = 1;
    for (auto itr = gap_v.rbegin(); itr != gap_v.rend(); ++itr)
    {
        ASSERT_EQ(3 - i, *itr);
        ++i;
    }
    ASSERT_EQ(2, gap_v.at(gap_v.size() - 1));
    ASSERT_EQ(3, i);
}

TEST_F(TestGapvector, swap)
{
    my::gapvector<int> gap_v2({1, 2, 3, 4});
    gap_v.swap(gap_v2);
    ASSERT_EQ(4, gap_v.size());
    ASSERT_EQ(2, gap_v2.size());
}

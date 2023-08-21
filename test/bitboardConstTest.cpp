#include <gtest/gtest.h>

#include "../src/includes/bitboardConst.hpp"

using namespace QuoridorAI;
using namespace Constant;

TEST(BitboardConstTest, FenceMaskByFenceNoneZeroTest)
{
    ASSERT_TRUE(fenceMaskByFence.size() == NumberOfFence);

    for (auto itr = fenceMaskByFence.begin(); itr != fenceMaskByFence.end(); ++itr)
    {
        EXPECT_FALSE((*itr).second == 0);
    }
}

TEST(BitboardConstTest, FenceMaskBySquareEdgeNoneZeroTest)
{
    // vertical

    ASSERT_TRUE(fenceMaskBySquareEdge[Vertical].size() == NumberOfFence / 2);

    for (auto itr = fenceMaskBySquareEdge[Vertical].begin(); itr != fenceMaskBySquareEdge[Vertical].end(); ++itr)
    {
        EXPECT_FALSE((*itr).second == 0);
    }

    // horizontal

    ASSERT_TRUE(fenceMaskBySquareEdge[Horizontal].size() == NumberOfFence / 2);

    for (auto itr = fenceMaskBySquareEdge[Horizontal].begin(); itr != fenceMaskBySquareEdge[Horizontal].end(); ++itr)
    {
        EXPECT_FALSE((*itr).second == 0);
    }
}
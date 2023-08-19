#include <gtest/gtest.h>
#include "../src/includes/wall.hpp"

using namespace QuoridorAI;

TEST(WallBBODTest, WallBBODHorizontalIsThereWallTest)
{
    WallBBOD<Horizontal> hw;

    /*
        wall existing at: a1-b1, b2-c2, c3-d3, d4-e4, e5-f5, f6-g6, g7-h7, i8-j8
    */
    hw = WallBBOD<Horizontal>(Bitboard96(
        "0b100000000001000000000100000000010000000001000000000100000000010000000001"));

    // all the true conditinos

    EXPECT_TRUE(hw.IsThereWall(FileA, Rank1));
    EXPECT_TRUE(hw.IsThereWall(FileB, Rank2));
    EXPECT_TRUE(hw.IsThereWall(FileC, Rank3));
    EXPECT_TRUE(hw.IsThereWall(FileD, Rank4));
    EXPECT_TRUE(hw.IsThereWall(FileE, Rank5));
    EXPECT_TRUE(hw.IsThereWall(FileF, Rank6));
    EXPECT_TRUE(hw.IsThereWall(FileG, Rank7));
    EXPECT_TRUE(hw.IsThereWall(FileI, Rank8));

    // some false conditions

    EXPECT_FALSE(hw.IsThereWall(FileB, Rank1));
    EXPECT_FALSE(hw.IsThereWall(FileD, Rank8));
    EXPECT_FALSE(hw.IsThereWall(FileE, Rank2));
    EXPECT_FALSE(hw.IsThereWall(FileF, Rank3));
    EXPECT_FALSE(hw.IsThereWall(FileH, Rank7));
}
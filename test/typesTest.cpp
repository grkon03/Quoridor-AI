/**
 * @file typesTest.cpp
 * @author grkon03
 * @brief testcases for types.hpp/.cpp
 *
 */

#include <gtest/gtest.h>
#include "../src/includes/types.hpp"

using namespace QuoridorAI;

TEST(TypesTest, GetFileGetRankTest)
{
    SquareEdge se = SE_C7;

    EXPECT_EQ(FileC, GetFile(se));
    EXPECT_EQ(Rank7, GetRank(se));
}

TEST(TypesTest, MakeSquareTest)
{
    SquareEdge se1, se2;

    // successfully make

    se1 = SE_A8; // 0x1010000
    se2 = SE_B9; // 0x1011011

    EXPECT_EQ(0x5b50, MakeSquare(se1, se2));
    EXPECT_EQ(0x5b50, MakeSquare(se2, se1));

    se1 = SE_D4; // 0x101011 (+1)
    se2 = SE_E3; // 0x100010 (-1)

    EXPECT_EQ(0x2c21, MakeSquare(se1, se2));
    EXPECT_EQ(0x2c21, MakeSquare(se2, se1));

    // fatal

    se1 = SE_A9;
    se2 = SE_J7;

    EXPECT_EQ(Square::SquareInvalid, MakeSquare(se1, se2));
    EXPECT_EQ(Square::SquareInvalid, MakeSquare(se2, se1));

    se1 = SE_I2;
    se2 = SE_I4;

    EXPECT_EQ(Square::SquareInvalid, MakeSquare(se1, se2));
    EXPECT_EQ(Square::SquareInvalid, MakeSquare(se2, se1));
}
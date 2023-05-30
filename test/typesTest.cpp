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

    se1 = SE_A8; // 0b1010000
    se2 = SE_B9; // 0b1011011

    EXPECT_EQ(0x5b50, MakeSquare(se1, se2));
    EXPECT_EQ(0x5b50, MakeSquare(se2, se1));

    se1 = SE_D4; // 0b101011 (+1)
    se2 = SE_E3; // 0b100010 (-1)

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

TEST(TypesTest, MakeFenceTest)
{
    SquareEdge se1, se2;

    // successfully make

    se1 = SE_D3; // 0b100001
    se2 = SE_D5; // 0b110101

    EXPECT_EQ(0x3521, MakeFence(se1, se2));
    EXPECT_EQ(0x3521, MakeFence(se2, se1));

    se1 = SE_F7; // 0b1001011
    se2 = SE_H7; // 0b1001101

    EXPECT_EQ(0x4d4b, MakeFence(se1, se2));
    EXPECT_EQ(0x4d4b, MakeFence(se2, se1));

    // fatal

    se1 = SE_A7;
    se2 = SE_I6;

    EXPECT_EQ(Fence::FenceInvalid, MakeFence(se1, se2));
    EXPECT_EQ(Fence::FenceInvalid, MakeFence(se2, se1));

    se1 = SE_C8;
    se2 = SE_D9;

    EXPECT_EQ(Fence::FenceInvalid, MakeFence(se1, se2));
    EXPECT_EQ(Fence::FenceInvalid, MakeFence(se2, se1));
}

TEST(TypesTest, MakeMoveTest)
{
    SquareEdge se1, se2;

    // successfully make
    // using testcases used MakeSquareTest, MakeFenceTest

    // derived from MakeSquareTest

    se1 = SE_A8; // 0b1010000
    se2 = SE_B9; // 0b1011011

    EXPECT_EQ(0x5b50, MakeMove(se1, se2));
    EXPECT_EQ(0x5b50, MakeMove(se2, se1));

    se1 = SE_D4; // 0b101011 (+1)
    se2 = SE_E3; // 0b100010 (-1)

    EXPECT_EQ(0x2c21, MakeMove(se1, se2));
    EXPECT_EQ(0x2c21, MakeMove(se2, se1));

    // derived from MakeFenceTest

    se1 = SE_D3; // 0b100001
    se2 = SE_D5; // 0b110101

    EXPECT_EQ(0x3521, MakeMove(se1, se2));
    EXPECT_EQ(0x3521, MakeMove(se2, se1));

    se1 = SE_F7; // 0b1001011
    se2 = SE_H7; // 0b1001101

    EXPECT_EQ(0x4d4b, MakeMove(se1, se2));
    EXPECT_EQ(0x4d4b, MakeMove(se2, se1));

    // fatal

    // derived from MakeSquareTest

    se1 = SE_A9;
    se2 = SE_J7;

    EXPECT_EQ(Move::MoveInvalid, MakeMove(se1, se2));
    EXPECT_EQ(Move::MoveInvalid, MakeMove(se2, se1));

    // derived from MakeFenceTest

    se1 = SE_A7;
    se2 = SE_I6;

    EXPECT_EQ(Move::MoveInvalid, MakeMove(se1, se2));
    EXPECT_EQ(Move::MoveInvalid, MakeMove(se2, se1));

    // ohter

    se1 = SE_I7;
    se2 = SE_C2;

    EXPECT_EQ(Move::MoveInvalid, MakeMove(se1, se2));
    EXPECT_EQ(Move::MoveInvalid, MakeMove(se2, se1));
}

TEST(TypesTest, IsAnyMoveTest)
{
    SquareEdge se1, se2;
    Move move;

    // square case

    se1 = SE_E3;
    se2 = SE_D4;
    move = MakeMove(se1, se2);

    EXPECT_EQ(true, IsKingMove(move));
    EXPECT_EQ(false, IsFenceMove(move));

    // fence case

    se1 = SE_J1;
    se2 = SE_J3;
    move = MakeMove(se1, se2);

    EXPECT_EQ(false, IsKingMove(move));
    EXPECT_EQ(true, IsFenceMove(move));

    se1 = SE_F8;
    se2 = SE_H8;
    move = MakeMove(se1, se2);

    EXPECT_EQ(false, IsKingMove(move));
    EXPECT_EQ(true, IsFenceMove(move));
}
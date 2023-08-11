#include <gtest/gtest.h>
#include <iostream>
#include "../../src/includes/types.hpp"
#include "../../src/includes/hasher/HasherAllIncludes.hpp"

using namespace QuoridorAI;
using namespace QuoridorAI::Hasher;

TEST(ZobristKeyTest, ZobristKeyTest)
{
    int i;

    for (i = 0; i < NumberOfSquare; ++i)
    {
        ASSERT_TRUE(ZobristKey::general.SquareKey[White][i] > 0);
        ASSERT_TRUE(ZobristKey::general.SquareKey[Black][i] > 0);
        ASSERT_TRUE(ZobristHash::basicKeys.SquareKey[White][i] > 0);
        ASSERT_TRUE(ZobristHash::basicKeys.SquareKey[Black][i] > 0);
    }

    for (i = 0; i < NumberOfFence; ++i)
    {
        ASSERT_TRUE(ZobristKey::general.FenceKey[i] > 0);
        ASSERT_TRUE(ZobristHash::basicKeys.FenceKey[i] > 0);
    }
}

TEST(ZobristHashTest, ZobristHashNoRegardForOrderTest)
{
    ZobristHash hash1 = ZobristHash();
    ZobristHash hash2 = ZobristHash();

    ASSERT_TRUE(hash1 == hash2);

    // same position from different ways

    hash1.GetNextKey(MakeMove(SE_E1, SE_F2));
    hash1.GetNextKey(MakeMove(SE_E7, SE_F8));
    hash1.GetNextKey(MakeMove(SE_E2, SE_F3));
    hash1.GetNextKey(MakeMove(SE_E6, SE_F7));
    hash1.GetNextKey(MakeMove(SE_E3, SE_F4));
    hash1.GetNextKey(MakeMove(SE_E5, SE_F6));
    hash1.GetNextKey(MakeMove(SE_E4, SE_F5));
    hash1.GetNextKey(MakeMove(SE_E6, SE_G6));
    hash1.GetNextKey(MakeMove(SE_E3, SE_F4));

    hash2.GetNextKey(MakeMove(SE_E1, SE_F2));
    hash2.GetNextKey(MakeMove(SE_E7, SE_F8));
    hash2.GetNextKey(MakeMove(SE_E2, SE_F3));
    hash2.GetNextKey(MakeMove(SE_E6, SE_F7));
    hash2.GetNextKey(MakeMove(SE_E3, SE_F4));
    hash2.GetNextKey(MakeMove(SE_E5, SE_F6));
    hash2.GetNextKey(MakeMove(SE_F3, SE_G4));
    hash2.GetNextKey(MakeMove(SE_E6, SE_G6));
    hash2.GetNextKey(MakeMove(SE_E3, SE_F4));

    EXPECT_TRUE(hash1 == hash2);
}
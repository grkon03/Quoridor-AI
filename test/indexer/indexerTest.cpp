#include <gtest/gtest.h>
#include <iostream>
#include "../../src/includes/types.hpp"
#include "../../src/includes/indexer/IndexerAllIncludes.hpp"

using namespace QuoridorAI;

TEST(IndexerTest, SquareIndexerTest)
{
    Square s;
    for (int i = 0; i < 81; ++i)
    {
        s = Indexer::indexer.IndexedSquare[i];
        ASSERT_NE(s, SquareInvalid);
        ASSERT_NE(s, 0);
        EXPECT_EQ(i, Indexer::SquareToIndex(s));
    }
}

TEST(IndexerTest, FenceIndexerTest)
{
    Fence f;
    for (int i = 0; i < 128; ++i)
    {
        f = Indexer::indexer.IndexedFence[i];
        ASSERT_NE(f, FenceInvalid);
        ASSERT_NE(f, 0);
        EXPECT_EQ(i, Indexer::FenceToIndex(f));
    }
}

TEST(IndexerTest, MoveIndexerTest)
{
    Move m;
    for (int i = 0; i < 209; ++i)
    {
        m = Indexer::indexer.IndexedMove[i];
        ASSERT_NE(m, MoveInvalid);
        ASSERT_NE(m, 0);
        EXPECT_EQ(i, Indexer::MoveToIndex(m));
    }
}
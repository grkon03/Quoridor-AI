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
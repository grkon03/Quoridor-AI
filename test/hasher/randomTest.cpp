#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "../../src/includes/types.hpp"
#include "../../src/includes/hasher/HasherAllIncludes.hpp"

using namespace QuoridorAI;
using namespace QuoridorAI::Hasher;

// verify no-conflict of MTRandomizer
TEST(RandomizerTest, MTRandomizerTest)
{
    Randomizer *r = new MTRandomizer(64, 2906);
    std::vector<HashKey> list;
    int size = 290;

    for (int i = 0; i < size; ++i)
    {
        list.push_back(r->next());
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            EXPECT_NE(list[i], list[j]);
        }
    }
}
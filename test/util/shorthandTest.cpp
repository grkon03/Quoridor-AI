#include <gtest/gtest.h>

#include <algorithm>

#include "../../src/includes/util/shorthand.hpp"
#include "../../src/includes/indexer/IndexerAllIncludes.hpp"

using namespace QuoridorAI;
using namespace QuoridorAI::Util;

TEST(UtilTest, MakeIMoveSNsTest)
{
    std::vector<std::string> sns;
    std::vector<int> cor;

    sns = {
        // valid case

        "Kc3",
        "Vg7",
        "Hf2",

        // invalid case

        "Kf9",
        "Kj2",

        "Va3",
        "Vj6",
        "Vc9",

        "Hc0",
        "Hf9",
        "Hi2",
    };

    cor = {
        // valid case
        Indexer::MoveToIndex(MakeMove(SE_C3, SE_D4)),
        Indexer::MoveToIndex(MakeMove(SE_G7, SE_G9)),
        Indexer::MoveToIndex(MakeMove(SE_F2, SE_H2)),

        // invalid case
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
    };

    EXPECT_TRUE(std::equal(cor.begin(), cor.end(), MakeIMoveSNs(sns).begin()));
}
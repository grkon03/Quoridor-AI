#include <gtest/gtest.h>
#include "../src/includes/bitboard.hpp"

using namespace QuoridorAI;

TEST(Bitboard96Comparations, Bitboard96Comprations)
{
    Bitboard96 b, c;
    EXPECT_EQ(b, c);
}

TEST(Bitboard96Constructions, Bitboard96ConstructionsWithString)
{
    Bitboard96 a, b;

    a = Bitboard96(0xffff, 0xffffUL);

    b = Bitboard96("ffff000000000000ffff", misc::BaseType::BT_HEX);
    EXPECT_EQ(a, b);
    b = Bitboard96("ffff000000000000fffa", misc::BaseType::BT_HEX);
    EXPECT_NE(a, b);
    b = Bitboard96(
        std::string("111111111111111100000000000000000000000000000000") +
            std::string("00000000000000001111111111111111"),
        misc::BaseType::BT_BIN);
    EXPECT_EQ(a, b);
    b = Bitboard96("0xffff000000000000ffff");
    EXPECT_EQ(a, b);
    b = Bitboard96(
        std::string("0b111111111111111100000000000000000000000000000000") +
        std::string("00000000000000001111111111111111"));
    EXPECT_EQ(a, b);

    a = Bitboard96(0xeaff9f91U, 0xf10083eabc87d6deULL);

    b = Bitboard96("0xeaff9f91f10083eabc87d6de");
    EXPECT_EQ(a, b);
}
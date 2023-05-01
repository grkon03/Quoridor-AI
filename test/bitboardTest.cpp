/**
 * @file bitboardTest.cpp
 * @author grkon03
 * @brief testcases for bitboard.hpp/.cpp
 *
 */

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

TEST(Bitboard96Operations, Bitboard96Additions)
{
    Bitboard96 a, b, cor;
    uint64_t n;

    // + Bitboard96, non-moveup

    a = "0xabcd000012340000ffff";
    b = "0x4f120000deeaff0000ff";
    cor = "0xfadf0000f11eff0100fe";

    EXPECT_EQ(a + b, cor);

    // + Bitboard96, moveup

    a = "0xff24ffacfdeeeddff";
    b = "0xcdc87019afcfbbd67";
    cor = "0x1cced6fc6adbea9b66";

    EXPECT_EQ(a + b, cor);

    // + Bitboard96, overflow errors, moveup

    a = Bitboard96(misc::fullbits32, misc::fullbits64);
    b = Bitboard96(1);
    a += b;

    EXPECT_EQ(a.IsOverflow(), true);

    // + Bitboard96, overflow errors, upperBits

    a = Bitboard96(misc::fullbits32, 0);
    b = Bitboard96(1, 0);
    a += b;

    EXPECT_EQ(a.IsOverflow(), true);

    // + uint64_t, non-moveup

    a = "0xf13fed3f13dddfffff";
    n = 0x123456789abcdefULL;
    cor = "0xf14110847b678bcdee";

    EXPECT_EQ(a + n, cor);

    // + uint64_t, moveup

    a = "0xfffffffffffffffffffff";
    n = 0xffffffffffffffffULL;
    cor = "0x100000fffffffffffffffe";

    EXPECT_EQ(a + n, cor);

    // + uint64_t, overflow errors
    a = "0xffffffffffffffffffffaaaa";
    n = 0xaaaaaaaa;
    a += n;

    EXPECT_EQ(a.IsOverflow(), true);
}

TEST(Bitboard96Operations, Bitboard96Substructions)
{
    Bitboard96 a, b, cor;
    uint64_t n;

    // - Bitboard96, non-movedown

    a = "0xf870fac7cb21bbcae7a73f";
    b = "0x12a8fba311c13d8ee176ac";
    cor = "0xe5c7ff24b9607e3c063093";

    EXPECT_EQ(a - b, cor);

    // - Bitboard96, movedown

    a = "0x10ffa3e0d982cbbc302";
    b = "0x100ff2eab3f27c727cc";
    cor = "0xefb0f625904f49b36";

    EXPECT_EQ(a - b, cor);

    // - Bitboard96, upperBits overflow

    a = "0xf1f2f2ff2f1f223331f";
    b = "0xe12ffdfefa8761f18ca";
    a -= b;

    EXPECT_EQ(a.IsOverflow(), true);

    // - Bitboard96, movedown overflow

    a = "0xffffffff11111111111";
    b = "0xffffffff11111111112";
    a -= b;

    EXPECT_EQ(a.IsOverflow(), true);

    // - uint64_t, non-movedown

    a = "0xf122ce81c766182ae";
    n = 0x118f8ba7ec971d4dULL;
    cor = "0xf009d5c7489ca6561";

    EXPECT_EQ(a - n, cor);

    // - uint64_t, movedown

    a = "0xf122ce81c766182ae";
    n = 0x318f8ba7ec971d4dULL;
    cor = "0xee09d5c7489ca6561";

    EXPECT_EQ(a - n, cor);

    // - uint64_t, non-movedown overflow

    a = "0xffffaaaa";
    n = 0xfffffaaaaa;
    a -= n;

    EXPECT_EQ(a.IsOverflow(), true);
}
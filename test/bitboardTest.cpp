/**
 * @file bitboardTest.cpp
 * @author grkon03
 * @brief testcases for bitboard.hpp/.cpp
 *
 */

#include <gtest/gtest.h>
#include "../src/includes/bitboard.hpp"
#include "../src/includes/misc.hpp"

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

    a = "0xa1f2f2ff2f1f223331f";
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

TEST(Bitboard96Operations, Bitboard96LeftShift)
{
    Bitboard96 a, cor;
    unsigned int n;

    // left-shift, no overflow

    a = "0b01111000010100111111001110001101101101101001010101011101011111111000101011101";
    n = 10;
    cor = "0b011110000101001111110011100011011011011010010101010111010111111110001010111010000000000";

    EXPECT_EQ(a << n, cor);

    // left-shift, overflow

    a = "0b011110101011111010101001001111010101001001101010101110000000010111010101101101111";
    n = 70;
    cor = "0b101110101011011011110000000000000000000000000000000000000000000000000000000000000000000000";

    EXPECT_EQ(a << n, cor);

    // left-shift, 0
    a = "0b010010011111001010010110000111111110000111101011100100100000000111111010100010111000";
    n = 100;
    cor = Bitboard96(0);

    EXPECT_EQ(a << n, 0);
}

TEST(Bitboard96Operations, Bitboard96RightShift)
{
    Bitboard96 a, cor;
    unsigned int n;

    // right-shift, n < 32

    a = "0b10010101101011111101011010010110000001110110000010010111101010100110110001111101001";
    n = 10;
    cor = "0b1001010110101111110101101001011000000111011000001001011110101010011011000";

    EXPECT_EQ(a >> n, cor);

    // right-shift, 32 <= n < 64

    a = "0b1100010010100100011001101011101000011010100100100011111100001001010101111000011010100010000";
    n = 40;
    cor = "0b110001001010010001100110101110100001101010010010001";

    EXPECT_EQ(a >> n, cor);

    // right-shift, 64 <= n < 96

    a = "0b1111100001010100001110100101010100100111101001001011101111110010011000011101000011";
    n = 80;
    cor = "0b11";

    EXPECT_EQ(a >> n, cor);

    // right-shift, 0

    a = "0b1101010000101001001111111101001001010010000010101010011111001011111110000010100100111";
    n = 100;
    cor = Bitboard96(0);

    EXPECT_EQ(a >> n, cor);
}

TEST(Bitboard96Operations, Bitboard96LogicalAnd)
{
    Bitboard96 a, b, cor;

    a = "0b1111011101110101010110010111110000101011001110101101001101111110001010110111011111";
    b = "0b0001111001011010111101001000000111011101011011011111000101101111001011101111011011";
    cor = "0b0001011001010000010100000000000000001001001010001101000101101110001010100111011011";

    EXPECT_EQ(a & b, cor);
}

TEST(Bitboard96Operations, Bitboard96LogicalOr)
{
    Bitboard96 a, b, cor;

    a = "0b1111011101110101010110010111110000101011001110101101001101111110001010110111011111";
    b = "0b0001111001011010111101001000000111011101011011011111000101101111001011101111011011";
    cor = "0b1111111101111111111111011111110111111111011111111111001101111111001011111111011111";

    EXPECT_EQ(a | b, cor);
}

TEST(Bitboard96Operations, Bitboard96LogicalXor)
{
    Bitboard96 a, b, cor;

    a = "0b1111011101110101010110010111110000101011001110101101001101111110001010110111011111";
    b = "0b0001111001011010111101001000000111011101011011011111000101101111001011101111011011";
    cor = "0b1110100100101111101011011111110111110110010101110010001000010001000001011000000100";

    EXPECT_EQ(a ^ b, cor);
}

TEST(Bitboard96Operations, Bitboard96LogicalNot)
{
    Bitboard96 a, cor;

    a = "0b000000000000001111011101110101010110010111110000101011001110101101001101111110001010110111011111";
    cor = "0b111111111111110000100010001010101001101000001111010100110001010010110010000001110101001000100000";

    EXPECT_EQ(~a, cor);
}
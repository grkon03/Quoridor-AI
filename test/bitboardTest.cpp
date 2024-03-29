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

TEST(Bitboard128Comparations, Bitboard128Comprations)
{
    Bitboard128 b, c;
    EXPECT_EQ(b, c);
}

TEST(Bitboard128Constructions, Bitboard128ConstructionsWithString)
{
    Bitboard128 a, b;

    a = Bitboard128(0xffff, 0xffffUL);

    b = Bitboard128("ffff000000000000ffff", misc::BaseType::BT_HEX);
    EXPECT_EQ(a, b);
    b = Bitboard128("ffff000000000000fffa", misc::BaseType::BT_HEX);
    EXPECT_NE(a, b);
    b = Bitboard128(
        std::string("111111111111111100000000000000000000000000000000") +
            std::string("00000000000000001111111111111111"),
        misc::BaseType::BT_BIN);
    EXPECT_EQ(a, b);
    b = Bitboard128("0xffff000000000000ffff");
    EXPECT_EQ(a, b);
    b = Bitboard128(
        std::string("0b111111111111111100000000000000000000000000000000") +
        std::string("00000000000000001111111111111111"));
    EXPECT_EQ(a, b);

    a = Bitboard128(0xeaff9f91U, 0xf10083eabc87d6deULL);

    b = Bitboard128("0xeaff9f91f10083eabc87d6de");
    EXPECT_EQ(a, b);
}

TEST(Bitboard128Operations, Bitboard128Additions)
{
    Bitboard128 a, b, cor;
    uint64_t n;

    // + Bitboard128, non-moveup

    a = "0xc8812dfdabcd000012340000ffff";
    b = "0xa09229cd4f120000deeaff0000ff";
    cor = "0x1691357cafadf0000f11eff0100fe";

    EXPECT_EQ(a + b, cor);

    // + Bitboard128, moveup

    a = "0xc12f1fda93eff24ffacfdeeeddff";
    b = "0x192fdc8a3ebcdc87019afcfbbd67";
    cor = "0xda5efc64d2acced6fc6adbea9b66";

    EXPECT_EQ(a + b, cor);

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
}

TEST(Bitboard128Operations, Bitboard128Substructions)
{
    Bitboard128 a, b, cor;
    uint64_t n;

    // - Bitboard128, non-movedown

    a = "0xc12f1fda93ef870fac7cb21bbcae7a73f";
    b = "0x192fdc8a3eb12a8fba311c13d8ee176ac";
    cor = "0xa7ff4350553e5c7ff24b9607e3c063093";

    EXPECT_EQ(a - b, cor);

    // - Bitboard128, movedown

    a = "0xcd1e8122bcbb10ffa3e0d982cbbc302";
    b = "0xcd1e8122bcbb100ff2eab3f27c727cc";
    cor = "0xefb0f625904f49b36";

    EXPECT_EQ(a - b, cor);

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
}

TEST(Bitboard128Operations, Bitboard128LeftShift)
{
    Bitboard128 a, cor;
    unsigned int n;

    // left-shift, no overflow

    a = "0b11001100100111101111000010100111111001110001101101101101001010101011101011111111000101011101";
    n = 10;
    cor = "0b110011001001111011110000101001111110011100011011011011010010101010111010111111110001010111010000000000";

    EXPECT_EQ(a << n, cor);

    // left-shift, overflow

    a = "0b011110101011111010101001001111010101001001101010101110000000010111010101101101111";
    n = 70;
    cor = "0b1001111010101001001101010101110000000010111010101101101111"
          "0000000000000000000000000000000000000000000000000000000000000000000000";

    EXPECT_EQ(a << n, cor);

    // left-shift, 0
    a = "0b111010010101101011010010011111001010010110000111111110000111101011100100100000000111111010100010111000";
    n = 130;
    cor = Bitboard128(0);

    EXPECT_EQ(a << n, 0);
}

TEST(Bitboard128Operations, Bitboard128RightShift)
{
    Bitboard128 a, cor;
    unsigned int n;

    // right-shift

    a = "0b1111000110111001101010010101101011111101011010010110000001110110000010010111101010100110110001111101001";
    n = 10;
    cor = "0b111100011011100110101001010110101111110101101001011000000111011000001001011110101010011011000";

    EXPECT_EQ(a >> n, cor);

    a = "0b1100010010100100011001101011101000011010100100100011111100001001010101111000011010100010000";
    n = 40;
    cor = "0b110001001010010001100110101110100001101010010010001";

    EXPECT_EQ(a >> n, cor);

    a = "0b111100001111101011101111100001010100001110100101010100100111101001001011101111110010011000011101000011";
    n = 80;
    cor = "0b1111000011111010111011";

    EXPECT_EQ(a >> n, cor);

    // right-shift, 0

    a = "0b100101111000111101010000101001001111111101001001010010000010101010011111001011111110000010100100111";
    n = 110;
    cor = Bitboard128(0);

    EXPECT_EQ(a >> n, cor);
}

TEST(Bitboard128Operations, Bitboard128LogicalAnd)
{
    Bitboard128 a, b, cor;

    a = "0b1111011101110101010110010111110000101011001110101101001101111110001010110111011111";
    b = "0b0001111001011010111101001000000111011101011011011111000101101111001011101111011011";
    cor = "0b0001011001010000010100000000000000001001001010001101000101101110001010100111011011";

    EXPECT_EQ(a & b, cor);
}

TEST(Bitboard128Operations, Bitboard128LogicalOr)
{
    Bitboard128 a, b, cor;

    a = "0b1111011101110101010110010111110000101011001110101101001101111110001010110111011111";
    b = "0b0001111001011010111101001000000111011101011011011111000101101111001011101111011011";
    cor = "0b1111111101111111111111011111110111111111011111111111001101111111001011111111011111";

    EXPECT_EQ(a | b, cor);
}

TEST(Bitboard128Operations, Bitboard128LogicalXor)
{
    Bitboard128 a, b, cor;

    a = "0b1111011101110101010110010111110000101011001110101101001101111110001010110111011111";
    b = "0b0001111001011010111101001000000111011101011011011111000101101111001011101111011011";
    cor = "0b1110100100101111101011011111110111110110010101110010001000010001000001011000000100";

    EXPECT_EQ(a ^ b, cor);
}

TEST(Bitboard128Operations, Bitboard128LogicalNot)
{
    Bitboard128 a, cor;

    a = "0b10110111110101011010010100010101"
        "000000000000001111011101110101010110010111110000101011001110101101001101111110001010110111011111";
    cor = "0b01001000001010100101101011101010"
          "111111111111110000100010001010101001101000001111010100110001010010110010000001110101001000100000";

    EXPECT_EQ(~a, cor);
}
#include <gtest/gtest.h>

#include "../src/includes/board.hpp"
#include "../src/includes/util/UtilAllIncludes.hpp"

using namespace QuoridorAI;
using namespace QuoridorAI::Util;

/*
    BoardInfo memo:

    //central

    WallMan wallMan;
    int kingSquareIndex[ColorLimit];
    unsigned char numberOfRemainingFence[ColorLimit]; // -1 expresses no square
    Color turnPlayer;                                 // player to do move in this turn
    int kingMovableSquaresIndex[ColorLimit][5];

    Bitboard128 availableFenceBB;
    Bitboard128 usedSquareEdgeBB;

    int turnSpent; // start with 0

    // hash

    Hasher::ZobristHash hash;

    // recorder

    std::vector<int> moveRecorder[ColorLimit];
    std::vector<int> kingRecorder[ColorLimit];
*/

TEST(BoardTest, BoardDoMoveTest)
{
    Board boardTested;
    BoardInfo biCor;
    std::vector<int> moves[ColorLimit], kingmoves[ColorLimit];

    // case 1

    boardTested = Board();

    moves[White] = std::vector<int>({13});

    moves[Black] = std::vector<int>({67});

    kingmoves[White] = std::vector<int>({4, 13});

    kingmoves[Black] = std::vector<int>({76, 67});

    biCor = BoardInfo{
        WallMan(moves),
        {13, 67},
        {10, 10},
        White,
        {{4, 12, 14, 22, -1}, {58, 66, 68, 76, -1}},
        Bitboard128(misc::fullbits64, misc::fullbits64),
        Bitboard128(0xffe018060ULL, 0x18060180601807ffULL),
        2,
        Hasher::ZobristHash(moves),
        {moves[White], moves[Black]},
        {kingmoves[White], kingmoves[Black]},
    };

    boardTested.DoMoveByGameRecord(moves);

    EXPECT_TRUE(biCor.IsSameAsByFullScan(boardTested.GetBoardInfo()));

    // case 2

    boardTested = Board();

    moves[White] = MakeIMoveSNs({
        "Ke1",
        "Ke2",
        "Ke3",
        "Ke4",
        "He5",
        "He4",
    });

    moves[Black] = MakeIMoveSNs({
        "Ke7",
        "Ke6",
        "He7",
        "Ve5",
        "Ve3",
    });

    kingmoves[White] = ExtractKingTracking(moves[White], 4);

    kingmoves[Black] = ExtractKingTracking(moves[Black], 76);

    biCor = BoardInfo{
        WallMan(moves),
        {40, 58},
        {8, 7},
        Black,
        {{41, -1, -1, -1, -1}, {59, 49, -1, -1, -1}},
        Bitboard128(0xffc7f7c7c7ffffffULL, 0xffe7c7c7c7f7ffffULL),
        Bitboard128(0xffe019c61ULL, 0x19c67184601807ffULL),
        11,
        Hasher::ZobristHash(moves),
        {moves[White], moves[Black]},
        {kingmoves[White], kingmoves[Black]},
    };

    boardTested.DoMoveByGameRecord(moves);

    EXPECT_TRUE(biCor.IsSameAsByFullScan(boardTested.GetBoardInfo()));
}

TEST(BoardTest, BoardDoMoveTestLongCase1)
{
    Board boardTested;
    BoardInfo biCor;
    std::vector<int> moves[ColorLimit], kingmoves[ColorLimit], exmoves[ColorLimit];

    // 1

    boardTested = Board();

    moves[White] = MakeIMoveSNs({
        "Ke1",
        "Ke2",
        "Ke3",
        "Ke4",
        "He3",
        "Ve2",
        "Vg2",
        "Hc4",
    });

    moves[Black] = MakeIMoveSNs({
        "Ke7",
        "Ke6",
        "Ke5",
        "Ke3",
        "He5",
        "Hc5",
        "Hg5",
        "Hh6",
    });

    kingmoves[White] = ExtractKingTracking(moves[White], 4);
    kingmoves[Black] = ExtractKingTracking(moves[Black], 76);

    biCor = BoardInfo{
        WallMan(moves),
        {40, 31},
        {6, 6},
        White,
        {{39, 41, 32, -1, -1}, {39, 41, 32, -1, -1}},
        Bitboard128(0xffff3f01e1c7ffffULL, 0xffff7fabd3c7d7ffULL),
        Bitboard128(0xffe018078ULL, 0x1ff65d9c651807ffULL),
        16,
        Hasher::ZobristHash(moves),
        {moves[White], moves[Black]},
        {kingmoves[White], kingmoves[Black]},
    };

    boardTested.DoMoveByGameRecord(moves);

    EXPECT_TRUE(biCor.IsSameAsByFullScan(boardTested.GetBoardInfo()));

    // 2

    // this is a game record followed by the previous one.

    exmoves[White] = MakeIMoveSNs({
        "Kf4",
        "Hg2",
        "Vi2",
    });

    exmoves[Black] = MakeIMoveSNs({
        "Vh3",
        "Ke4",
    });

    moves[White].insert(moves[White].end(), exmoves[White].begin(), exmoves[White].end());
    moves[Black].insert(moves[Black].end(), exmoves[Black].begin(), exmoves[Black].end());

    kingmoves[White] = ExtractKingTracking(moves[White], 4);
    kingmoves[Black] = ExtractKingTracking(moves[Black], 76);

    biCor = BoardInfo{
        WallMan(moves),
        {41, 40},
        {4, 5},
        Black,
        {{39, 42, 32, -1, -1}, {39, 42, 31, -1, -1}},
        Bitboard128(0xffff3f01b1471fffULL, 0xffff7fab130717ffULL),
        Bitboard128(0xffe018078ULL, 0x1ff7ddfc7d1807ffULL),
        21,
        Hasher::ZobristHash(moves),
        {moves[White], moves[Black]},
        {kingmoves[White], kingmoves[Black]},
    };

    boardTested.DoMoveByGameRecord(exmoves);

    EXPECT_TRUE(biCor.IsSameAsByFullScan(boardTested.GetBoardInfo()));

    // 3

    // this is a game record followed by the previous ones.

    exmoves[White] = MakeIMoveSNs({
        "Ve4",
    });

    exmoves[Black] = MakeIMoveSNs({
        "Ha5",
        "Kg4",
    });

    moves[White].insert(moves[White].end(), exmoves[White].begin(), exmoves[White].end());
    moves[Black].insert(moves[Black].end(), exmoves[Black].begin(), exmoves[Black].end());

    kingmoves[White] = ExtractKingTracking(moves[White], 4);
    kingmoves[Black] = ExtractKingTracking(moves[Black], 76);

    biCor = BoardInfo{
        WallMan(moves),
        {41, 42},
        {3, 4},
        White,
        {{40, 33, 32, -1, -1}, {40, 33, -1, -1, -1}},
        Bitboard128(0xffff3f0011071fffULL, 0xffff3702130717ffULL),
        Bitboard128(0xffe018079ULL, 0x1fffddfc7d1807ffULL),
        24,
        Hasher::ZobristHash(moves),
        {moves[White], moves[Black]},
        {kingmoves[White], kingmoves[Black]},
    };

    boardTested.DoMoveByGameRecord(exmoves);

    EXPECT_TRUE(biCor.IsSameAsByFullScan(boardTested.GetBoardInfo()));

    // 4

    // this is a game record followed by the previous ones.

    exmoves[White] = MakeIMoveSNs({
        "Hh1",
        "Kg3",
    });

    exmoves[Black] = MakeIMoveSNs({
        "Vg0",
    });

    moves[White].insert(moves[White].end(), exmoves[White].begin(), exmoves[White].end());
    moves[Black].insert(moves[Black].end(), exmoves[Black].begin(), exmoves[Black].end());

    kingmoves[White] = ExtractKingTracking(moves[White], 4);
    kingmoves[Black] = ExtractKingTracking(moves[Black], 76);

    biCor = BoardInfo{
        WallMan(moves),
        {33, 42},
        {2, 3},
        Black,
        {{24, 41, -1, -1, -1}, {24, 41, -1, -1, -1}},
        Bitboard128(0xffff3f0011071f1fULL, 0xffff37221307171fULL),
        Bitboard128(0xffe018079ULL, 0x1fffddfc7d1f07ffULL),
        27,
        Hasher::ZobristHash(moves),
        {moves[White], moves[Black]},
        {kingmoves[White], kingmoves[Black]},
    };

    boardTested.DoMoveByGameRecord(exmoves);

    EXPECT_TRUE(biCor.IsSameAsByFullScan(boardTested.GetBoardInfo()));

    // 5

    // this is a game record followed by the previous ones.

    exmoves[White] = std::vector<int>();

    exmoves[Black] = MakeIMoveSNs({
        "Kg2",
    });

    moves[Black].insert(moves[Black].end(), exmoves[Black].begin(), exmoves[Black].end());

    kingmoves[White] = ExtractKingTracking(moves[White], 4);
    kingmoves[Black] = ExtractKingTracking(moves[Black], 76);

    biCor = BoardInfo{
        WallMan(moves),
        {33, 24},
        {2, 3},
        White,
        {{25, 42, -1, -1, -1}, {25, 42, -1, -1, -1}},
        Bitboard128(0xffff3f0031071f1fULL, 0xffff37221307171fULL),
        Bitboard128(0xffe018079ULL, 0x1fffddfc7d1f07ffULL),
        28,
        Hasher::ZobristHash(moves),
        {moves[White], moves[Black]},
        {kingmoves[White], kingmoves[Black]},
    };

    boardTested.DoMoveByGameRecord(exmoves);

    EXPECT_TRUE(biCor.IsSameAsByFullScan(boardTested.GetBoardInfo()));

    // 6

    // this is a game record followed by the previous ones.

    exmoves[White] = MakeIMoveSNs({
        "Kh2",
    });

    exmoves[Black] = std::vector<int>();

    moves[White].insert(moves[White].end(), exmoves[White].begin(), exmoves[White].end());

    kingmoves[White] = ExtractKingTracking(moves[White], 4);
    kingmoves[Black] = ExtractKingTracking(moves[Black], 76);

    biCor = BoardInfo{
        WallMan(moves),
        {25, 24},
        {2, 3},
        Black,
        {{33, 34, -1, -1, -1}, {33, 34, -1, -1, -1}},
        Bitboard128(0xffff3f0031071f1fULL, 0xffff37221307171fULL),
        Bitboard128(0xffe018079ULL, 0x1fffddfc7d1f07ffULL),
        29,
        Hasher::ZobristHash(moves),
        {moves[White], moves[Black]},
        {kingmoves[White], kingmoves[Black]},
    };

    boardTested.DoMoveByGameRecord(exmoves);

    EXPECT_TRUE(biCor.IsSameAsByFullScan(boardTested.GetBoardInfo()));

    // 7

    // this is a game record followed by the previous ones.

    exmoves[White] = std::vector<int>();

    exmoves[Black] = MakeIMoveSNs({
        "Kh3",
    });

    moves[Black].insert(moves[Black].end(), exmoves[Black].begin(), exmoves[Black].end());

    kingmoves[White] = ExtractKingTracking(moves[White], 4);
    kingmoves[Black] = ExtractKingTracking(moves[Black], 76);

    biCor = BoardInfo{
        WallMan(moves),
        {25, 34},
        {2, 3},
        White,
        {{24, 43, -1, -1, -1}, {24, 43, -1, -1, -1}},
        Bitboard128(0xffff3f0031071f1fULL, 0xffff37221307171fULL),
        Bitboard128(0xffe018079ULL, 0x1fffddfc7d1f07ffULL),
        30,
        Hasher::ZobristHash(moves),
        {moves[White], moves[Black]},
        {kingmoves[White], kingmoves[Black]},
    };

    boardTested.DoMoveByGameRecord(exmoves);

    EXPECT_TRUE(biCor.IsSameAsByFullScan(boardTested.GetBoardInfo()));

    // 8

    // this is a game record followed by the previous ones.

    exmoves[White] = MakeIMoveSNs({
        "Kh4",
    });

    exmoves[Black] = std::vector<int>();

    moves[White].insert(moves[White].end(), exmoves[White].begin(), exmoves[White].end());

    kingmoves[White] = ExtractKingTracking(moves[White], 4);
    kingmoves[Black] = ExtractKingTracking(moves[Black], 76);

    biCor = BoardInfo{
        WallMan(moves),
        {43, 34},
        {2, 3},
        Black,
        {{25, 44, -1, -1, -1}, {25, 44, -1, -1, -1}},
        Bitboard128(0xffff3f0031471f1fULL, 0xffff37221307171fULL),
        Bitboard128(0xffe018079ULL, 0x1fffddfc7d1f07ffULL),
        31,
        Hasher::ZobristHash(moves),
        {moves[White], moves[Black]},
        {kingmoves[White], kingmoves[Black]},
    };

    boardTested.DoMoveByGameRecord(exmoves);

    EXPECT_TRUE(biCor.IsSameAsByFullScan(boardTested.GetBoardInfo()));

    // 9

    // this is a game record followed by the previous ones.

    exmoves[White] = std::vector<int>();

    exmoves[Black] = MakeIMoveSNs({
        "Ki4",
    });

    moves[Black].insert(moves[Black].end(), exmoves[Black].begin(), exmoves[Black].end());

    kingmoves[White] = ExtractKingTracking(moves[White], 4);
    kingmoves[Black] = ExtractKingTracking(moves[Black], 76);

    biCor = BoardInfo{
        WallMan(moves),
        {43, 44},
        {2, 3},
        White,
        {{34, 35, 53, -1, -1}, {34, 35, 53, -1, -1}},
        Bitboard128(0xffff3f0031471f1fULL, 0xffff37221307171fULL),
        Bitboard128(0xffe018079ULL, 0x1fffddfc7d1f07ffULL),
        32,
        Hasher::ZobristHash(moves),
        {moves[White], moves[Black]},
        {kingmoves[White], kingmoves[Black]},
    };

    boardTested.DoMoveByGameRecord(exmoves);

    EXPECT_TRUE(biCor.IsSameAsByFullScan(boardTested.GetBoardInfo()));

    // 10

    // this is a game record followed by the previous ones.

    exmoves[White] = MakeIMoveSNs({
        "Ki5",
        "Ve6",
        "Vh6",
    });

    exmoves[Black] = MakeIMoveSNs({
        "Hf6",
        "He7",
        "Hf8",
    });

    moves[White].insert(moves[White].end(), exmoves[White].begin(), exmoves[White].end());
    moves[Black].insert(moves[Black].end(), exmoves[Black].begin(), exmoves[Black].end());

    kingmoves[White] = ExtractKingTracking(moves[White], 4);
    kingmoves[Black] = ExtractKingTracking(moves[Black], 76);

    biCor = BoardInfo{
        WallMan(moves),
        {53, 44},
        {0, 0},
        White,
        {{52, 35, -1, -1, -1}, {52, 35, 43, -1, -1}},
        Bitboard128(0x8787070031471f1fULL, 0x878707021307171fULL),
        Bitboard128(0xffef1bc7fULL, 0x1fffddfc7d1f07ffULL),
        38,
        Hasher::ZobristHash(moves),
        {moves[White], moves[Black]},
        {kingmoves[White], kingmoves[Black]},
    };

    boardTested.DoMoveByGameRecord(exmoves);

    EXPECT_TRUE(biCor.IsSameAsByFullScan(boardTested.GetBoardInfo()));

    // 10

    // this is a game record followed by the previous ones.

    exmoves[White] = MakeIMoveSNs({
        "Kh5",
        "Kg5",
        "Kf5",
    });

    exmoves[Black] = MakeIMoveSNs({
        "Ki3",
        "Ki2",
        "Ki1",
    });

    moves[White].insert(moves[White].end(), exmoves[White].begin(), exmoves[White].end());
    moves[Black].insert(moves[Black].end(), exmoves[Black].begin(), exmoves[Black].end());

    kingmoves[White] = ExtractKingTracking(moves[White], 4);
    kingmoves[Black] = ExtractKingTracking(moves[Black], 76);

    biCor = BoardInfo{
        WallMan(moves),
        {50, 17},
        {0, 0},
        White,
        {{49, 51, -1, -1, -1}, {26, 16, -1, -1, -1}},
        Bitboard128(0x87870700b1471f1fULL, 0x878707a21307171fULL),
        Bitboard128(0xffef1bc7fULL, 0x1fffddfc7d1f07ffULL),
        44,
        Hasher::ZobristHash(moves),
        {moves[White], moves[Black]},
        {kingmoves[White], kingmoves[Black]},
    };

    boardTested.DoMoveByGameRecord(exmoves);

    EXPECT_TRUE(biCor.IsSameAsByFullScan(boardTested.GetBoardInfo()));
}

TEST(BoardTest, BoardUndoMoveTest)
{
    Board board;
    BoardInfo biCor;
    std::vector<int> moves[ColorLimit];

    moves[White] = MakeIMoveSNs({
        "Ke1",
        "Ke2",
        "Ke3",
        "Ke4",
        "He3",
        "Ve2",
        "Vg2",
        "Hc4",
    });

    moves[Black] = MakeIMoveSNs({
        "Ke7",
        "Ke6",
        "Ke5",
        "Ke3",
        "He5",
        "Hc5",
        "Hg5",
        "Hh6",
    });

    board.DoMoveByGameRecord(moves);
    biCor = board.GetBoardInfo();

    board.DoMove(MakeIMoveSN("Kf3"));

    board.UndoMove();

    EXPECT_TRUE(biCor.IsSameAsByFullScan(board.GetBoardInfo()));

    board.DoMove(MakeIMoveSN("Ve4"));

    board.UndoMove();

    EXPECT_TRUE(biCor.IsSameAsByFullScan(board.GetBoardInfo()));

    board.DoMove(MakeIMoveSN("Hf4"));

    board.UndoMove();

    EXPECT_TRUE(biCor.IsSameAsByFullScan(board.GetBoardInfo()));

    // another case

    board = Board();

    moves[White] = MakeIMoveSNs({
        "Ke1",
        "Ke2",
        "Ke3",
        "He3",
        "Vg3",
        "Hc3",
        "Hg5",
    });

    moves[Black] = MakeIMoveSNs({
        "Ke7",
        "Ke6",
        "Ke5",
        "He6",
        "Ve4",
        "Hg6",
        "Vh3",
    });

    board.DoMoveByGameRecord(moves);
    biCor = board.GetBoardInfo();

    board.DoMove(MakeIMoveSN("Ke4"));
    board.UndoMove();

    EXPECT_TRUE(biCor.IsSameAsByFullScan(board.GetBoardInfo()));

    board.DoMove(MakeIMoveSN("Vg5"));
    board.UndoMove();

    EXPECT_TRUE(biCor.IsSameAsByFullScan(board.GetBoardInfo()));
}
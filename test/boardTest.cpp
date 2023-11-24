#include <gtest/gtest.h>

#include "../src/includes/board.hpp"
#include "../src/includes/util/UtilAllIncludes.hpp"

using namespace QuoridorAI;

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
}
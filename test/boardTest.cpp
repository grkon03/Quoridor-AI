#include <gtest/gtest.h>

#include "../src/includes/board.hpp"

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
    BoardInfo biStart, biCor;
    WallMan wmStart, wmCor;

    biStart = BoardInfo{

    };
}
#pragma once

#include "wallman.hpp"
#include "hasher/HasherAllIncludes.hpp"

#include <vector>

namespace QuoridorAI
{
    struct BoardInfo
    {
        // central

        WallMan wallMan;
        int kingSquareIndex[ColorLimit];
        unsigned char numberOfRemainingFence[ColorLimit]; // -1 expresses no square
        Color turnPlayer;                                 // player to do move in this turn
        int kingMovableSquaresIndex[ColorLimit][5];

        int turnSpent; // start with 0

        // hash

        Hasher::ZobristHash hash;

        // recorder

        std::vector<int> moveRecorder[ColorLimit];
        std::vector<int> kingRecorder[ColorLimit];
    };

    class Board
    {
        // variables

        BoardInfo boardInfo;

    public:
        // constructors

        Board();
        /**
         * @note shallow copy
         *
         */
        Board(BoardInfo);
        /**
         * @note shallow copy
         *
         */
        Board(const Board &);

        // functions

        /**
         * @brief do move
         *
         * @param move the move
         *
         * @return whether succeed or not
         */
        bool DoMove(Move move);

        /**
         * @brief do move
         *
         * @param moveIndex index of the move
         *
         * @return whether succeed or not
         */
        bool DoMove(int moveIndex);

        /**
         * @brief do fence move
         *
         * @param fence the fence
         *
         * @return whether succeed or not
         */
        bool DoFenceMove(Fence fence);

        /**
         * @brief do fence move
         *
         * @param fenceIndex index of the fence
         *
         * @return whether succeed or not
         */
        bool DoFenceMove(int fenceIndex);

        /**
         * @brief do king move
         *
         * @param square square of the king destination
         *
         * @return whether succeed or not
         */
        bool DoKingMove(Square square);

        /**
         * @brief do king move
         *
         * @param squareIndex index of the square of the king destination
         *
         * @return whether succeed or not
         */
        bool DoKingMove(int squareIndex);

        /**
         * @brief undo move
         *
         * @return if there is no prevous move, return false
         *
         */
        bool UndoMove();

    private:
        /**
         * @brief calculate king movable squares
         *
         */
        void CalcKingMovableSquares();
    };
}
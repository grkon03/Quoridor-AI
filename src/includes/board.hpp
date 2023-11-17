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
        /**
         * @brief the n-th bit is set if n-th fence is available
         *
         * @note wallMan.availableFenceBB doesn't consider the king shutting up
         *
         */
        Bitboard128 availableFenceBB;
        /**
         * @brief the n-th bit is set if the n-th square edge is used by wall
         *
         */
        Bitboard128 usedSquareEdgeBB;

        int turnSpent; // start with 0

        // hash

        Hasher::ZobristHash hash;

        // recorder

        std::vector<int> moveRecorder[ColorLimit];
        std::vector<int> kingRecorder[ColorLimit];

        // functions for test

        bool IsSameAsByFullScan(const BoardInfo &) const;
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
         * @brief Get the BoardInfo object
         *
         * @return BoardInfo
         */
        BoardInfo GetBoardInfo() const;

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
         * @brief do move by using a game record
         *
         * @param moveRecords the move records (per a color)
         * @return whether succeed or not
         */
        bool DoMoveByGameRecord(std::vector<int> moveRecords[ColorLimit]);

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

        /**
         * @brief calculate king movable squares when both kings are adjacent to above each other
         *
         */
        void CalcKingMovableSquaresAdjacentUp();
        /**
         * @brief calculate king movable squares when both kings are adjacent to below each other
         *
         */
        void CalcKingMovableSquaresAdjacentDown();
        /**
         * @brief calculate king movable squares when both kings are adjacent to left each other
         *
         */
        void CalcKingMovableSquaresAdjacentLeft();
        /**
         * @brief calculate king movable squares when both kings are adjacent to right each other
         *
         */
        void CalcKingMovableSquaresAdjacentRight();
        /**
         * @brief calculate king movable squares when both kings are not adjacent each other
         *
         */
        void CalcKingMovableSquaresNoAdjacent();

        /**
         * @brief calc wall existing if kings are adjacent vertical
         *
         * @param lcsb left-center square edge of kings
         *
         *          ・-・
         *          ｜B｜
         * here ->  ・-・
         *          ｜W｜
         *          ・-・
         *
         */
        void WallExistingVertical(
            SquareEdge lcsb,
            bool *center, bool *top, bool *topleft, bool *topright, bool *bottom, bool *bottomleft, bool *bottomright);

        /**
         * @brief calc wall existing if kings are adjacent horiznotal
         *
         * @param cbse center-boottom square edge of kings
         *
         *  here
         * 　 |
         * 　 v
         * ・-・-・
         * ｜B｜W｜
         * ・-・-・
         */
        void WallExistingHorizontal(
            SquareEdge cbse,
            bool *center, bool *left, bool *topleft, bool *bottomleft, bool *right, bool *topright, bool *bottomright);

        /**
         * @brief update usedSquareEdgeBB after fence move
         *
         * @param fenceIndex index of the fence
         */
        void UpdateUsedSquareEdgeBB(int fenceIndex);

        /**
         * @brief calculate availableFenceBB
         *
         */
        void CalcAvailableFenceBB();
    };

    inline void Board::UpdateUsedSquareEdgeBB(int fenceIndex)
    {
        boardInfo.usedSquareEdgeBB |= Constant::usedSquareEdgeByFenceBB[fenceIndex];
    }
}
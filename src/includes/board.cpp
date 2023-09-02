#include "board.hpp"

namespace QuoridorAI
{
    Board::Board()
        : boardInfo{
              WallMan(),
              {4, 76},
              {10, 10},
              White,
              {{3, 5, 13, -1, -1}, {75, 77, 67, -1, -1}},
              {misc::fullbits64, misc::fullbits64},
              0,
              Hasher::ZobristHash(),
              {{}, {}},
              {{4}, {76}},
          }
    {
    }

    Board::Board(BoardInfo boardInfo) : boardInfo(boardInfo) {}

    Board::Board(const Board &board) : boardInfo(board.boardInfo) {}

    bool Board::DoMove(Move move)
    {
        return DoMove(Indexer::MoveToIndex(move));
    }

    bool Board::DoMove(int moveIndex)
    {
        if (moveIndex < NumberOfSquare)
            return DoKingMove(moveIndex);
        else if (moveIndex < NumberOfMove)
            return DoFenceMove(moveIndex - 81);
        else
            return false;
    }

    bool Board::DoFenceMove(Fence fence)
    {
        return DoFenceMove(Indexer::FenceToIndex(fence));
    }

    bool Board::DoFenceMove(int fenceIndex)
    {
        // verification and board updating process

        if (boardInfo.numberOfRemainingFence[boardInfo.turnPlayer] == 0)
            return false;

        Dijkstra _d = boardInfo.wallMan.GetDijkstra();
        _d.PutFence(fenceIndex);
        if (!(_d.IsThereReachableToGoal(boardInfo.kingSquareIndex[White], White) &&
              _d.IsThereReachableToGoal(boardInfo.kingSquareIndex[Black], Black)))
            return false;

        if ((boardInfo.availableFenceBB[fenceIndex >> 6] & misc::oneBitMask64[fenceIndex & 0b111111]) == 0)
            return false;

        boardInfo.wallMan.PutFence(fenceIndex);

        boardInfo.hash.GetNextKeyAfterFenceMove(fenceIndex);
        --boardInfo.numberOfRemainingFence[boardInfo.turnPlayer];
        CalcKingMovableSquares();
        CalcAvailableFenceBB();

        // record process

        boardInfo.moveRecorder[boardInfo.turnPlayer].push_back(fenceIndex + 81);

        // end process

        ++boardInfo.turnSpent;
        boardInfo.turnPlayer = !boardInfo.turnPlayer;

        return true;
    }

    bool Board::DoKingMove(Square square)
    {
        return DoKingMove(Indexer::SquareToIndex(square));
    }

    bool Board::DoKingMove(int squareIndex)
    {
        // verification and board updating process

        bool illegal = true;
        for (int i = 0; i < 5; ++i)
        {
            if (squareIndex == boardInfo.kingMovableSquaresIndex[boardInfo.turnPlayer][i])
            {
                illegal = false;
                break;
            }
        }

        if (illegal)
            return false;

        boardInfo.kingSquareIndex[boardInfo.turnPlayer] = squareIndex;

        boardInfo.hash.GetNextKeyAfterKingMove(squareIndex);
        CalcKingMovableSquares();
        CalcAvailableFenceBB();

        // record process

        boardInfo.moveRecorder[boardInfo.turnPlayer].push_back(squareIndex);
        boardInfo.kingRecorder[boardInfo.turnPlayer].push_back(squareIndex);

        // end process

        ++boardInfo.turnSpent;
        boardInfo.turnPlayer = !boardInfo.turnPlayer;

        return true;
    }

    void Board::CalcKingMovableSquares()
    {
        switch (boardInfo.kingSquareIndex[White] - boardInfo.kingSquareIndex[Black])
        {
        case 1:
            CalcKingMovableSquaresAdjacentLeft();
            break;
        case -1:
            CalcKingMovableSquaresAdjacentRight();
            break;
        case 9:
            CalcKingMovableSquaresAdjacentDown();
            break;
        case -9:
            CalcKingMovableSquaresAdjacentUp();
            break;
        default:
            CalcKingMovableSquaresNoAdjacent();
            break;
        }
    }

    void Board::CalcKingMovableSquaresAdjacentUp()
    {
        const int kingW = boardInfo.kingSquareIndex[White],
                  kingB = boardInfo.kingSquareIndex[Black];

        // left-center square edge of white king and black king
        SquareEdge lcse = ExtractSquareEdgeLower((Move)Indexer::indexer.IndexedSquare[kingB]);

        // wall existing
        bool center, top, topleft, topright, bottom, bottomleft, bottomright;

        WallExistingVertical(lcse, &center, &top, &topleft, &topright, &bottom, &bottomleft, &bottomright);

        int index = 0;

        // white

        // up
        if (!center)
        {
            if (top)
            {
                if (!topleft)
                    boardInfo.kingMovableSquaresIndex[White][index++] = kingW + 8;
                if (!topright)
                    boardInfo.kingMovableSquaresIndex[White][index++] = kingW + 10;
            }
            else
            {
                boardInfo.kingMovableSquaresIndex[White][index++] = kingW + 18;
            }
        }

        // down
        if (!bottom)
            boardInfo.kingMovableSquaresIndex[White][index++] = kingW - 9;

        // left
        if (!bottomleft)
            boardInfo.kingMovableSquaresIndex[White][index++] = kingW - 1;

        // down
        if (!bottomright)
            boardInfo.kingMovableSquaresIndex[White][index++] = kingW + 1;

        // fill -1 if the movable squares are not filled
        while (index < 5)
        {
            boardInfo.kingMovableSquaresIndex[White][index++] = -1;
        }

        // black

        index = 0;

        // up
        if (!center)
        {
            if (bottom)
            {
                if (!bottomleft)
                    boardInfo.kingMovableSquaresIndex[Black][index++] = kingB - 10;
                if (!bottomright)
                    boardInfo.kingMovableSquaresIndex[Black][index++] = kingB - 8;
            }
            else
            {
                boardInfo.kingMovableSquaresIndex[Black][index++] = kingB - 18;
            }
        }

        // down
        if (!top)
            boardInfo.kingMovableSquaresIndex[Black][index++] = kingB + 9;

        // left
        if (!topright)
            boardInfo.kingMovableSquaresIndex[Black][index++] = kingB + 1;

        // right
        if (!topleft)
            boardInfo.kingMovableSquaresIndex[Black][index++] = kingB - 1;

        // fill -1 if the movable squares are not filled
        while (index < 5)
        {
            boardInfo.kingMovableSquaresIndex[Black][index++] = -1;
        }
    }

    void Board::CalcKingMovableSquaresAdjacentDown()
    {
        const int kingW = boardInfo.kingSquareIndex[White],
                  kingB = boardInfo.kingSquareIndex[Black];

        // left-center square edge of white king and black king
        SquareEdge lcse = ExtractSquareEdgeLower((Move)Indexer::indexer.IndexedSquare[kingW]);

        // wall existing
        bool center, top, topleft, topright, bottom, bottomleft, bottomright;

        WallExistingVertical(lcse, &center, &top, &topleft, &topright, &bottom, &bottomleft, &bottomright);

        int index = 0;

        // white

        // up
        if (!top)
            boardInfo.kingMovableSquaresIndex[White][index++] = kingW + 9;

        // down
        if (!center)
        {
            if (bottom)
            {
                if (!bottomleft)
                    boardInfo.kingMovableSquaresIndex[White][index++] = kingW - 10;
                if (!bottomright)
                    boardInfo.kingMovableSquaresIndex[White][index++] = kingW - 8;
            }
            else
            {
                boardInfo.kingMovableSquaresIndex[White][index++] = kingW - 18;
            }
        }

        // left
        if (!topleft)
            boardInfo.kingMovableSquaresIndex[White][index++] = kingW - 1;

        // right
        if (!topright)
            boardInfo.kingMovableSquaresIndex[White][index++] = kingW + 1;

        // fill -1 if the movable squares are not filled
        while (index < 5)
        {
            boardInfo.kingMovableSquaresIndex[White][index++] = -1;
        }

        // black

        index = 0;

        // up
        if (!bottom)
            boardInfo.kingMovableSquaresIndex[Black][index++] = kingB - 9;

        // down
        if (!center)
        {
            if (top)
            {
                if (!topleft)
                    boardInfo.kingMovableSquaresIndex[Black][index++] = kingB + 10;
                if (!topright)
                    boardInfo.kingMovableSquaresIndex[Black][index++] = kingB + 8;
            }
            else
            {
                boardInfo.kingMovableSquaresIndex[Black][index++] = kingB + 18;
            }
        }

        // left
        if (!bottomright)
            boardInfo.kingMovableSquaresIndex[Black][index++] = kingB + 1;

        // right
        if (!bottomleft)
            boardInfo.kingMovableSquaresIndex[Black][index++] = kingB - 1;

        // fill -1 if the movable squares are not filled
        while (index < 5)
        {
            boardInfo.kingMovableSquaresIndex[Black][index++] = -1;
        }
    }

    void Board::CalcKingMovableSquaresAdjacentLeft()
    {
        const int kingW = boardInfo.kingSquareIndex[White],
                  kingB = boardInfo.kingSquareIndex[Black];

        SquareEdge cbse = ExtractSquareEdgeLower((Move)Indexer::indexer.IndexedSquare[kingW]);

        bool center, left, topleft, bottomleft, right, topright, bottomright;

        WallExistingHorizontal(cbse, &center, &left, &topleft, &bottomleft, &right, &topright, &bottomright);

        int index = 0;

        // white

        // up
        if (!topright)
            boardInfo.kingMovableSquaresIndex[White][index++] = kingW + 9;

        // down
        if (!bottomright)
            boardInfo.kingMovableSquaresIndex[White][index++] = kingW - 9;

        // left
        if (!center)
        {
            if (left)
            {
                if (!topleft)
                    boardInfo.kingMovableSquaresIndex[White][index++] = kingW + 8;
                if (!bottomleft)
                    boardInfo.kingMovableSquaresIndex[White][index++] = kingW - 10;
            }
            else
            {
                boardInfo.kingMovableSquaresIndex[White][index++] = kingW - 2;
            }
        }

        // right
        if (!right)
            boardInfo.kingMovableSquaresIndex[White][index++] = kingW + 1;

        // fill -1 if the movable squares are not filled
        while (index < 5)
        {
            boardInfo.kingMovableSquaresIndex[White][index++] = -1;
        }

        // black

        index = 0;

        // up
        if (!bottomleft)
            boardInfo.kingMovableSquaresIndex[Black][index++] = kingB - 9;

        // down
        if (!topleft)
            boardInfo.kingMovableSquaresIndex[Black][index++] = kingB + 9;

        // left
        if (!center)
        {
            if (right)
            {
                if (!topright)
                    boardInfo.kingMovableSquaresIndex[Black][index++] = kingB + 10;
                if (!bottomright)
                    boardInfo.kingMovableSquaresIndex[Black][index++] = kingB - 8;
            }
            else
            {
                boardInfo.kingMovableSquaresIndex[Black][index++] = kingB + 2;
            }
        }

        // right
        if (!left)
            boardInfo.kingMovableSquaresIndex[Black][index++] = kingB - 1;

        // fill -1 if the movable squares are not filled
        while (index < 5)
        {
            boardInfo.kingMovableSquaresIndex[Black][index++] = -1;
        }
    }

    void Board::CalcKingMovableSquaresAdjacentRight()
    {
        const int kingW = boardInfo.kingSquareIndex[White],
                  kingB = boardInfo.kingSquareIndex[Black];

        SquareEdge cbse = ExtractSquareEdgeLower((Move)Indexer::indexer.IndexedSquare[kingB]);

        bool center, left, topleft, bottomleft, right, topright, bottomright;

        WallExistingHorizontal(cbse, &center, &left, &topleft, &bottomleft, &right, &topright, &bottomright);

        int index = 0;

        // white

        // up
        if (!topleft)
            boardInfo.kingMovableSquaresIndex[White][index++] = kingW + 9;

        // down
        if (!bottomleft)
            boardInfo.kingMovableSquaresIndex[White][index++] = kingW - 9;

        // left
        if (!left)
            boardInfo.kingMovableSquaresIndex[White][index++] = kingW - 1;

        // right
        if (!center)
        {
            if (right)
            {
                if (!topright)
                    boardInfo.kingMovableSquaresIndex[White][index++] = kingW + 10;
                if (!bottomright)
                    boardInfo.kingMovableSquaresIndex[White][index++] = kingW - 8;
            }
            else
            {
                boardInfo.kingMovableSquaresIndex[White][index++] = kingW + 2;
            }
        }

        // fill -1 if the movable squares are not filled
        while (index < 5)
        {
            boardInfo.kingMovableSquaresIndex[White][index++] = -1;
        }

        // black

        index = 0;

        // up
        if (!bottomleft)
            boardInfo.kingMovableSquaresIndex[Black][index++] = kingB - 9;

        // down
        if (!topleft)
            boardInfo.kingMovableSquaresIndex[Black][index++] = kingB + 9;

        // left
        if (!right)
            boardInfo.kingMovableSquaresIndex[Black][index++] = kingB + 1;

        // right
        if (!center)
        {
            if (left)
            {
                if (!topleft)
                    boardInfo.kingMovableSquaresIndex[Black][index++] = kingB + 8;
                if (!bottomleft)
                    boardInfo.kingMovableSquaresIndex[Black][index++] = kingB - 10;
            }
            else
            {
                boardInfo.kingMovableSquaresIndex[Black][index++] = kingB - 2;
            }
        }

        // fill -1 if the movable squares are not filled
        while (index < 5)
        {
            boardInfo.kingMovableSquaresIndex[Black][index++] = -1;
        }
    }

    void Board::CalcKingMovableSquaresNoAdjacent()
    {
        const int kingW = boardInfo.kingSquareIndex[White],
                  kingB = boardInfo.kingSquareIndex[Black];

        SquareEdge wlbse = ExtractSquareEdgeLower((Move)Indexer::indexer.IndexedSquare[kingW]);
        SquareEdge blbse = ExtractSquareEdgeLower((Move)Indexer::indexer.IndexedSquare[kingB]);

        int index = 0;

        // white

        // up
        if (wlbse >= 80 ? false : !boardInfo.wallMan.IsThereWall<Horizontal>(SquareEdge(wlbse + 10)))
            boardInfo.kingMovableSquaresIndex[White][index++] = kingW + 9;

        // down
        if (wlbse < 10 ? false : !boardInfo.wallMan.IsThereWall<Horizontal>(wlbse))
            boardInfo.kingMovableSquaresIndex[White][index++] = kingW - 9;

        // left
        if (wlbse % 10 == 0 ? false : !boardInfo.wallMan.IsThereWall<Vertical>(wlbse))
            boardInfo.kingMovableSquaresIndex[White][index++] = kingW - 1;

        // right
        if (wlbse % 10 == 8 ? false : !boardInfo.wallMan.IsThereWall<Vertical>(SquareEdge(wlbse + 1)))
            boardInfo.kingMovableSquaresIndex[White][index++] = kingW + 1;

        // fill -1 if the movable squares are not filled
        while (index < 5)
        {
            boardInfo.kingMovableSquaresIndex[White][index++] = -1;
        }

        // black

        index = 0;

        // up
        if (blbse < 10 ? false : !boardInfo.wallMan.IsThereWall<Horizontal>(blbse))
            boardInfo.kingMovableSquaresIndex[Black][index++] = kingB - 9;

        // down
        if (blbse >= 80 ? false : !boardInfo.wallMan.IsThereWall<Horizontal>(SquareEdge(blbse + 10)))
            boardInfo.kingMovableSquaresIndex[Black][index++] = kingB + 9;

        // left
        if (blbse % 10 == 8 ? false : !boardInfo.wallMan.IsThereWall<Vertical>(SquareEdge(blbse + 1)))
            boardInfo.kingMovableSquaresIndex[Black][index++] = kingB + 1;

        // right
        if (blbse % 10 == 0 ? false : !boardInfo.wallMan.IsThereWall<Vertical>(blbse))
            boardInfo.kingMovableSquaresIndex[Black][index++] = kingB - 1;

        // fill -1 if the movable squares are not filled
        while (index < 5)
        {
            boardInfo.kingMovableSquaresIndex[Black][index++] = -1;
        }
    }

    void Board::WallExistingVertical(SquareEdge lcse, bool *center, bool *top, bool *topleft, bool *topright,
                                     bool *bottom, bool *bottomleft, bool *bottomright)
    {
        *center = boardInfo.wallMan.IsThereWall<Horizontal>(lcse);
        *top = (lcse >= 80) ? true
                            : boardInfo.wallMan.IsThereWall<Horizontal>(SquareEdge(lcse + 10));
        *bottom = (lcse < 10) ? true
                              : boardInfo.wallMan.IsThereWall<Horizontal>(SquareEdge(lcse - 10));
        if (lcse % 10 == 0)
        {
            *topleft = *bottomleft = true;
        }
        else
        {
            *topleft = boardInfo.wallMan.IsThereWall<Vertical>(lcse);
            *bottomleft = boardInfo.wallMan.IsThereWall<Vertical>(SquareEdge(lcse - 10));
        }

        if (lcse % 10 == 8)
        {
            *topright = *bottomright = true;
        }
        else
        {
            *topright = boardInfo.wallMan.IsThereWall<Vertical>(SquareEdge(lcse + 1));
            *bottomright = boardInfo.wallMan.IsThereWall<Vertical>(SquareEdge(lcse - 9));
        }
    }

    void Board::WallExistingHorizontal(SquareEdge cbse, bool *center, bool *left, bool *topleft, bool *bottomleft,
                                       bool *right, bool *topright, bool *bottomright)
    {
        *center = boardInfo.wallMan.IsThereWall<Vertical>(cbse);
        *left = (cbse % 10 == 1) ? true
                                 : boardInfo.wallMan.IsThereWall<Vertical>(SquareEdge(cbse - 1));
        *right = (cbse % 10 == 8) ? true
                                  : boardInfo.wallMan.IsThereWall<Vertical>(SquareEdge(cbse + 1));

        if (cbse >= 80)
        {
            *topleft = *topright = true;
        }
        else
        {
            *topleft = boardInfo.wallMan.IsThereWall<Horizontal>(SquareEdge(cbse + 9));
            *topright = boardInfo.wallMan.IsThereWall<Horizontal>(SquareEdge(cbse + 10));
        }

        if (cbse < 10)
        {
            *bottomleft = *bottomright = true;
        }
        else
        {
            *bottomleft = boardInfo.wallMan.IsThereWall<Horizontal>(SquareEdge(cbse - 1));
            *bottomright = boardInfo.wallMan.IsThereWall<Horizontal>(cbse);
        }
    }

    void Board::CalcAvailableFenceBB()
    {
    }
}
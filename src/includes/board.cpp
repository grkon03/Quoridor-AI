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
              Bitboard96(misc::fullbits32, misc::fullbits64),
              0,
              Hasher::ZobristHash(),
              {
                  std::vector<int>(),
                  std::vector<int>(),
              },
              {
                  std::vector<int>(4),
                  std::vector<int>(76),
              }}
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

        if (!boardInfo.wallMan.PutFence(fenceIndex))
            return false;

        boardInfo.hash.GetNextKeyAfterFenceMove(fenceIndex);
        --boardInfo.numberOfRemainingFence[boardInfo.turnPlayer];
        CalcKingMovableSquares();

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

        // record process

        boardInfo.moveRecorder[boardInfo.turnPlayer].push_back(squareIndex);
        boardInfo.kingRecorder[boardInfo.turnPlayer].push_back(squareIndex);

        // end process

        ++boardInfo.turnSpent;
        boardInfo.turnPlayer = !boardInfo.turnPlayer;

        return true;
    }
}
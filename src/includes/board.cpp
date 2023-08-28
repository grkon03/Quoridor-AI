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
              0,
              nullptr,
              -1} {}

    Board::Board(BoardInfo boardInfo) : boardInfo(boardInfo) {}

    Board::Board(const Board &board) : boardInfo(board.boardInfo) {}
}
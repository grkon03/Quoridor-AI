#include "types.hpp"

namespace QuoridorAI
{
    File GetFile(SquareEdge se)
    {
        return File(se % 10);
    }

    Rank GetRank(SquareEdge se)
    {
        return Rank(se / 10);
    }

    Square MakeSquare(SquareEdge se1, SquareEdge se2)
    {
        int df = GetFile(se1) - GetFile(se2);
        if (df != 1 && df != -1)
            return Square::SquareInvalid;
        switch (int(se1 - se2))
        {
        case 11:
            return Square(se2 + (se1 << 8));
        case 9:
            return Square((se2 - 1) + ((se1 + 1) << 8));
        case -11:
            return Square(se1 + (se2 << 8));
        case -9:
            return Square((se1 - 1) + ((se2 + 1) << 8));
        default:
            return Square::SquareInvalid;
        }
    }

    Fence MakeFence(SquareEdge se1, SquareEdge se2)
    {
        int df = GetFile(se1) - GetFile(se2);
        int dr = GetRank(se1) - GetFile(se2);
        if ((df > 2) || (df < -2) || (dr > 2) || (dr < -2))
            return Fence::FenceInvalid;
        switch (int(se1 - se2))
        {
        case 2:
        case 20:
            return Fence(se2 + (se1 << 8));
        case -2:
        case -20:
            return Fence(se1 + (se2 << 8));
        default:
            return Fence::FenceInvalid;
        }
    }

    Move MakeMove(SquareEdge se1, SquareEdge se2)
    {
        int df = GetFile(se1) - GetFile(se2);
        int dr = GetRank(se1) - GetFile(se2);
        if ((df > 2) || (df < -2) || (dr > 2) || (dr < -2))
            return Move::MoveInvalid;
        switch (int(se1 - se2))
        {
        case 2:
        case 20:
        case 11:
            return Move(se2 + se1 << 8);
        case 9:
            return Move(se2 - 1 + ((se1 + 1) << 8));
        case -2:
        case -20:
        case -11:
            return Move(se1 + (se2 << 8));
        case -9:
            return Move(se1 - 1 + ((se2 + 1) << 8));
        default:
            return Move::MoveInvalid;
        }
    }

    bool IsKingMove(Move move)
    {
        int p = (move >> 8) - (move & 0xff);
        return (p == 11);
    }

    bool IsFenceMove(Move move)
    {
        int p = (move >> 8) - (move & 0xff);
        return (p == 2 || p == 20);
    }

    Move CastToMove(Square square)
    {
        return Move(square);
    }

    Move CastToMove(Fence fence)
    {
        return Move(fence);
    }

    Square CastToSquare(Move move)
    {
        if (IsKingMove(move))
            return Square(move);
        else
            return Square::SquareInvalid;
    }

    Fence CastToFence(Move move)
    {
        if (IsFenceMove(move))
            return Fence(move);
        else
            return Fence::FenceInvalid;
    }
}
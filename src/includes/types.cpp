#include "types.hpp"

namespace QuoridorAI
{

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
        if ((df > 2) || (df < -2))
            return Fence::FenceInvalid;
        switch (int(se1 - se2))
        {
        case 2:
            if (Rank1 <= GetRank(se1) && GetRank(se1) <= Rank8)
                return Fence(se2 + (se1 << 8));
            else
                return FenceInvalid;
        case 20:
            if (FileB <= GetFile(se1) && GetFile(se1) <= FileI)
                return Fence(se2 + (se1 << 8));
            else
                return FenceInvalid;
        case -2:
            if (Rank1 <= GetRank(se1) && GetRank(se1) <= Rank8)
                return Fence(se1 + (se2 << 8));
            else
                return FenceInvalid;
        case -20:
            if (FileB <= GetFile(se1) && GetFile(se1) <= FileI)
                return Fence(se1 + (se2 << 8));
            else
                return FenceInvalid;
        default:
            return Fence::FenceInvalid;
        }
    }

    WallDir GetWallDir(Fence fence)
    {
        switch (int((fence >> 8) - fence & 0xff))
        {
        case 2:
            return WallDir::Horizontal;
        case 20:
            return WallDir::Vertical;
        default:
            return WallDir::WallDirLimit;
        }
    }

    Move MakeMove(SquareEdge se1, SquareEdge se2)
    {
        int df = GetFile(se1) - GetFile(se2);
        if ((df > 2) || (df < -2))
            return Move::MoveInvalid;
        switch (int(se1 - se2))
        {
        case 2:
        case 20:
        case 11:
            return Move(se2 + (se1 << 8));
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
}
#include "indexer.hpp"
#include "../types.hpp"

namespace QuoridorAI
{
    int Indexer::SquareToIndex(Square square)
    {
        SquareEdge se = ExtractSquareEdgeLower(Move(square));
        return GetRank(se) * 9 + GetFile(se);
    }

    int Indexer::FenceToIndex(Fence fence)
    {
        SquareEdge se = ExtractSquareEdgeLower(Move(fence));
        switch (GetWallDir(fence))
        {
        case Vertical:
            return GetRank(se) * 8 + GetFile(se) - 1;
        case Horizontal:
            return (GetRank(se) - 1) * 8 + GetFile(se) + 64;
        default:
            return -1;
        }
    }

    int Indexer::MoveToIndex(Move move)
    {
        if (IsKingMove(move))
            return SquareToIndex(Square(move));
        else if (IsFenceMove(move))
            return FenceToIndex(Fence(move));
        else
            return -1;
    }

    void Indexer::Initialize()
    {
        int i = 0;
        int index = 0;
        Square s;
        Fence f;

        // square

        while (index < 81)
        {
            s = MakeSquare(SE_A0 + i, SE_A0 + i + 11);

            if (s != SquareInvalid)
            {
                IndexedSquare[index] = s;
                ++index;
            }
            ++i;
        }

        index = 0;
        i = 0;

        // fence

        // vartical

        while (index < 64)
        {
            f = MakeFence(SE_A0 + i, SE_A0 + i + 20);

            if (f != FenceInvalid)
            {
                IndexedFence[index] = f;
                ++index;
            }

            ++i;
        }

        i = 0;

        // horizontal

        while (index < 128)
        {
            f = MakeFence(SE_A0 + i, SE_A0 + i + 2);

            if (f != FenceInvalid)
            {
                IndexedFence[index] = f;
                ++index;
            }

            ++i;
        }

        // move

        for (i = 0; i < 81; ++i)
        {
            IndexedMove[i] = Move(IndexedSquare[i]);
        }

        for (i = 0; i < 128; ++i)
        {
            IndexedMove[i + 81] = Move(IndexedFence[i]);
        }
    }

    Indexer::Indexer()
    {
        Initialize();
    }

    const Indexer Indexer::indexer = Indexer();
}
#include "indexer.hpp"
#include "../types.hpp"

namespace QuoridorAI
{
    int Indexer::SquareToIndex(Square square)
    {
        SquareEdge se = ExtractSquareEdgeLower(Move(square));
        return GetRank(se) * 9 + GetFile(se);
    }

    void Indexer::Initialize()
    {
        int i = 0;
        int index = 0;
        Square s;

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
    }

    Indexer::Indexer()
    {
        Initialize();
    }

    const Indexer Indexer::indexer = Indexer();
}
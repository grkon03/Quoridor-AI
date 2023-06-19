#include "indexer.hpp"
#include "../types.hpp"

namespace QuoridorAI
{
    namespace Indexer
    {
        int SquareToIndex(Square square)
        {
            SquareEdge se = ExtractSquareEdgeLower(Move(square));
            return GetRank(se) * 9 + GetFile(se);
        }
    }
}
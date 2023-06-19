#include "indexer.hpp"
#include "../types.hpp"

namespace QuoridorAI
{
    namespace Indexer
    {
        int SquareToIndex(Square square)
        {
            return ExtractSquareEdgeLower(Move(square));
        }
    }
}
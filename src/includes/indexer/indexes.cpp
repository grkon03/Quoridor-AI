#include "indexes.hpp"

namespace QuoridorAI
{
    namespace Indexer
    {
        void Initialize()
        {
            int i;

            for (i = 0; i < 81; ++i)
            {
                IndexedSquare[i] = MakeSquare(SE_A0 + i, SE_A0 + i + 11);
            }
        }

        Square IndexedSquare[81];
        Fence IndexedFence[128];
        Move IndexedMove[209];
    }
}
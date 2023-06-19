#include "indexes.hpp"
#include <iostream>

namespace QuoridorAI
{
    namespace Indexer
    {
        void Initialize()
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

        Square IndexedSquare[81];
        Fence IndexedFence[128];
        Move IndexedMove[209];
    }
}
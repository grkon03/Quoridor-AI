#include "keys.hpp"

namespace QuoridorAI
{
    namespace Hasher
    {
        ZobristKey::ZobristKey(Randomizer &r)
        {
            int i;
            for (i = 0; i < 64; ++i)
            {
                SquareKey[White][i] = r.next();
                SquareKey[Black][i] = r.next();
            }
            for (i = 0; i < 128; ++i)
            {
                FenceKey[i] = r.next();
            }
        }
    }
}
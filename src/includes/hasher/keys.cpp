#include "keys.hpp"
#include <iostream>

namespace QuoridorAI
{
    namespace Hasher
    {
        ZobristKey::ZobristKey(Randomizer &r)
        {
            int i;
            for (i = 0; i < 81; ++i)
            {
                SquareKey[White][i] = r.next();
                SquareKey[Black][i] = r.next();
            }
            for (i = 0; i < 128; ++i)
            {
                FenceKey[i] = r.next();
            }
        }

        ZobristKey::ZobristKey(const ZobristKey &key)
        {
            int i;

            for (i = 0; i < NumberOfSquare; ++i)
            {
                SquareKey[White][i] = key.SquareKey[White][i];
                SquareKey[Black][i] = key.SquareKey[Black][i];
            }
            for (i = 0; i < NumberOfFence; ++i)
            {
                FenceKey[i] = key.FenceKey[i];
            }
        }

        namespace
        {
            MTRandomizer __mt(2906);
        }

        const ZobristKey ZobristKey::general = ZobristKey(__mt);
    }
}
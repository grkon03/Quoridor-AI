#pragma once

#include "../types.hpp"
#include "random.hpp"
#include "mt.hpp"

namespace QuoridorAI
{
    namespace Hasher
    {
        /**
         * @brief HashKeys used in Zobrist Hashing
         *
         */
        struct ZobristKey
        {
            HashKey SquareKey[ColorLimit][81];
            HashKey FenceKey[128];

            ZobristKey(Randomizer &r);
        };
    }
}
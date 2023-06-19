#pragma once

#include "../types.hpp"

namespace QuoridorAI
{
    namespace Indexer
    {
        /// @brief Initialize Indexed(Square/Fence/Move)
        void Initialize();

        extern Square IndexedSquare[81];
        extern Fence IndexedFence[128];
        extern Move IndexedMove[209];
    }
}
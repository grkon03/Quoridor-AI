#pragma once

#include "../types.hpp"

namespace QuoridorAI
{
    /**
     * @brief indexing Square and Fence, also Move
     *
     * @note Indexing Rules: (https://hackmd.io/3Ro1CFVLSeSJtVc-KsqLow#Indexing-Rules).
     *
     */
    namespace Indexer
    {
        /// @brief  Indexer of Square
        int SquareToIndex(Square);
        /// @brief  Indexer of Fence
        int FenceToIndex(Fence);
        /// @brief  Indexer of Move
        int MoveToIndex(Move);
    }
}
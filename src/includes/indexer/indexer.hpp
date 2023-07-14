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
    class Indexer
    {
    public:
        // variables

        Square IndexedSquare[81];
        Fence IndexedFence[128];
        Move IndexedMove[209];

    public:
        // constructors

        Indexer();

        // functions

        /// @brief Initialize Indexed(Square/Fence/Move)
        void Initialize();

        // static functions

        /// @brief  Indexer of Square
        static int SquareToIndex(Square);
        /// @brief  Indexer of Fence
        static int FenceToIndex(Fence);
        /// @brief  Indexer of Move
        static int MoveToIndex(Move);

        // static variables

        static const Indexer indexer;
    };
}
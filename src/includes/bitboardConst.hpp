#pragma once

#include <unordered_map>

#include "bitboard.hpp"
#include "types.hpp"

namespace QuoridorAI
{
    /**
     * @namespace Constant
     * @brief constances' space of QuoridorAI
     *
     */
    namespace Constant
    {
        template <typename T, typename U>
        using Map = std::unordered_map<T, U>;

        extern const Bitboard128 oneBitMask128[128];
        extern const Bitboard128 fenceMaskByIndex[NumberOfFence];
        extern const Map<Fence, Bitboard128> fenceMaskByFence;
        extern const Map<SquareEdge, Bitboard128> fenceMaskBySquareEdge[WallDirLimit];

        extern const Bitboard64 availableFenceRemainMaskByIndex[NumberOfFence];
        extern const Map<SquareEdge, Bitboard64> availableFenceRemainMaskBySquareEdge[WallDirLimit];
    }
}
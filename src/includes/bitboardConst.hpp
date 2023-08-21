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

        extern const Bitboard96 oneBitMask96[96];
        extern const Bitboard96 fenceMaskByIndex[NumberOfFence];
        extern const Map<Fence, Bitboard96> fenceMaskByFence;
        extern const Map<SquareEdge, Bitboard96> fenceMaskBySquareEdge[WallDirLimit];
    }
}
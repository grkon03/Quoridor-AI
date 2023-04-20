#pragma once

#include "bitboard.hpp"

namespace QuoridorAI
{
    /**
     *
     * Bitboard96
     *
     */

    // constructors

    Bitboard96::Bitboard96() : lowerBits(0), upperBits(0){};
    Bitboard96::Bitboard96(uint64_t n) : lowerBits(n), upperBits(0){};
    Bitboard96::Bitboard96(uint64_t low, uint32_t upp)
        : lowerBits(low), upperBits(upp){};
    Bitboard96::Bitboard96(std::string number, misc::BaseType bt)
    {
        int digit = 0;
        int length;

        switch (bt)
        {
        case misc::BaseType::BT_BIN:
            for (digit = 0; digit < 96; ++digit)
            {
                if (digit < 64)
                {
                }
            }
        case misc::BaseType::BT_DEC:
        case misc::BaseType::BT_HEX:
        default:
            return;
        }
    }
}
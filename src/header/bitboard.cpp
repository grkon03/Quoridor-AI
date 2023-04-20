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
        int i;
        int length;
        int digit;

        // initialize
        upperBits = 0;
        lowerBits = 0;

        switch (bt)
        {
        case misc::BaseType::BT_BIN:
            length = number.length();

            // over
            if (length > 96)
                return;

            for (i = length - 1; i >= 0; --i)
            {
                switch (number[length - i - 1])
                {
                case '0':
                    break;
                case '1':
                    if (i < 64)
                    {
                        lowerBits += 1ULL << i;
                    }
                    else
                    {
                        upperBits += 1ULL << (i - 64);
                    }
                    break;
                default:
                    lowerBits = 0;
                    upperBits = 0;
                    return;
                }
            }

            break;
        case misc::BaseType::BT_DEC:
            break;
        case misc::BaseType::BT_HEX:
            break;
        default:
            return;
        }
    }
}
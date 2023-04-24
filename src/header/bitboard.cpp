#pragma once

#include "bitboard.hpp"

namespace QuoridorAI
{
    /**
     *
     * misc
     *
     */

    namespace misc
    {
        uint64_t fullbits64 = 0xffffffffffffffffULL;
        uint32_t fullbits32 = 0xffffffffUL;
    }

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
        char cDigit;

        // initialize
        upperBits = 0;
        lowerBits = 0;

        length = number.length();

        switch (bt)
        {
        case misc::BaseType::BT_BIN:

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
        case misc::BaseType::BT_HEX:
            if (length > 24)
                return;

            for (i = length - 1; i >= 0; --i)
            {
                cDigit = number[length - i - 1];
                if ('0' <= cDigit && cDigit <= '9')
                {
                    digit = int(cDigit - '0');
                }
                else if ('a' <= cDigit && cDigit <= 'f')
                {
                    digit = int(cDigit - 'a') + 10;
                }
                else if ('A' <= cDigit && cDigit <= 'F')
                {
                    digit = int(cDigit - 'A') + 10;
                }
                else
                {
                    lowerBits = 0;
                    upperBits = 0;
                    return;
                }

                if (i < 16)
                {
                    lowerBits += digit * (1ULL << (i * 4));
                }
                else
                {
                    upperBits += digit * (1ULL << (i * 4));
                }
            }

            break;
        default:
            return;
        }
    }
}
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

    Bitboard96::Bitboard96()
        : lowerBits(0), upperBits(0), overflow(false), invalidExpression(false){};
    Bitboard96::Bitboard96(uint64_t n)
        : lowerBits(n), upperBits(0), overflow(false), invalidExpression(false){};
    Bitboard96::Bitboard96(uint32_t upp, uint64_t low)
        : lowerBits(low), upperBits(upp), overflow(false), invalidExpression(false){};
    Bitboard96::Bitboard96(std::string number, misc::BaseType bt)
    {
        overflow = false;
        invalidExpression = false;

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
            {
                overflow = true;
                return;
            }

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
                    invalidExpression = true;
                    return;
                }
            }

            break;
        case misc::BaseType::BT_HEX:
            if (length > 24)
            {
                overflow = true;
                return;
            }

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
                    invalidExpression = true;
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
            invalidExpression = true;
            return;
        }
    }

    Bitboard96::Bitboard96(std::string exp)
    {
        if (exp.substr(0, 2) == "0x")
            *this = Bitboard96(exp.substr(2), misc::BaseType::BT_HEX);
        else if (exp.substr(0, 2) == "0b")
            *this = Bitboard96(exp.substr(2), misc::BaseType::BT_BIN);
        else
        {
            lowerBits = 0;
            upperBits = 0;
            overflow = false;
            invalidExpression = true;
        }
    }

    // operators

    Bitboard96 Bitboard96::operator=(const Bitboard96 &b)
    {
        upperBits = b.upperBits;
        lowerBits = b.lowerBits;
        overflow = b.overflow;
        invalidExpression = b.invalidExpression;

        return *this;
    }

    Bitboard96 Bitboard96::operator=(const std::string number)
    {
        return (*this = Bitboard96(number));
    }

    bool Bitboard96::operator==(const Bitboard96 &b) const
    {
        if (overflow || invalidExpression || b.overflow || b.invalidExpression)
            return false;

        return ((upperBits == b.upperBits) && (lowerBits == b.lowerBits));
    }

    bool Bitboard96::operator!=(const Bitboard96 &b) const
    {
        return !operator==(b);
    }

    // functions

    bool Bitboard96::IsOverflow() { return overflow; }
    bool Bitboard96::IsInvalidExpression() { return invalidExpression; }
}
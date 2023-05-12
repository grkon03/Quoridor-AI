#include "bitboard.hpp"
#include "misc.hpp"

namespace QuoridorAI
{
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

    Bitboard96 &Bitboard96::operator+=(const Bitboard96 &b)
    {
        if (IsError() | b.IsError())
        {
            InheritError(b);
            return *this;
        }

        if (misc::fullbits64 - b.lowerBits < lowerBits)
        {
            if (misc::fullbits32 == upperBits)
            {
                overflow = true;
                return *this;
            }

            lowerBits -= misc::fullbits64 - b.lowerBits + 1;
            ++upperBits;
        }
        else
        {
            lowerBits += b.lowerBits;
        }

        if (misc::fullbits32 - b.upperBits < upperBits)
        {
            overflow = true;
            return *this;
        }

        upperBits += b.upperBits;

        return *this;
    }

    Bitboard96 Bitboard96::operator+(const Bitboard96 &b) const
    {
        Bitboard96 res = *this;
        return (res += b);
    }

    Bitboard96 &Bitboard96::operator+=(const uint64_t n)
    {
        if (IsError())
            return *this;

        if (misc::fullbits64 - n < lowerBits)
        {
            if (misc::fullbits32 == upperBits)
            {
                overflow = true;
                return *this;
            }

            lowerBits -= misc::fullbits64 - n + 1;
            ++upperBits;
        }
        else
        {
            lowerBits += n;
        }

        return *this;
    }

    Bitboard96 Bitboard96::operator+(const uint64_t n) const
    {
        Bitboard96 res = *this;
        return (res += n);
    }

    Bitboard96 &Bitboard96::operator-=(const Bitboard96 &b)
    {
        if (IsError() || b.IsError())
        {
            InheritError(b);
            return *this;
        }

        if (upperBits < b.upperBits)
        {
            overflow = true;
            return *this;
        }

        if (lowerBits < b.lowerBits)
        {
            if (upperBits == b.upperBits)
            {
                overflow = true;
                return *this;
            }

            upperBits -= b.upperBits + 1;
            lowerBits += misc::fullbits64 - b.lowerBits + 1;
        }
        else
        {
            upperBits -= b.upperBits;
            lowerBits -= b.lowerBits;
        }

        return *this;
    }

    Bitboard96 Bitboard96::operator-(const Bitboard96 &b) const
    {
        Bitboard96 res = *this;
        return (res -= b);
    }

    Bitboard96 &Bitboard96::operator-=(const uint64_t n)
    {
        if (IsError())
            return *this;

        if (lowerBits < n)
        {
            if (upperBits == 0)
            {
                overflow = true;
                return *this;
            }

            --upperBits;
            lowerBits += misc::fullbits64 - n + 1;
        }
        else
        {
            lowerBits -= n;
        }

        return *this;
    }

    Bitboard96 Bitboard96::operator-(const uint64_t n) const
    {
        Bitboard96 res = *this;
        return (res -= n);
    }

    Bitboard96 &Bitboard96::operator<<=(const unsigned int n)
    {
        uint32_t moveup;

        if (n < 64)
        {
            moveup = static_cast<uint32_t>(((lowerBits & misc::higherBitsFullMask64[n]) >> n) & misc::fullbits32);
            lowerBits <<= n;
            upperBits <<= n;
            upperBits += moveup;
        }
        else if (n < 96)
        {
            lowerBits = 0;
            upperBits = static_cast<uint32_t>(lowerBits & misc::fullbits32) << (n - 64);
        }
        else
        {
            lowerBits = 0;
            upperBits = 0;
        }

        return *this;
    }

    Bitboard96 Bitboard96::operator<<(const unsigned int n) const
    {
        Bitboard96 res = *this;
        return (res <<= n);
    }

    Bitboard96 &Bitboard96::operator>>=(const unsigned int n)
    {
        uint64_t movedown;

        if (n >= 96)
        {
            upperBits = 0;
            lowerBits = 0;
        }

        if (n < 32)
        {
            movedown = (upperBits & misc::lowerBitsFullMask32[n]) << (32 - n);
        }
        else if (n < 64)
        {
            movedown = upperBits << (32 - n);
        }
        else
        {
            movedown = upperBits >> (n - 64);
        }

        upperBits >>= n;
        lowerBits >>= n;
        lowerBits += movedown;

        return *this;
    }

    Bitboard96 Bitboard96::operator>>(const unsigned int n) const
    {
        Bitboard96 res = *this;
        return (res >>= n);
    }

    Bitboard96 &Bitboard96::operator&=(const Bitboard96 &b)
    {
        upperBits &= b.upperBits;
        lowerBits &= b.lowerBits;
        return *this;
    }

    Bitboard96 Bitboard96::operator&(const Bitboard96 &b) const
    {
        Bitboard96 res = *this;
        return (res &= b);
    }

    Bitboard96 &Bitboard96::operator|=(const Bitboard96 &b)
    {
        upperBits |= b.upperBits;
        lowerBits |= b.lowerBits;
        return *this;
    }

    Bitboard96 Bitboard96::operator|(const Bitboard96 &b) const
    {
        Bitboard96 res = *this;
        return (res |= b);
    }

    Bitboard96 &Bitboard96::operator^=(const Bitboard96 &b)
    {
        upperBits ^= b.upperBits;
        lowerBits ^= b.lowerBits;
        return *this;
    }

    Bitboard96 Bitboard96::operator^(const Bitboard96 &b) const
    {
        Bitboard96 res = *this;
        return (res ^= b);
    }

    Bitboard96 Bitboard96::operator~() const
    {
        return Bitboard96(~upperBits, ~lowerBits);
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

    bool Bitboard96::IsError() const
    {
        return (
            overflow |
            invalidExpression);
    }

    bool Bitboard96::IsOverflow() const { return overflow; }
    bool Bitboard96::IsInvalidExpression() const { return invalidExpression; }

    void Bitboard96::InheritError(const Bitboard96 &b)
    {
        overflow |= b.overflow;
        invalidExpression |= b.invalidExpression;
    }
}
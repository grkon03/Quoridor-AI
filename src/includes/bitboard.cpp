#include "bitboard.hpp"
#include "misc.hpp"

namespace QuoridorAI
{
    /**
     *
     * Bitboard128
     *
     */

    // constructors

    Bitboard128::Bitboard128()
        : lowerBits(0), upperBits(0) {}
    Bitboard128::Bitboard128(Bitboard64 n)
        : lowerBits(n), upperBits(0) {}
    Bitboard128::Bitboard128(Bitboard64 upp, Bitboard64 low)
        : lowerBits(low), upperBits(upp) {}

    Bitboard128::Bitboard128(std::string number, misc::BaseType bt)
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

            if (length >= 128)
                length = 128;

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

            if (length >= 32)
                length = 32;

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

    Bitboard128::Bitboard128(std::string exp)
    {
        if (exp.substr(0, 2) == "0x")
            *this = Bitboard128(exp.substr(2), misc::BaseType::BT_HEX);
        else if (exp.substr(0, 2) == "0b")
            *this = Bitboard128(exp.substr(2), misc::BaseType::BT_BIN);
        else
        {
            lowerBits = 0;
            upperBits = 0;
        }
    }

    // operators

    Bitboard128 Bitboard128::operator=(const Bitboard128 &b)
    {
        upperBits = b.upperBits;
        lowerBits = b.lowerBits;

        return *this;
    }

    Bitboard128 Bitboard128::operator=(const std::string number)
    {
        return (*this = Bitboard128(number));
    }

    Bitboard128 &Bitboard128::operator+=(const Bitboard128 &b)
    {
        if (misc::fullbits64 - b.lowerBits < lowerBits)
        {
            lowerBits -= misc::fullbits64 - b.lowerBits + 1;
            ++upperBits;
        }
        else
        {
            lowerBits += b.lowerBits;
        }

        upperBits += b.upperBits;

        return *this;
    }

    Bitboard128 Bitboard128::operator+(const Bitboard128 &b) const
    {
        Bitboard128 res = *this;
        return (res += b);
    }

    Bitboard128 &Bitboard128::operator+=(const Bitboard64 n)
    {
        if (misc::fullbits64 - n < lowerBits)
        {
            lowerBits -= misc::fullbits64 - n + 1;
            ++upperBits;
        }
        else
        {
            lowerBits += n;
        }

        return *this;
    }

    Bitboard128 Bitboard128::operator+(const Bitboard64 n) const
    {
        Bitboard128 res = *this;
        return (res += n);
    }

    Bitboard128 &Bitboard128::operator-=(const Bitboard128 &b)
    {
        if (lowerBits < b.lowerBits)
        {
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

    Bitboard128 Bitboard128::operator-(const Bitboard128 &b) const
    {
        Bitboard128 res = *this;
        return (res -= b);
    }

    Bitboard128 &Bitboard128::operator-=(const Bitboard64 n)
    {
        if (lowerBits < n)
        {
            --upperBits;
            lowerBits += misc::fullbits64 - n + 1;
        }
        else
        {
            lowerBits -= n;
        }

        return *this;
    }

    Bitboard128 Bitboard128::operator-(const Bitboard64 n) const
    {
        Bitboard128 res = *this;
        return (res -= n);
    }

    Bitboard128 &Bitboard128::operator<<=(const unsigned int n)
    {
        Bitboard64 moveup;

        if (n < 64)
        {
            moveup = (lowerBits & misc::upperBitsFullMask64[n]) >> (64 - n);
            lowerBits <<= n;
            upperBits <<= n;
            upperBits += moveup;
        }
        else if (n < 128)
        {
            upperBits = lowerBits << (n - 64);
            lowerBits = 0;
        }
        else
        {
            lowerBits = 0;
            upperBits = 0;
        }

        return *this;
    }

    Bitboard128 Bitboard128::operator<<(const unsigned int n) const
    {
        Bitboard128 res = *this;
        return (res <<= n);
    }

    Bitboard128 &Bitboard128::operator>>=(const unsigned int n)
    {
        Bitboard64 movedown;

        if (n >= 128)
        {
            upperBits = 0;
            lowerBits = 0;
        }
        else if (n < 64)
        {
            movedown = upperBits << (64 - n);
            if (n < 64)
            {
                upperBits >>= n;
            }
            else
            {
                upperBits = 0;
            }
            lowerBits >>= n;
            lowerBits += movedown;
        }
        else
        {
            movedown = upperBits >> (n - 64);
            upperBits = 0;
            lowerBits = movedown;
        }

        return *this;
    }

    Bitboard128 Bitboard128::operator>>(const unsigned int n) const
    {
        Bitboard128 res = *this;
        return (res >>= n);
    }

    Bitboard128 &Bitboard128::operator&=(const Bitboard128 &b)
    {
        upperBits &= b.upperBits;
        lowerBits &= b.lowerBits;
        return *this;
    }

    Bitboard128 Bitboard128::operator&(const Bitboard128 &b) const
    {
        Bitboard128 res = *this;
        return (res &= b);
    }

    Bitboard128 &Bitboard128::operator|=(const Bitboard128 &b)
    {
        upperBits |= b.upperBits;
        lowerBits |= b.lowerBits;
        return *this;
    }

    Bitboard128 Bitboard128::operator|(const Bitboard128 &b) const
    {
        Bitboard128 res = *this;
        return (res |= b);
    }

    Bitboard128 &Bitboard128::operator^=(const Bitboard128 &b)
    {
        upperBits ^= b.upperBits;
        lowerBits ^= b.lowerBits;
        return *this;
    }

    Bitboard128 Bitboard128::operator^(const Bitboard128 &b) const
    {
        Bitboard128 res = *this;
        return (res ^= b);
    }

    Bitboard128 Bitboard128::operator~() const
    {
        return Bitboard128(~upperBits, ~lowerBits);
    }

    bool Bitboard128::operator==(const Bitboard128 &b) const
    {
        return ((upperBits == b.upperBits) && (lowerBits == b.lowerBits));
    }

    bool Bitboard128::operator!=(const Bitboard128 &b) const
    {
        return !operator==(b);
    }

    Bitboard64 Bitboard128::GetLowerBits() const
    {
        return lowerBits;
    }
}
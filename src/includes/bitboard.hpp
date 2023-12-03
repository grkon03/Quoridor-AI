#pragma once

#include <cstdint>
#include <string>

namespace QuoridorAI
{
    using Bitboard64 = uint64_t;

    namespace misc
    {
        /**
         * @enum BaseType
         * @brief base type of integer
         *
         * @note BT_BIN: binary, BT_HEX: hexadecimal
         */
        enum BaseType
        {
            BT_BIN,
            BT_HEX,
        };
    }

    /**
     * @brief 128bits - bitboard
     * @details 128bits bitboard with operators, regarded as unsigned integer
     */
    class Bitboard128
    {
        // bits

        Bitboard64 lowerBits;
        Bitboard64 upperBits;

    public:
        // constructors

        Bitboard128();
        Bitboard128(Bitboard64);
        Bitboard128(Bitboard64, Bitboard64);
        /**
         * @brief Construct a new Bitboard128 object
         * @note If it is over the max value (2^128 - 1), or if something is wrong, the value is set to 0.
         */
        Bitboard128(std::string, misc::BaseType);
        /**
         * @brief Construct a new Bitboard128 object
         * @note Begin with "0x" or "0b".
         */
        Bitboard128(std::string);

        // operators

        Bitboard128 operator=(const Bitboard128 &);
        Bitboard128 operator=(const std::string);

        Bitboard128 &operator+=(const Bitboard128 &);
        Bitboard128 operator+(const Bitboard128 &) const;
        Bitboard128 &operator+=(const Bitboard64);
        Bitboard128 operator+(const Bitboard64) const;

        Bitboard128 &operator-=(const Bitboard128 &);
        Bitboard128 operator-(const Bitboard128 &) const;
        Bitboard128 &operator-=(const Bitboard64);
        Bitboard128 operator-(const Bitboard64) const;

        Bitboard128 &operator<<=(const unsigned int);
        Bitboard128 operator<<(const unsigned int) const;
        Bitboard128 &operator>>=(const unsigned int);
        Bitboard128 operator>>(const unsigned int) const;

        Bitboard128 &operator&=(const Bitboard128 &);
        Bitboard128 operator&(const Bitboard128 &) const;

        Bitboard128 &operator|=(const Bitboard128 &);
        Bitboard128 operator|(const Bitboard128 &) const;

        Bitboard128 &operator^=(const Bitboard128 &);
        Bitboard128 operator^(const Bitboard128 &) const;

        Bitboard128 operator~() const;

        bool operator==(const Bitboard128 &) const;
        bool operator!=(const Bitboard128 &) const;

        std::string ToString(misc::BaseType);

        Bitboard64 GetLowerBits() const;
        Bitboard64 GetUpperBits() const;
    };

    inline Bitboard128 lsb(Bitboard128 bb)
    {
        return bb & (~bb + 1);
    }
}
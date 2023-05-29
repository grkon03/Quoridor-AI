#pragma once

#include <cstdint>
#include <string>

namespace QuoridorAI
{
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
     * @brief 96bits - bitboard
     * @details 96bits bitboard with operators, regarded as unsigned integer
     */
    class Bitboard96
    {
        // bits

        uint64_t lowerBits;
        uint32_t upperBits;

        // errors

        bool overflow;
        bool invalidExpression;

    public:
        // constructors

        Bitboard96();
        Bitboard96(uint64_t);
        Bitboard96(uint32_t, uint64_t);
        /**
         * @brief Construct a new Bitboard96 object
         * @note If it is over the max value (2^96 - 1), or if something is wrong, the value is set to 0.
         */
        Bitboard96(std::string, misc::BaseType);
        /**
         * @brief Construct a new Bitboard96 object
         * @note Begin with "0x" or "0b".
         */
        Bitboard96(std::string);

        // operators

        Bitboard96 operator=(const Bitboard96 &);
        Bitboard96 operator=(const std::string);

        Bitboard96 &operator+=(const Bitboard96 &);
        Bitboard96 operator+(const Bitboard96 &) const;
        Bitboard96 &operator+=(const uint64_t);
        Bitboard96 operator+(const uint64_t) const;

        Bitboard96 &operator-=(const Bitboard96 &);
        Bitboard96 operator-(const Bitboard96 &) const;
        Bitboard96 &operator-=(const uint64_t);
        Bitboard96 operator-(const uint64_t) const;

        Bitboard96 &operator<<=(const unsigned int);
        Bitboard96 operator<<(const unsigned int) const;
        Bitboard96 &operator>>=(const unsigned int);
        Bitboard96 operator>>(const unsigned int) const;

        Bitboard96 &operator&=(const Bitboard96 &);
        Bitboard96 operator&(const Bitboard96 &) const;

        Bitboard96 &operator|=(const Bitboard96 &);
        Bitboard96 operator|(const Bitboard96 &) const;

        Bitboard96 &operator^=(const Bitboard96 &);
        Bitboard96 operator^(const Bitboard96 &) const;

        Bitboard96 operator~() const;

        bool operator==(const Bitboard96 &) const;
        bool operator!=(const Bitboard96 &) const;

        // functions

        bool IsError() const;

        bool IsOverflow() const;
        bool IsInvalidExpression() const;

        void InheritError(const Bitboard96 &);
    };
}
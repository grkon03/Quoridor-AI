#include "misc.hpp"

namespace QuoridorAI
{
    namespace misc
    {
        constexpr uint64_t fullbits64 = 0xffffffffffffffffULL;
        constexpr uint32_t fullbits32 = 0xffffffffUL;

        /**
         * @brief lower bits mask of 64-bit bitmap
         * ex) lowerBitsFullMask64[5] = 0b11111
         */
        const uint64_t lowerBitsFullMask64[65] = {
            0,
            fullbits64 >> 63,
            fullbits64 >> 62,
            fullbits64 >> 61,
            fullbits64 >> 60,
            fullbits64 >> 59,
            fullbits64 >> 58,
            fullbits64 >> 57,
            fullbits64 >> 56,
            fullbits64 >> 55,
            fullbits64 >> 54,
            fullbits64 >> 53,
            fullbits64 >> 52,
            fullbits64 >> 51,
            fullbits64 >> 50,
            fullbits64 >> 49,
            fullbits64 >> 48,
            fullbits64 >> 47,
            fullbits64 >> 46,
            fullbits64 >> 45,
            fullbits64 >> 44,
            fullbits64 >> 43,
            fullbits64 >> 42,
            fullbits64 >> 41,
            fullbits64 >> 40,
            fullbits64 >> 39,
            fullbits64 >> 38,
            fullbits64 >> 37,
            fullbits64 >> 36,
            fullbits64 >> 35,
            fullbits64 >> 34,
            fullbits64 >> 33,
            fullbits64 >> 32,
            fullbits64 >> 31,
            fullbits64 >> 30,
            fullbits64 >> 29,
            fullbits64 >> 28,
            fullbits64 >> 27,
            fullbits64 >> 26,
            fullbits64 >> 25,
            fullbits64 >> 24,
            fullbits64 >> 23,
            fullbits64 >> 22,
            fullbits64 >> 21,
            fullbits64 >> 20,
            fullbits64 >> 19,
            fullbits64 >> 18,
            fullbits64 >> 17,
            fullbits64 >> 16,
            fullbits64 >> 15,
            fullbits64 >> 14,
            fullbits64 >> 13,
            fullbits64 >> 12,
            fullbits64 >> 11,
            fullbits64 >> 10,
            fullbits64 >> 9,
            fullbits64 >> 8,
            fullbits64 >> 7,
            fullbits64 >> 6,
            fullbits64 >> 5,
            fullbits64 >> 4,
            fullbits64 >> 3,
            fullbits64 >> 2,
            fullbits64 >> 1,
            fullbits64 >> 0,
        };

        /**
         * @brief lower bits mask of 32-bit bitmap
         * ex) lowerBitsFullMask32[5] = 0b11111
         */
        const uint32_t lowerBitsFullMask32[33] = {
            0,
            fullbits32 >> 31,
            fullbits32 >> 30,
            fullbits32 >> 29,
            fullbits32 >> 28,
            fullbits32 >> 27,
            fullbits32 >> 26,
            fullbits32 >> 25,
            fullbits32 >> 24,
            fullbits32 >> 23,
            fullbits32 >> 22,
            fullbits32 >> 21,
            fullbits32 >> 20,
            fullbits32 >> 19,
            fullbits32 >> 18,
            fullbits32 >> 17,
            fullbits32 >> 16,
            fullbits32 >> 15,
            fullbits32 >> 14,
            fullbits32 >> 13,
            fullbits32 >> 12,
            fullbits32 >> 11,
            fullbits32 >> 10,
            fullbits32 >> 9,
            fullbits32 >> 8,
            fullbits32 >> 7,
            fullbits32 >> 6,
            fullbits32 >> 5,
            fullbits32 >> 4,
            fullbits32 >> 3,
            fullbits32 >> 2,
            fullbits32 >> 1,
            fullbits32 >> 0,
        };
    }
}
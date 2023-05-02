#pragma once

#include <cstdint>

namespace QuoridorAI
{
    namespace misc
    {
        extern const uint64_t fullbits64;
        extern const uint32_t fullbits32;

        extern const uint64_t lowerBitsFullMask64[65];
        extern const uint32_t lowerBitsFullMask32[33];
        extern const uint64_t higherBitsFullMask64[65];
        extern const uint64_t higherBitsFullMask32[33];
        extern const uint64_t oneBitMask64[64];
        extern const uint32_t oneBitMask32[32];
    }
}
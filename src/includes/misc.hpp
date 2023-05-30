#pragma once

#include <cstdint>

// operation activator

#define ActivateEnumOperation(TYPE)                                            \
    constexpr bool operator==(TYPE a, TYPE b) { return int(a) == int(b); }     \
    constexpr bool operator!=(TYPE a, TYPE b) { return !(a == b); }            \
    constexpr TYPE operator+(TYPE a, TYPE b) { return TYPE(int(a) + int(b)); } \
    inline TYPE &operator+=(TYPE &a, TYPE b) { return (a = a + b); }           \
    constexpr TYPE operator-(TYPE a, TYPE b) { return TYPE(int(a) - int(b)); } \
    inline TYPE &operator-=(TYPE &a, const TYPE b) { return (a = a - b); }     \
    constexpr TYPE operator*(TYPE a, TYPE b) { return TYPE(int(a) * int(b)); } \
    inline TYPE &operator*=(TYPE &a, TYPE b) { return (a = a * b); }           \
    constexpr TYPE operator/(TYPE a, TYPE b) { return TYPE(int(a) / int(b)); } \
    inline TYPE &operator/=(TYPE &a, const TYPE b) { return (a = a / b); }     \
    inline TYPE &operator++(TYPE &a) { return (a = a + TYPE(1)); }             \
    inline TYPE &operator--(TYPE &a) { return (a = a + TYPE(1)); }

namespace QuoridorAI
{
    namespace misc
    {
        extern const uint64_t fullbits64;
        extern const uint32_t fullbits32;

        extern const uint64_t lowerBitsFullMask64[65];
        extern const uint32_t lowerBitsFullMask32[33];
        extern const uint64_t upperBitsFullMask64[65];
        extern const uint64_t upperBitsFullMask32[33];
        extern const uint64_t oneBitMask64[64];
        extern const uint32_t oneBitMask32[32];
    }
}
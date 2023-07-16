#include "mt.hpp"

namespace QuoridorAI
{
    namespace Hasher
    {
        MTRandomizer::MTRandomizer() : Randomizer(64), old(2906) {}
        MTRandomizer::MTRandomizer(HashKey seed) : Randomizer(64), old(seed) {}
        MTRandomizer::MTRandomizer(int _size, HashKey seed) : Randomizer(_size), old(seed) {}

        HashKey MTRandomizer::next()
        {
            old ^= old >> 12, old ^= old << 25, old ^= old >> 27;
            if (size >= 64)
                return (old * 2685821657736338717LL);
            else
                return (old * 2685821657736338717LL) % (1ULL << size);
        }
    }
}
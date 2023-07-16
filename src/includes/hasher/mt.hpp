#pragma once
#include "../types.hpp"
#include "random.hpp"

namespace QuoridorAI
{
    namespace Hasher
    {
        /**
         * @brief Randomizer using Mersenne twister
         *
         */
        class MTRandomizer : public RandomizerBase
        {
            HashKey old;

        public:
            // constructors

            /**
             * @brief Construct a new MTRandomizer, seed is set to 2906, and size is set to 64
             *
             */
            MTRandomizer();
            /**
             * @brief Construct a new MTRandomizer, size is set to 64
             *
             * @param seed seed of this randomizer
             */
            MTRandomizer(HashKey seed);
            /**
             * @brief Construct a new MTRandomizer
             *
             * @param size size of generated numbers: restricted to {size}-bits numbers
             * @param seed seed of this randomizer
             */
            MTRandomizer(int size, HashKey seed);

            // functions

            /**
             * @brief generate a new HashKey by Mersenne twister
             *
             * @return HashKey
             */
            HashKey next();
        };
    }
}
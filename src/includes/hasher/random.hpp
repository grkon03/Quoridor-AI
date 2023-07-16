#pragma once
#include "../types.hpp"

namespace QuoridorAI
{
    namespace Hasher
    {
        /**
         * @brief Abstract class of randomizers for hash
         *
         */
        class RandomizerBase
        {
        protected:
            /// @brief random number size: generated number should be restricted to {size}-bits numbers
            const int size;

        public:
            // constructos

            /**
             * @brief Construct a new Randomizer, size is set to 64
             *
             */
            RandomizerBase();
            /**
             * @brief Construct a new Randomizer
             * @param size size of generated numbers: restricted to {size}-bits numbers
             *
             */
            RandomizerBase(int size);

            // virtual functions

            /**
             * @brief generate new HashKey
             *
             * @return HashKey
             */
            virtual HashKey next() = 0;
        };
    }
}
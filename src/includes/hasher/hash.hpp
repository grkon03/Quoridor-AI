#pragma once

#include "../types.hpp"
#include "keys.hpp"

namespace QuoridorAI
{
    namespace Hasher
    {
        /**
         * @brief Implement Zobrist Hashing
         *
         */
        class ZobristHash
        {
            HashKey currentKey;

            /**
             * @brief index expressing king squares, dominated by Indexer::indexer
             *
             */
            int indexOfKings[ColorLimit];

        public:
            // static variables

            /**
             * @brief hash keys used for hash
             *
             * Why is this static variable? -- keys should be same.
             *
             */
            static const ZobristKey basicKeys;

            // costructors

            /**
             * @brief Construct a new Zobrist Hasher
             *
             * @param basicKeys basic hash keys expressing relations between moves and hashkeys
             * @param whiteKing the place of a white king
             * @param blackKing the place of a black king
             * @param currentKey The hash key begins from initialKey
             */
            ZobristHash(Square whiteKing, Square blackKing, HashKey currentKey);
            /**
             * @brief Construct a new Zobrist Hasher
             *
             * @param basicKeys basic hash keys expressing relations between moves and hashkeys
             */
            ZobristHash();

            // functions

            /**
             * @brief To get the current hash key
             *
             * @return current hash keys
             */
            inline HashKey GetCurrentKey() const { return currentKey; };
            /**
             * @brief Get the Next Key object
             *
             * @return next hash key after this move
             */
            HashKey GetNextKey(Move, Color);
        };
    }
}
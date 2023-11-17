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

            /**
             * @brief color of the turn player
             *
             */
            Color turnPlayer;

        public:
            // static variables

            /**
             * @brief basic hash keys expressing relations between moves and hashkeys
             *
             * Why is this static variable? -- keys should be same.
             *
             */
            static const ZobristKey basicKeys;

            // costructors

            /**
             * @brief Construct a new Zobrist Hasher
             *
             * @param whiteKing the place of a white king
             * @param blackKing the place of a black king
             * @param turnPlayer color of the turn player
             * @param currentKey The hash key begins from initialKey
             */
            ZobristHash(Square whiteKing, Square blackKing, Color turnPlayer, HashKey currentKey);
            /**
             * @brief Construct a new Zobrist Hasher
             *
             */
            ZobristHash();
            /**
             * @brief Construct a new Zobrist Hasher
             *
             * @param moveRecords move records (per a color)
             */
            ZobristHash(std::vector<int> moveRecords[ColorLimit]);

            // functions

            /**
             * @brief To get the current hash key
             *
             * @return current hash keys
             */
            inline HashKey GetCurrentKey() const { return currentKey; };
            /**
             * @brief Get the Next Key
             *
             * @return next hash key after this move
             */
            HashKey GetNextKey(Move, Color);
            /**
             * @brief Get the Next Key
             *
             * @return next hash key after this move
             */
            HashKey GetNextKey(Move);
            /**
             * @brief Get the Next Key
             *
             * @param moveIndex index of the move
             * @return next hash key after this move
             */
            HashKey GetNextKey(int moveIndex);
            /**
             * @brief Get the Next Key after fence move
             *
             * @param fenceIndex index of the fence
             * @return next hash key after this move
             */
            HashKey GetNextKeyAfterFenceMove(int fenceIndex);
            /**
             * @brief Get the Next Key after king move
             *
             * @param squareIndex index of the square
             * @return next hash key after this move
             */
            HashKey GetNextKeyAfterKingMove(int squareIndex);

            /**
             * @brief Get the Key by reading a game record
             *
             * @param moveRecords move records (per a color)
             * @return the key after all moves are did
             */
            HashKey GetKeyByGameRecord(std::vector<int> moveRecords[ColorLimit]);

            // operators

            inline bool operator==(const ZobristHash &h) const { return (currentKey == h.currentKey); }
            inline bool operator!=(const ZobristHash &h) const { return (currentKey != h.currentKey); }
        };
    }
}
#include "../indexer/indexer.hpp"
#include "hash.hpp"

namespace QuoridorAI
{
    namespace Hasher
    {
        ZobristHash::ZobristHash(Square whiteKing, Square blackKing, HashKey currentKey)
            : indexOfKings{Indexer::SquareToIndex(whiteKing), Indexer::SquareToIndex(blackKing)},
              currentKey(currentKey){};
        ZobristHash::ZobristHash()
            : indexOfKings{Indexer::SquareToIndex(MakeSquare(SE_E0, SE_F0)),
                           Indexer::SquareToIndex(MakeSquare(SE_E9, SE_F9))},
              currentKey(basicKeys.SquareKey[White][Indexer::SquareToIndex(
                             MakeSquare(SE_E0, SE_F0))] ^
                         basicKeys.SquareKey[Black][Indexer::SquareToIndex(
                             MakeSquare(SE_E9, SE_F9))]){};

        HashKey ZobristHash::GetNextKey(Move move, Color color)
        {
            if (IsFenceMove(move))
            {
                return currentKey ^= basicKeys.FenceKey[Indexer::FenceToIndex(Fence(move))];
            }
            else if (IsKingMove(move))
            {
                currentKey ^= basicKeys.SquareKey[color][indexOfKings[color]];
                indexOfKings[color] = Indexer::SquareToIndex(Square(move));
                return currentKey ^= basicKeys.SquareKey[color][indexOfKings[color]];
            }

            return currentKey;
        }

        const ZobristKey ZobristHash::basicKeys = ZobristKey::general;
    }
}
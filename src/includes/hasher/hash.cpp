#include "../indexer/indexer.hpp"
#include "hash.hpp"

namespace QuoridorAI
{
    namespace Hasher
    {
        ZobristHash::ZobristHash(Square whiteKing, Square blackKing, Color turnPlayer, HashKey currentKey)
            : indexOfKings{Indexer::SquareToIndex(whiteKing), Indexer::SquareToIndex(blackKing)},
              turnPlayer(turnPlayer), currentKey(currentKey){};
        ZobristHash::ZobristHash()
            : indexOfKings{Indexer::SquareToIndex(MakeSquare(SE_E0, SE_F1)),
                           Indexer::SquareToIndex(MakeSquare(SE_E8, SE_F9))},
              turnPlayer(White),
              currentKey(basicKeys.SquareKey[White][Indexer::SquareToIndex(
                             MakeSquare(SE_E0, SE_F1))] ^
                         basicKeys.SquareKey[Black][Indexer::SquareToIndex(
                             MakeSquare(SE_E8, SE_F9))]){};

        HashKey ZobristHash::GetNextKey(Move move, Color color)
        {
            turnPlayer = !color;
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

        HashKey ZobristHash::GetNextKey(Move move)
        {
            Color color = turnPlayer;
            turnPlayer = !turnPlayer;
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

        namespace
        {
            MTRandomizer __mt(2906);
        }

        const ZobristKey ZobristHash::basicKeys = ZobristKey(__mt);
    }
}
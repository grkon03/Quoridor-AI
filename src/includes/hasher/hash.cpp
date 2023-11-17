#include "../indexer/indexer.hpp"
#include "hash.hpp"

#include <vector>

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

        HashKey ZobristHash::GetNextKey(int moveIndex)
        {
            if (moveIndex < 81)
                return GetNextKeyAfterKingMove(moveIndex);
            else
                return GetNextKeyAfterFenceMove(moveIndex - 81);
        }

        HashKey ZobristHash::GetNextKeyAfterFenceMove(int fenceIndex)
        {
            turnPlayer = !turnPlayer;
            return currentKey ^= basicKeys.FenceKey[fenceIndex];
        }

        HashKey ZobristHash::GetNextKeyAfterKingMove(int squareIndex)
        {
            currentKey ^= basicKeys.SquareKey[turnPlayer][indexOfKings[turnPlayer]];
            indexOfKings[turnPlayer] = squareIndex;
            turnPlayer = !turnPlayer;
            return currentKey ^= basicKeys.SquareKey[!turnPlayer][squareIndex];
        }

        HashKey ZobristHash::GetKeyByGameRecord(std::vector<int> moveRecords[ColorLimit])
        {
            int i;
            Color turnPlayerAtLoopBegining = turnPlayer;

            for (i = 0; i < std::min(moveRecords[White].size(), moveRecords[Black].size()); ++i)
            {
                GetNextKey(moveRecords[turnPlayerAtLoopBegining][i]);
                GetNextKey(moveRecords[!turnPlayerAtLoopBegining][i]);
            }

            // the case exists, in which a turn player at loop begining did one more move than the opponent did.

            if (moveRecords[turnPlayerAtLoopBegining].size() > i)
                GetNextKey(moveRecords[turnPlayerAtLoopBegining][i]);

            return currentKey;
        }

        namespace
        {
            MTRandomizer __mt(2906);
        }

        const ZobristKey ZobristHash::basicKeys = ZobristKey(__mt);
    }
}
#include "dijkstra.hpp"
#include "../wallman.hpp"
#include "../indexer/IndexerAllIncludes.hpp"

#include <algorithm>

namespace QuoridorAI
{
    Dijkstra::Dijkstra() {}
    Dijkstra::Dijkstra(const WallBBOD<Vertical> &wallVBB, const WallBBOD<Horizontal> &wallHBB)
        : Dijkstra(WallBBs(wallVBB, wallHBB)) {}
    Dijkstra::Dijkstra(const WallBBs &wallBBs) : wallBBs(wallBBs)
    {
        for (int i = 0; i < NumberOfSquare; ++i)
        {
            distances[White][i] = misc::initDistance[White][i];
            distances[Black][i] = misc::initDistance[Black][i];
        }

        DijkstraRecursive(White, 1);
        DijkstraRecursive(Black, 1);
    }
    Dijkstra::Dijkstra(const WallMan &wm) : Dijkstra(wm.GetWallBBs()) {}

    void Dijkstra::GetDistances(Distance receiver[ColorLimit][NumberOfSquare]) const
    {
        for (int i = 0; i < NumberOfSquare; ++i)
        {
            receiver[White][i] = distances[White][i];
            receiver[Black][i] = distances[Black][i];
        }
    }

    Distance Dijkstra::GetDistance(Square square, Color color) const
    {
        return distances[color][Indexer::SquareToIndex(square)];
    }

    Distance Dijkstra::GetDistance(int squareIndex, Color color) const
    {
        return distances[color][squareIndex];
    }

    bool Dijkstra::IsThereReachableToGoal(Square square, Color color) const
    {
        return (distances[color][Indexer::SquareToIndex(square)] != Unreachable);
    }

    bool Dijkstra::IsThereReachableToGoal(int squareIndex, Color color) const
    {
        return (distances[color][squareIndex] != Unreachable);
    }

    bool Dijkstra::IsThereReachableToGoal(SquareEdge se, Color color) const
    {
        return (distances[color][GetRank(se) * 9 + GetFile(se)]);
    }

    void Dijkstra::DijkstraRecursive(const Color color, const Distance phase)
    {
        bool continueProcess = false;
        int searchStart, searchLimit;

        switch (color)
        {
        case White:
            // if phase is small, no need to search bottom squares
            searchStart = std::max(0, (8 - (int)phase) * 9);
            // limit is the square I7-J8
            searchLimit = 72;
            break;
        case Black:
            // start from A1-B2
            searchStart = 9;
            // if phase is small, no need to search top squares
            searchLimit = std::min((int)NumberOfSquare, ((int)phase + 1) * 9);
            break;
        default:
            return;
        }

        for (int squareIndex = searchStart; squareIndex < searchLimit; ++squareIndex)
        {
            // not searched verification
            if (distances[color][squareIndex] != Unreachable)
                continue;

            if (phase == CalcTemporaryDistance(color, squareIndex))
            {
                // decide distances if distance is same as phase
                distances[color][squareIndex] = phase;
                continueProcess = true;
            }
        }

        // if there are updated squares, continue searching
        if (continueProcess)
            DijkstraRecursive(color, phase + 1);
    }

    Distance Dijkstra::CalcTemporaryDistance(Color color, int squareIndex)
    {
        Distance minDistance = 81;

        // left-bottom square edge of the square
        SquareEdge lbse = ExtractSquareEdgeLower((Move)Indexer::indexer.IndexedSquare[squareIndex]);

        // top
        // if squareIndex is 72 or more, the square has no top square
        if (squareIndex < 72)
            if ((distances[color][squareIndex + 9] != Unreachable) &&
                !wallBBs.IsThereWall<Horizontal>((SquareEdge)(lbse + 10)))
                minDistance = std::min(minDistance, distances[color][squareIndex + 9]);

        // bottom
        // if squareIndex is 8 or less, the square has no bottom square
        if (squareIndex > 8)
            if ((distances[color][squareIndex - 9] != Unreachable) &&
                !wallBBs.IsThereWall<Horizontal>(lbse))
                minDistance = std::min(minDistance, distances[color][squareIndex - 9]);

        // left
        // if squareIndex % 9 is 0, the square has no left square
        if (squareIndex % 9 > 0)
            if ((distances[color][squareIndex - 1] != Unreachable) &&
                !wallBBs.IsThereWall<Vertical>(lbse))
                minDistance = std::min(minDistance, distances[color][squareIndex - 1]);

        // right
        // if squareIndex % 9 is 8, the square has no right square
        if (squareIndex % 9 < 8)
            if ((distances[color][squareIndex + 1] != Unreachable) &&
                !wallBBs.IsThereWall<Vertical>((SquareEdge)(lbse + 1)))
                minDistance = std::min(minDistance, distances[color][squareIndex + 1]);

        return minDistance + 1;
    }
}
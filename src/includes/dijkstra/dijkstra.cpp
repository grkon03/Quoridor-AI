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

        DijkstraRecursive(White);
        DijkstraRecursive(Black);
    }
    Dijkstra::Dijkstra(const WallMan &wm) : Dijkstra(wm.GetWallBBs()) {}

    void Dijkstra::DijkstraRecursive(const Color color)
    {
        int candidates[41];
        int numOfCandidates = 0;
        Distance distance;
        Distance minDistance = 81;
        bool notInCandidates;

        for (int squareIndex = 0; squareIndex < NumberOfSquare; ++squareIndex)
        {
            // not searched verification
            if (distances[color][squareIndex] != Unreachable)
                continue;

            distance = CalcTemporaryDistance(color, squareIndex);

            if (distance == Unreachable)
            {
                // no process if still unreachable
                continue;
            }
            else if (distance == minDistance)
            {
                // add this square to candidates if same distance as minDistance
                candidates[numOfCandidates] = squareIndex;
                ++numOfCandidates;
            }
            else if (distance < minDistance)
            {
                // update candidates if fewer distance than minDistance
                candidates[0] = squareIndex;
                numOfCandidates = 1;
            }
        }

        // end recursive if no candidates
        if (numOfCandidates == 0)
            return;

        for (int i = 0; i < numOfCandidates; ++i)
        {
            distances[color][candidates[i]] = minDistance;
        }

        DijkstraRecursive(color);
    }

    Distance Dijkstra::CalcTemporaryDistance(Color color, int squareIndex)
    {
        Distance minDistance = 81;

        // left-bottom square edge of the square
        SquareEdge lbse = ExtractSquareEdgeLower((Move)Indexer::indexer.IndexedSquare[squareIndex]);

        // top
        // if squareIndex is 71 or more, the square has no top square
        if (squareIndex < 71)
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

        if (minDistance == 81)
            return Unreachable;
        else
            return minDistance;
    }
}
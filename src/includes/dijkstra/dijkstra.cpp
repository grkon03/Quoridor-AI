#include "dijkstra.hpp"
#include "../wallman.hpp"
#include "../indexer/IndexerAllIncludes.hpp"

#include <algorithm>

namespace QuoridorAI
{
    Dijkstra::Dijkstra()
    {
        for (int i = 0; i < NumberOfSquare; ++i)
        {
            distances[White][i] = misc::startPositionDistance[White][i];
            distances[Black][i] = misc::startPositionDistance[Black][i];
        }
    }
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
    Dijkstra::Dijkstra(const Dijkstra &dijkstra) : wallBBs(dijkstra.wallBBs)
    {
        for (int i = 0; i < NumberOfSquare; ++i)
        {
            distances[White][i] = dijkstra.distances[White][i];
            distances[Black][i] = dijkstra.distances[Black][i];
        }
    }

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

    void Dijkstra::PutFence(Fence fence)
    {
        switch (GetWallDir(fence))
        {
        case Vertical:
            PutFence<Vertical>(ExtractSquareEdgeLower((Move)fence));
            break;
        case Horizontal:
            PutFence<Horizontal>(ExtractSquareEdgeLower((Move)fence));
            break;
        default:
            return;
        }
    }

    void Dijkstra::PutFence(int fenceIndex)
    {
        wallBBs.PutFence(fenceIndex);

        int lbSquareIndex = ((fenceIndex >> 3) & 0b111) * 9 + (fenceIndex & 0b111);

        UpdateDistancesByPutFence(White, lbSquareIndex);
        UpdateDistancesByPutFence(Black, lbSquareIndex);
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
        Distance minDistance = Unreachable;

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

    void Dijkstra::ReverseDijkstraRecursive(
        const Color color,
        const int squareIndex,
        int *numOfSquaresToUpdate,
        int squaresToUpdate[81])
    {
        // if already searched in reverse dijkstra
        if (distances[color][squareIndex] == Unreachable)
            return;

        // if goal square
        if (color == White && squareIndex >= 72)
            return;
        else if (color == Black && squareIndex < 9)
            return;

        bool top, bottom, left, right;
        top = bottom = left = right = false;
        Distance minDistance = Unreachable;

        // calculate temporary distance

        SquareEdge lbse = ExtractSquareEdgeLower((Move)Indexer::indexer.IndexedSquare[squareIndex]);

        // top
        // if squareIndex is 72 or more, the square has no top square
        if (squareIndex < 72)
            if ((distances[color][squareIndex + 9] != Unreachable) &&
                !wallBBs.IsThereWall<Horizontal>((SquareEdge)(lbse + 10)))
                top = true;

        // bottom
        // if squareIndex is 8 or less, the square has no bottom square
        if (squareIndex > 8)
            if ((distances[color][squareIndex - 9] != Unreachable) &&
                !wallBBs.IsThereWall<Horizontal>(lbse))
                bottom = true;

        // left
        // if squareIndex % 9 is 0, the square has no left square
        if (squareIndex % 9 > 0)
            if ((distances[color][squareIndex - 1] != Unreachable) &&
                !wallBBs.IsThereWall<Vertical>(lbse))
                left = true;

        // right
        // if squareIndex % 9 is 8, the square has no right square
        if (squareIndex % 9 < 8)
            if ((distances[color][squareIndex + 1] != Unreachable) &&
                !wallBBs.IsThereWall<Vertical>((SquareEdge)(lbse + 1)))
                right = true;

        if (top)
            minDistance = std::min(minDistance, distances[color][squareIndex + 9]);
        if (bottom)
            minDistance = std::min(minDistance, distances[color][squareIndex - 9]);
        if (left)
            minDistance = std::min(minDistance, distances[color][squareIndex - 1]);
        if (right)
            minDistance = std::min(minDistance, distances[color][squareIndex + 1]);

        // minDistance + 1 is a temporary distance

        // updating process

        if (distances[color][squareIndex] == minDistance + 1)
            return;

        distances[color][squareIndex] = Unreachable;

        squaresToUpdate[*numOfSquaresToUpdate] = squareIndex;
        ++(*numOfSquaresToUpdate);

        if (top)
            ReverseDijkstraRecursive(color, squareIndex + 9, numOfSquaresToUpdate, squaresToUpdate);
        if (bottom)
            ReverseDijkstraRecursive(color, squareIndex - 9, numOfSquaresToUpdate, squaresToUpdate);
        if (left)
            ReverseDijkstraRecursive(color, squareIndex - 1, numOfSquaresToUpdate, squaresToUpdate);
        if (right)
            ReverseDijkstraRecursive(color, squareIndex + 1, numOfSquaresToUpdate, squaresToUpdate);
    }

    void Dijkstra::UpdateDistancesByPutFence(const Color color, const int lbSquareIndex)
    {
        int numOfSquaresToUpdate = 0;
        int squaresToUpdate[81];

        ReverseDijkstraRecursive(color, lbSquareIndex, &numOfSquaresToUpdate, squaresToUpdate);
        ReverseDijkstraRecursive(color, lbSquareIndex + 1, &numOfSquaresToUpdate, squaresToUpdate);
        ReverseDijkstraRecursive(color, lbSquareIndex + 9, &numOfSquaresToUpdate, squaresToUpdate);
        ReverseDijkstraRecursive(color, lbSquareIndex + 10, &numOfSquaresToUpdate, squaresToUpdate);

        if (numOfSquaresToUpdate == 0)
            return;

        Distance minDistance = Unreachable;

        for (int i = 0; i < numOfSquaresToUpdate; ++i)
        {
            minDistance = std::min(minDistance, CalcTemporaryDistance(color, squaresToUpdate[i]));
        }

        DijkstraRecursive(color, minDistance);
    }
}
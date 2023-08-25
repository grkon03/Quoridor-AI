#include "wallman.hpp"

namespace QuoridorAI
{
    WallMan::WallMan()
        : wallBBs(), acrossBB(0ULL) {}
    WallMan::WallMan(WallBBs wallBBs, Bitboard64 acrossBB)
        : wallBBs(wallBBs), acrossBB(acrossBB), dijkstra(wallBBs) {}
    WallMan::WallMan(const WallMan &wm)
        : wallBBs(wm.wallBBs), acrossBB(wm.acrossBB), dijkstra(wm.dijkstra) {}

    WallBBs WallMan::GetWallBBs() const
    {
        return wallBBs;
    }

    bool WallMan::IsThereReachableToGoal(Square square, Color color) const
    {
        return dijkstra.IsThereReachableToGoal(square, color);
    }

    bool WallMan::IsThereReachableToGoal(int squareIndex, Color color) const
    {
        return dijkstra.IsThereReachableToGoal(squareIndex, color);
    }

    bool WallMan::IsThereReachableToGoal(SquareEdge se, Color color) const
    {
        return dijkstra.IsThereReachableToGoal(se, color);
    }

    void WallMan::GetDistances(Distance receiver[ColorLimit][NumberOfSquare]) const
    {
        dijkstra.GetDistances(receiver);
    }

    Distance WallMan::GetDistance(Square square, Color color) const
    {
        return dijkstra.GetDistance(square, color);
    }

    Distance WallMan::GetDistance(int squareIndex, Color color) const
    {
        return dijkstra.GetDistance(squareIndex, color);
    }

    Distance WallMan::GetDistance(SquareEdge se, Color color) const
    {
        return dijkstra.GetDistance(se, color);
    }
}
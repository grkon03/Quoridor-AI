#include "wallman.hpp"

namespace QuoridorAI
{
    WallMan::WallMan()
        : wallBBs(), availableFenceBB{misc::fullbits64, misc::fullbits64} {}

    WallMan::WallMan(WallBBs wallBBs)
        : wallBBs(wallBBs), dijkstra(wallBBs)
    {
        CalcAvailableFenceBB();
    }
    WallMan::WallMan(const WallMan &wm)
        : wallBBs(wm.wallBBs), dijkstra(wm.dijkstra), availableFenceBB{
                                                          wm.availableFenceBB[Vertical], wm.availableFenceBB[Horizontal]} {}

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

    void WallMan::CalcAvailableFenceBB()
    {
    }
}
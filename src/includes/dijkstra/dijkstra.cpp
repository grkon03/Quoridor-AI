#include "dijkstra.hpp"

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
}
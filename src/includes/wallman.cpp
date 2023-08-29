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

    Dijkstra WallMan::GetDijkstra() const
    {
        return dijkstra;
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
        Bitboard96 vbb = GetWallBBOD<Vertical>(), hbb = GetWallBBOD<Horizontal>();

        Bitboard64 overlapV, overlapH, intersectV, intersectH;
        int i;

        // overlap verification

        Bitboard96 overlapH96;

        overlapV = ((vbb >> 8) | (vbb)).GetLowerBits();
        overlapH96 = Bitboard96(0);
        for (i = 0; i < 8; ++i)
        {
            overlapH96 |= (((hbb >> (9 * i)) | (hbb >> (9 * i + 1))) & 0xff) << (8 * i);
        }
        overlapH = overlapH96.GetLowerBits();

        // intersection verification

        Bitboard96 intersectV96;
        Bitboard96 _lsb, extendedAvailableFenceBB;

        intersectV = intersectH = 0;

        // vertical

        while (hbb != 0)
        {
            _lsb = lsb(hbb);
            // delete the least significant fence
            hbb ^= _lsb | (_lsb << 1);

            extendedAvailableFenceBB |= _lsb;
        }

        for (i = 0; i < 8; ++i)
        {
            intersectV96 |= ((extendedAvailableFenceBB >> (9 * i)) & 0xff) << (8 * i);
        }
        intersectV = intersectV96.GetLowerBits();

        // horizontal

        extendedAvailableFenceBB = Bitboard96(0);

        while (vbb != 0)
        {
            _lsb = lsb(vbb);
            // delete the least significant fence
            vbb ^= _lsb | (_lsb << 8);
            extendedAvailableFenceBB |= _lsb;
        }

        intersectH = extendedAvailableFenceBB.GetLowerBits();

        // assign out of them

        availableFenceBB[Vertical] = ~(overlapV | intersectV);
        availableFenceBB[Horizontal] = ~(overlapH | intersectH);
    }
}
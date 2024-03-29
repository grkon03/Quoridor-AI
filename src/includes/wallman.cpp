#include <vector>
#include <algorithm>
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
        : wallBBs(wm.wallBBs), dijkstra(wm.dijkstra), availableFenceBB(wm.availableFenceBB) {}

    WallMan::WallMan(std::vector<int> moveRecords[ColorLimit]) : WallMan()
    {
        PutFencesByGameRecord(moveRecords, White);
    }

    WallBBs WallMan::GetWallBBs() const
    {
        return wallBBs;
    }

    Dijkstra WallMan::GetDijkstra() const
    {
        return dijkstra;
    }

    bool WallMan::PutFencesByGameRecord(std::vector<int> moveRecords[ColorLimit], Color turnPlayer)
    {
        int i;
        for (i = 0; i < std::min(moveRecords[turnPlayer].size(), moveRecords[!turnPlayer].size()); ++i)
        {
            if (moveRecords[turnPlayer][i] >= 81)
            {
                if (!PutFence(moveRecords[turnPlayer][i] - 81))
                    return false;
            }
            if (moveRecords[!turnPlayer][i] >= 81)
            {
                if (!PutFence(moveRecords[!turnPlayer][i] - 81))
                    return false;
            }
        }

        // the case exists, in which turnPlayer did one more move than the opponent did.

        if (moveRecords[turnPlayer].size() <= i)
            return true;

        return PutFence(moveRecords[turnPlayer][i] - 81);
    }

    void WallMan::RemoveFence(int fenceIndex)
    {
        if (fenceIndex < 0 || fenceIndex >= 128)
            return;

        wallBBs.RemoveFence(fenceIndex);
        dijkstra.RemoveFence(fenceIndex);

        UpdateAvailableFenceByRemoveFence(fenceIndex);
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
        Bitboard128 vbb = GetWallBBOD<Vertical>(), hbb = GetWallBBOD<Horizontal>();

        Bitboard128 overlapV, overlapH, intersectV, intersectH;
        int i;

        // overlap verification

        Bitboard128 overlapH128;

        overlapV = ((vbb >> 8) | (vbb)).GetLowerBits();
        overlapH128 = Bitboard128(0);
        for (i = 0; i < 8; ++i)
        {
            overlapH128 |= (((hbb >> (9 * i)) | (hbb >> (9 * i + 1))) & 0xff) << (8 * i);
        }
        overlapH = overlapH128.GetLowerBits();

        // intersection verification

        Bitboard128 intersectV128;
        Bitboard128 _lsb, extendedAvailableFenceBB;

        intersectV = intersectH = Bitboard128(0);

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
            intersectV128 |= ((extendedAvailableFenceBB >> (9 * i)) & 0xff) << (8 * i);
        }
        intersectV = intersectV128.GetLowerBits();

        // horizontal

        extendedAvailableFenceBB = Bitboard128(0);

        while (vbb != 0)
        {
            _lsb = lsb(vbb);
            // delete the least significant fence
            vbb ^= _lsb | (_lsb << 8);
            extendedAvailableFenceBB |= _lsb;
        }

        intersectH = extendedAvailableFenceBB.GetLowerBits();

        // assign out of them

        availableFenceBB = ~(overlapV | intersectV | ((overlapH | intersectH) << 64));
    }

    void WallMan::UpdateAvailableFenceByRemoveFence(int fenceIndex)
    {
        // todo: reinforce for quickness
        this->CalcAvailableFenceBB();
    }
}
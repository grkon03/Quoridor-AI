#include "wallman.hpp"

namespace QuoridorAI
{
    WallMan::WallMan() {}
    WallMan::WallMan(WallBBs wallBBs, Bitboard64 acrossBB)
        : wallBBs(wallBBs), acrossBB(acrossBB) {}
    WallMan::WallMan(const WallMan &wm)
        : wallBBs(wm.wallBBs), acrossBB(wm.acrossBB) {}

    WallBBs WallMan::GetWallBBs() const
    {
        return wallBBs;
    }
}
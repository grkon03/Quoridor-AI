#include "wallman.hpp"

namespace QuoridorAI
{
    WallMan::WallMan()
        : wallBBs(), acrossBB(0) {}
    WallMan::WallMan(WallBBs wallBBs, Bitboard64 acrossBB)
        : wallBBs(wallBBs), acrossBB(acrossBB) {}
    WallMan::WallMan(const WallMan &wm)
        : wallBBs(wm.wallBBs), acrossBB(wm.acrossBB) {}

    WallBBs WallMan::GetWallBBs() const
    {
        return wallBBs;
    }
}
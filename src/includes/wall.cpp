#include "wall.hpp"

namespace QuoridorAI
{
    WallBBs::WallBBs() {}
    WallBBs::WallBBs(WallBBOD<Vertical> wallVBB, WallBBOD<Horizontal> wallHBB)
        : wallVBB(wallVBB), wallHBB(wallHBB) {}
    WallBBs::WallBBs(const WallBBs &wallBBs)
        : wallVBB(wallBBs.wallVBB), wallHBB(wallBBs.wallHBB) {}
}
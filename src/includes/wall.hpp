#pragma once

#include "bitboard.hpp"
#include "types.hpp"

namespace QuoridorAI
{
    /**
     * @brief Wall by Bitboard expression
     */
    class WallBBOD : public Bitboard96
    {
        WallDir wallDir;

    public:
        // constructors

        WallBBOD(WallDir);
    };
}
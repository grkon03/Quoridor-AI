#pragma once

#include "bitboard.hpp"
#include "types.hpp"

namespace QuoridorAI
{
    /**
     * @brief Wall by Bitboard expression
     */
    template <WallDir direction>
    class WallBBOD : public Bitboard96
    {
    public:
        // constructors

        WallBBOD();
        WallBBOD(const WallBBOD &);
    };

    template <WallDir direction>
    WallBBOD<direction>::WallBBOD() {}
    template <WallDir direction>
    WallBBOD<direction>::WallBBOD(const WallBBOD &wb) : Bitboard96(wb) {}
}
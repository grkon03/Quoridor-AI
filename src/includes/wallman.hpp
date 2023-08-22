#pragma once

#include "wall.hpp"

namespace QuoridorAI
{
    /**
     * @brief Wall Manager
     *
     */
    class WallMan
    {
        // variables

        /**
         * @brief main wall bitboard
         *
         */
        WallBBs wallBBs;

        /**
         * @brief bitboard for across fence such that:
         * C3C5 and B4D4, in this case, these fences have intersection at C4.
         * Bits is set which the center square edge of fences
         *
         */
        Bitboard96 acrossBB;

    public:
        // constructors

        WallMan();
        /**
         * @note not recommended
         *
         */
        WallMan(WallBBs);
        WallMan(WallBBs, Bitboard96);
        WallMan(const WallMan &);

        // functions

        /**
         * @brief Get the WallBBs object
         *
         * @return WallBBs
         */
        WallBBs GetWallBBs() const;

        template <WallDir direction>
        WallBBOD<direction> GetWallBBOD() const;

        /**
         * @brief put fence
         *
         */
        void PutFence(Fence);

        /**
         * @brief put fence
         *
         * @tparam direction the fence direction
         * @param se left-bottom square edge of the fence
         */
        template <WallDir direction>
        void PutFence(SquareEdge se);

        /**
         * @brief put fence
         *
         * @param fenceIndex index of the fence
         */
        void PutFence(int fenceIndex);
    };
}
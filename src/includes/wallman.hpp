#pragma once

#include "misc.hpp"
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
        Bitboard64 acrossBB;

    public:
        // constructors

        WallMan();
        WallMan(WallBBs, Bitboard64);
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
         * @brief verify whether the fence have intersection with walls
         *
         * @param fence the fence
         */
        bool IsIntersect(Fence fence) const;

        /**
         * @brief verify whether the fence have intersection with walls
         *
         * @tparam direction direction of the fence
         * @param se left-bottom square edge of the fence
         */
        template <WallDir direction>
        bool IsIntersect(SquareEdge se) const;

        /**
         * @brief verify whether the fence have intersection with walls
         *
         * @param fenceIndex index of the fence
         */
        bool IsIntersect(int fenceIndex) const;

        /**
         * @brief put fence
         *
         * @param the fence
         */
        void PutFence(Fence fence);

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

        // static functions

        /**
         * @brief calculate acrossBB from fence
         *
         * @param fence the fence
         * @return acrossBB
         */
        static Bitboard64 FenceToAcrossBB(Fence fence);

        /**
         * @brief calculate acrossBB from fence
         *
         * @tparam direction direction of the fence
         * @param se left-bottom square edge of the fence
         * @return acrossBB
         */
        template <WallDir direction>
        static Bitboard64 FenceToAcrossBB(SquareEdge se);

        /**
         * @brief calculate acrossBB from fence
         *
         * @param fenceIndex index of the fence
         * @return acrossBB
         */
        static Bitboard64 FenceToAcrossBB(int fenceIndex);
    };

    template <>
    WallBBOD<Vertical> WallMan::GetWallBBOD() const
    {
        return wallBBs.GetWallVBB();
    }

    template <>
    WallBBOD<Horizontal> WallMan::GetWallBBOD() const
    {
        return wallBBs.GetWallHBB();
    }

    inline void WallMan::PutFence(Fence fence)
    {
        Bitboard64 centerBB = FenceToAcrossBB(fence);
        if ((acrossBB & centerBB) == 0)
        {
            acrossBB |= centerBB;
            wallBBs.PutFenceWithOverlapVerification(fence);
        }
    }

    template <WallDir direction>
    inline void WallMan::PutFence(SquareEdge se)
    {
        Bitboard64 centerBB = FenceToAcrossBB<direction>(se);
        if ((acrossBB & centerBB) == 0)
        {
            acrossBB |= centerBB;
            wallBBs.PutFenceWithOverlapVerification<direction>(se);
        }
    }

    inline void WallMan::PutFence(int fenceIndex)
    {
        Bitboard64 centerBB = FenceToAcrossBB(fenceIndex);
        if ((acrossBB & centerBB) == 0)
        {
            acrossBB |= centerBB;
            wallBBs.PutFenceWithOverlapVerification(fenceIndex);
        }
    }

    inline bool WallMan::IsIntersect(Fence fence) const
    {
        return (acrossBB & FenceToAcrossBB(fence)) != 0;
    }

    template <WallDir direction>
    inline bool WallMan::IsIntersect(SquareEdge se) const
    {
        return (acrossBB & FenceToAcrossBB<direction>(se)) != 0;
    }

    inline bool WallMan::IsIntersect(int fenceIndex) const
    {
        return (acrossBB & FenceToAcrossBB(fenceIndex)) != 0;
    }

    inline Bitboard64 WallMan::FenceToAcrossBB(Fence fence)
    {
        return misc::oneBitMask64[(ExtractSquareEdgeLower((Move)fence) + ExtractSquareEdgeUpper((Move)fence)) / 2];
    }

    template <>
    inline Bitboard64 WallMan::FenceToAcrossBB<Vertical>(SquareEdge se)
    {
        return misc::oneBitMask64[se - 1];
    }

    template <>
    inline Bitboard64 WallMan::FenceToAcrossBB<Horizontal>(SquareEdge se)
    {
        return misc::oneBitMask64[se - 10];
    }

    inline Bitboard64 WallMan::FenceToAcrossBB(int fenceIndex)
    {
        return misc::oneBitMask64[fenceIndex % 64];
    }
}
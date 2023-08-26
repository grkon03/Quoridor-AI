#pragma once

#include "misc.hpp"
#include "wall.hpp"
#include "indexer/IndexerAllIncludes.hpp"
#include "dijkstra/DijkstraAllIncludes.hpp"

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

        /**
         * @brief dijkstra algorithm
         *
         */
        Dijkstra dijkstra;

        /**
         * @brief bitboards for available fences such that:
         * if there is only the C3C5 fence, C2C4, C3C5, C4C6, B4D4 sections are unable to put fence, and the other sections are able to put.
         * Then, n-th bit with a WallDir is not set if n is remainder of index of C2C4, C3C5, C4C6, B4D4 after dividing by 64 along with the WallDir,
         * and is set if n is the others.
         */
        Bitboard64 availableFenceBB[WallDirLimit];

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
         *
         * @return whether succeed or not (whether the fence doesn't overlaps with walls and doesn't intersect wit walls)
         */
        bool PutFence(Fence fence);

        /**
         * @brief put fence
         *
         * @tparam direction the fence direction
         * @param se left-bottom square edge of the fence
         *
         * @return whether succeed or not (whether the fence doesn't overlaps with walls and doesn't intersect wit walls)
         */
        template <WallDir direction>
        bool PutFence(SquareEdge se);

        /**
         * @brief put fence
         *
         * @param fenceIndex index of the fence
         *
         * @return whether succeed or not (whether the fence doesn't overlaps with walls and doesn't intersect wit walls)
         */
        bool PutFence(int fenceIndex);

        /**
         * @brief verify whether a king of the color can reach to his goal from the specified square
         *
         * @param color color of the king
         * @param square the square
         */
        bool IsThereReachableToGoal(Square square, Color color) const;

        /**
         * @brief verify whether a king of the color can reach to his goal from the specified square
         *
         * @param color color of the king
         * @param squareIndex index of the square
         */
        bool IsThereReachableToGoal(int squareIndex, Color color) const;

        /**
         * @brief verify whether a king of the color can reach to his goal from the specified square
         *
         * @param color color of the king
         * @param se left-bottom square edge of the square
         */
        bool IsThereReachableToGoal(SquareEdge se, Color color) const;

        /**
         * @brief Get the distances
         *
         * @param receiver variable to receive distances
         */
        void GetDistances(Distance receiver[ColorLimit][NumberOfSquare]) const;

        /**
         * @brief Get the distance
         *
         * @param square the square
         * @param color color of the king
         */
        Distance GetDistance(Square square, Color color) const;

        /**
         * @brief Get the distance
         *
         * @param squareIndex index of the square
         * @param color color of the king
         */
        Distance GetDistance(int squareIndex, Color color) const;

        /**
         * @brief Get the distance
         *
         * @param square left-bottom square edge of the square
         * @param color color of the king
         */
        Distance GetDistance(SquareEdge se, Color color) const;

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

    private:
        // private functions

        /**
         * @brief calculate availableFenceBB from other informations
         *
         */
        void CalcAvailableFenceBB();

        /**
         * @brief update availableFenceBB after putting fence
         *
         * @param fence the put fence
         */
        void UpdateAvailableFenceByPutFence(Fence fence);

        /**
         * @brief update availableFenceBB after putting fence
         *
         * @param fenceIndex index of the put fence
         */
        void UpdateAvailableFenceByPutFence(int fenceIndex);

        /**
         * @brief update availableFenceBB after putting fence
         *
         * @tparam direction direction of the put fence
         * @param se left-bottom square edge of the put fence
         */
        template <WallDir direction>
        void UpdateAvailableFenceByPutFence(SquareEdge se);
    };

    template <>
    inline WallBBOD<Vertical> WallMan::GetWallBBOD<Vertical>() const
    {
        return wallBBs.GetWallVBB();
    }

    template <>
    inline WallBBOD<Horizontal> WallMan::GetWallBBOD<Horizontal>() const
    {
        return wallBBs.GetWallHBB();
    }

    inline bool WallMan::PutFence(Fence fence)
    {
        Bitboard64 centerBB = FenceToAcrossBB(fence);
        if ((acrossBB & centerBB) == 0)
        {
            if (!wallBBs.PutFenceWithOverlapVerification(fence))
                return false;

            acrossBB |= centerBB;
            dijkstra.PutFence(fence);
            UpdateAvailableFenceByPutFence(fence);
            return true;
        }

        return false;
    }

    template <WallDir direction>
    inline bool WallMan::PutFence(SquareEdge se)
    {
        Bitboard64 centerBB = FenceToAcrossBB<direction>(se);
        if ((acrossBB & centerBB) == 0)
        {
            if (!wallBBs.PutFenceWithOverlapVerification<direction>(se))
                return false;

            acrossBB |= centerBB;
            dijkstra.PutFence<direction>(se);
            UpdateAvailableFenceByPutFence<direction>(se);
            return true;
        }

        return false;
    }

    inline bool WallMan::PutFence(int fenceIndex)
    {
        Bitboard64 centerBB = FenceToAcrossBB(fenceIndex);
        if ((acrossBB & centerBB) == 0)
        {
            if (!wallBBs.PutFenceWithOverlapVerification(fenceIndex))
                return false;

            acrossBB |= centerBB;
            dijkstra.PutFence(fenceIndex);
            UpdateAvailableFenceByPutFence(fenceIndex);
            return true;
        }

        return false;
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

    template <>
    inline Bitboard64 WallMan::FenceToAcrossBB<Vertical>(SquareEdge se)
    {
        return misc::oneBitMask64[(GetRank(se) << 3) + GetFile(se) - 1];
    }

    template <>
    inline Bitboard64 WallMan::FenceToAcrossBB<Horizontal>(SquareEdge se)
    {
        return misc::oneBitMask64[((GetRank(se) - 1) << 3) + GetFile(se)];
    }

    inline Bitboard64 WallMan::FenceToAcrossBB(Fence fence)
    {
        return FenceToAcrossBB(Indexer::FenceToIndex(fence));
    }

    inline Bitboard64 WallMan::FenceToAcrossBB(int fenceIndex)
    {
        return misc::oneBitMask64[fenceIndex & 0x3f];
    }
}
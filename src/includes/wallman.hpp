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
        Bitboard128 availableFenceBB;

    public:
        // constructors

        WallMan();
        WallMan(WallBBs);
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

        Dijkstra GetDijkstra() const;

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
         * @brief verify whether there is wall at the section
         *
         * @tparam direction direction
         * @param se left-bottom square edge of the section
         */
        template <WallDir direction>
        bool IsThereWall(SquareEdge se) const;

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

        template <WallDir direction>
        Bitboard64 GetAvailableFenceBB() const;

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
        return PutFence(Indexer::FenceToIndex(fence));
    }

    template <WallDir direction>
    inline bool WallMan::PutFence(SquareEdge se)
    {
        if ((availableFenceBB[direction] & misc::oneBitMask64[((GetRank(se) - direction) << 3) + GetFile(se) + direction - 1]) == 0)
            return false;

        wallBBs.PutFence<direction>(se);
        dijkstra.PutFence<direction>(se);
        UpdateAvailableFenceByPutFence<direction>(se);

        return true;
    }

    inline bool WallMan::PutFence(int fenceIndex)
    {
        if (fenceIndex < 0 || fenceIndex >= 128)
            return false;

        if ((availableFenceBB & Constant::oneBitMask128[fenceIndex]) == 0)
            return false;

        wallBBs.PutFence(fenceIndex);
        dijkstra.PutFence(fenceIndex);
        UpdateAvailableFenceByPutFence(fenceIndex);

        return true;
    }

    template <>
    inline bool WallMan::IsThereWall<Horizontal>(SquareEdge se) const
    {
        return wallBBs.IsThereWall<Horizontal>(se);
    }

    template <>
    inline bool WallMan::IsThereWall<Vertical>(SquareEdge se) const
    {
        return wallBBs.IsThereWall<Vertical>(se);
    }

    inline void WallMan::UpdateAvailableFenceByPutFence(Fence fence)
    {
        UpdateAvailableFenceByPutFence(Indexer::FenceToIndex(fence));
    }

    inline void WallMan::UpdateAvailableFenceByPutFence(int fenceIndex)
    {
        if (fenceIndex < 64)
        {
            // vertical

            // overlap
            availableFenceBB[Vertical] &= Constant::availableFenceRemainMaskByIndex[fenceIndex];
            // intersect
            availableFenceBB[Horizontal] &= ~misc::oneBitMask64[fenceIndex];
        }
        else if (fenceIndex < 128)
        {
            // horizontal

            // overlap
            availableFenceBB[Horizontal] &= Constant::availableFenceRemainMaskByIndex[fenceIndex];
            // intersect
            availableFenceBB[Vertical] &= ~misc::oneBitMask64[fenceIndex - 64];
        }
    }

    template <>
    inline void WallMan::UpdateAvailableFenceByPutFence<Vertical>(SquareEdge se)
    {
        // overlap
        availableFenceBB[Vertical] &= Constant::availableFenceRemainMaskBySquareEdge[Vertical].at(se);
        // intersect
        availableFenceBB[Horizontal] &= ~misc::oneBitMask64[((GetRank(se) << 3) + GetFile(se) - 1)];
    }

    template <>
    inline void WallMan::UpdateAvailableFenceByPutFence<Horizontal>(SquareEdge se)
    {
        // overlap
        availableFenceBB[Horizontal] &= Constant::availableFenceRemainMaskBySquareEdge[Horizontal].at(se);
        // intersect
        availableFenceBB[Vertical] &= ~misc::oneBitMask64[((GetRank(se) - 1) << 3) + GetFile(se)];
    }

    template <WallDir direction>
    inline Bitboard64 WallMan::GetAvailableFenceBB() const
    {
        return availableFenceBB[direction];
    }
}
#pragma once

#include "bitboard.hpp"
#include "types.hpp"

#include "bitboardConst.hpp"

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
        WallBBOD(const Bitboard96 &);
        WallBBOD(const WallBBOD &);

        // functions

        /**
         * @brief verify whether there is wall at one section of walls
         *
         * @param file lower file of square edges of the section
         * @param rank lower rank of square edges of the section
         *
         * @note should Bottom-Left Square edge
         * @note for speed, no verification whether rank or file is out of range
         */
        bool IsThereWall(File file, Rank rank) const;

        /**
         * @brief verify whether there is wall at one section of walls
         *
         * @param se bottom-left one of square edges of the section
         *
         * @note should Bottom-Left Square edge
         * @note for speed, no verification whether square edge is out of range
         */
        bool IsThereWall(SquareEdge se) const;

        /**
         * @brief put fence
         *
         * @param se left-bottom square edges of the fence
         *
         * @note for speed, no varification whether the square edge is out of range
         */
        void PutFence(SquareEdge se);
        /**
         * @brief put fence
         *
         * @param fence the fence
         *
         * @note for speed, no varification whether the fence is out of range
         */
        void PutFence(Fence fence);
        /**
         * @brief put fence
         *
         * @param fenceIndex index of the fence (by Indexer)
         *
         * @note for speed, no varification whether the index is out of range
         */
        void PutFence(int fenceIndex);
    };

    template <WallDir direction>
    WallBBOD<direction>::WallBBOD() {}
    template <WallDir direction>
    WallBBOD<direction>::WallBBOD(const Bitboard96 &bb) : Bitboard96(bb) {}
    template <WallDir direction>
    WallBBOD<direction>::WallBBOD(const WallBBOD &wb) : Bitboard96(wb) {}

    template <>
    inline bool WallBBOD<Horizontal>::IsThereWall(File file, Rank rank) const
    {
        return (operator&(Constant::oneBitMask96[(rank - 1) * 9 + file]) != 0);
    }

    template <>
    inline bool WallBBOD<Vertical>::IsThereWall(File file, Rank rank) const
    {
        return (operator&(Constant::oneBitMask96[rank * 8 + file - 1]) != 0);
    }

    template <WallDir direction>
    inline bool WallBBOD<direction>::IsThereWall(SquareEdge se) const
    {
        return IsThereWall(GetFile(se), GetRank(se));
    }

    template <WallDir direction>
    inline void WallBBOD<direction>::PutFence(SquareEdge se)
    {
        operator|=(Constant::fenceMaskBySquareEdge[direction].at(se));
    }

    template <WallDir direction>
    inline void WallBBOD<direction>::PutFence(Fence fence)
    {
        operator|=(Constant::fenceMaskByFence.at(fence));
    }

    template <WallDir direction>
    inline void WallBBOD<direction>::PutFence(int fenceIndex)
    {
        operator|=(Constant::fenceMaskByIndex[fenceIndex]);
    }

    /**
     * @brief wall bitboard collection
     *
     */
    class WallBBs
    {
        // variables

        WallBBOD<Horizontal> wallHBB;
        WallBBOD<Vertical> wallVBB;

    public:
        // constructors

        WallBBs();
        WallBBs(WallBBOD<Horizontal>, WallBBOD<Vertical>);
        WallBBs(const WallBBs &);

        // functions

        /**
         * @brief verify whether there is a wall at the section with its edges se1, se2
         *
         * @param se1 the first edge of the section
         * @param se2 the second edge of the section
         */
        bool IsThereWall(SquareEdge se1, SquareEdge se2) const;

        /**
         * @brief verify whether there is a wall at the section its edges specified by file(i), rank(i)
         *
         * @param file1 file of the first edge of the section
         * @param rank1 rank of the first edge of the section
         * @param file2 file of the second edge of the secion
         * @param rank2 rank of the second edge of the secion
         */
        bool IsThereWall(File file1, Rank rank1, File file2, Rank rank2) const;

        template <WallDir direction>
        /**
         * @brief verify whether there is a wall at the section of specified direction
         *
         * @param se bottom-left square edge of the section
         */
        bool IsThereWall(SquareEdge se) const;

        template <WallDir direction>
        /**
         * @brief verify whether there is a wall at the secion of specified direction
         *
         * @param file lower one of files of the edges of the secion
         * @param rank lower one of ranks of the edges of the secion
         */
        bool IsThereWall(File file, Rank rank) const;

        /**
         * @brief put fence
         *
         * @tparam direction the direction
         * @param se left-bottom square edge of the fence
         */
        template <WallDir direction>
        void PutFence(SquareEdge se);

        /**
         * @brief put fence
         *
         * @param fence the fence
         */
        void PutFence(Fence fence);

        /**
         * @brief put fence
         *
         * @param fenceIndex index of the fence
         */
        void PutFence(int fenceIndex);
    };

    template <>
    inline bool WallBBs::IsThereWall<Horizontal>(SquareEdge se) const
    {
        return wallHBB.IsThereWall(se);
    }

    template <>
    inline bool WallBBs::IsThereWall<Vertical>(SquareEdge se) const
    {
        return wallVBB.IsThereWall(se);
    }

    inline bool WallBBs::IsThereWall(SquareEdge se1, SquareEdge se2) const
    {
        switch (int(se1 - se2))
        {
        case 1:
            return IsThereWall<Horizontal>(se2);
        case -1:
            return IsThereWall<Horizontal>(se1);
        case 10:
            return IsThereWall<Vertical>(se2);
        case -10:
            return IsThereWall<Vertical>(se1);
        default:
            return false;
        }
    }

    inline bool WallBBs::IsThereWall(File file1, Rank rank1, File file2, Rank rank2) const
    {
        return IsThereWall(MakeSquareEdge(file1, rank1), MakeSquareEdge(file2, rank2));
    }

    template <>
    inline bool WallBBs::IsThereWall<Horizontal>(File file, Rank rank) const
    {
        return wallHBB.IsThereWall(file, rank);
    }

    template <>
    inline bool WallBBs::IsThereWall<Vertical>(File file, Rank rank) const
    {
        return wallVBB.IsThereWall(file, rank);
    }

    template <>
    inline void WallBBs::PutFence<Vertical>(SquareEdge se)
    {
        wallVBB.PutFence(se);
    }

    template <>
    inline void WallBBs::PutFence<Horizontal>(SquareEdge se)
    {
        wallHBB.PutFence(se);
    }

    inline void WallBBs::PutFence(Fence fence)
    {
        switch (GetWallDir(fence))
        {
        case Vertical:
            wallVBB.PutFence(fence);
            break;
        case Horizontal:
            wallHBB.PutFence(fence);
            break;
        default:
            break;
        }
    }

    inline void WallBBs::PutFence(int fenceIndex)
    {
        if (fenceIndex < NumberOfFence / 2)
            // vertical
            wallVBB.PutFence(fenceIndex);
        else if (fenceIndex < NumberOfFence)
            // horizontal
            wallHBB.PutFence(fenceIndex);
    }
}
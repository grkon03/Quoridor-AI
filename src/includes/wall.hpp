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
         * @note for speed, no verification that rank or file is out of range
         */
        bool IsThereWall(File file, Rank rank) const;

        /**
         * @brief verify whether there is wall at one section of walls
         *
         * @param se bottom-left one of square edges of the section
         *
         * @note should Bottom-Left Square edge
         * @note for speed, no verification that square edge
         */
        bool IsThereWall(SquareEdge se) const;
    };

    template <WallDir direction>
    WallBBOD<direction>::WallBBOD() {}
    template <WallDir direction>
    WallBBOD<direction>::WallBBOD(const Bitboard96 &bb) : Bitboard96(bb) {}
    template <WallDir direction>
    WallBBOD<direction>::WallBBOD(const WallBBOD &wb) : Bitboard96(wb) {}

    template <>
    /**
     * @brief verify whether there is wall at one section of walls
     *
     * @param file lower file of square edges of the section
     * @param rank rank of the section of walls
     *
     * @note should Bottom-Left Square edge
     * @note for speed, no verification that rank or file is out of range
     */
    inline bool WallBBOD<Horizontal>::IsThereWall(File file, Rank rank) const
    {
        return (operator&(Constant::oneBitMask96[(rank - 1) * 9 + file]) != 0);
    }

    template <>
    /**
     * @brief verify whether there is wall at one section of walls
     *
     * @param file file of the section of walls
     * @param rank lower rank of square edges of the section
     *
     * @note should Bottom-Left Square edge
     * @note for speed, no verification that rank or file is out of range
     */
    inline bool WallBBOD<Vertical>::IsThereWall(File file, Rank rank) const
    {
        return (operator&(Constant::oneBitMask96[rank * 8 + file - 1]) != 0);
    }

    template <WallDir direction>
    /**
     * @brief verify whether there is wall at one section of walls
     *
     * @param se bottom-left one of square edges of the section
     *
     * @note should Bottom-Left Square edge
     * @note for speed, no verification that square edge
     */
    inline bool WallBBOD<direction>::IsThereWall(SquareEdge se) const
    {
        return IsThereWall(GetRank(se), GetFile(se));
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
        bool IsThereWall(File file, Rank rank);
    };
}
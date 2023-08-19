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
         * @param rank lower rank of square edges of the section
         * @param file lower file of square edges of the section
         *
         * @note should Bottom-Left Square edge
         * @note for speed, no verification that rank or file is out of range
         */
        bool IsThereWall(Rank rank, File file) const;

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
    inline bool WallBBOD<Horizontal>::IsThereWall(Rank rank, File file) const
    {
        return (operator&(Constant::oneBitMask96[(rank - 1) * 9 + file]) == 0);
    }
    template <>
    inline bool WallBBOD<Vertical>::IsThereWall(Rank rank, File file) const
    {
        return (operator&(Constant::oneBitMask96[rank * 9 + file - 1]) == 0);
    }

    template <WallDir direction>
    inline bool WallBBOD<direction>::IsThereWall(SquareEdge se) const
    {
        return IsThereWall(GetRank(se), GetFile(se));
    }
}
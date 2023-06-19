#pragma once
#include "misc.hpp"

namespace QuoridorAI
{
    // expressing player color
    enum Color : int
    {
        White = 0,
        Black,
        ColorLimit,
    };

    // expressing wall direction
    enum WallDir : int
    {
        Vertical = 0,
        Horizontal,
        WallDirLimit,
    };

    // Rank

    enum Rank : int
    {
        Rank0 = 0,
        Rank1,
        Rank2,
        Rank3,
        Rank4,
        Rank5,
        Rank6,
        Rank7,
        Rank8,
        Rank9,
        RankLimit,
    };

    ActivateEnumOperation(Rank);

    // File

    enum File : int
    {
        FileA = 0,
        FileB,
        FileC,
        FileD,
        FileE,
        FileF,
        FileG,
        FileH,
        FileI,
        FileJ,
        FileLimit,
    };

    ActivateEnumOperation(File);

    // SquareEdge

    enum SquareEdge : int
    {
        SE_A0 = 0,
        SE_B0,
        SE_C0,
        SE_D0,
        SE_E0,
        SE_F0,
        SE_G0,
        SE_H0,
        SE_I0,
        SE_J0,
        SE_A1,
        SE_B1,
        SE_C1,
        SE_D1,
        SE_E1,
        SE_F1,
        SE_G1,
        SE_H1,
        SE_I1,
        SE_J1,
        SE_A2,
        SE_B2,
        SE_C2,
        SE_D2,
        SE_E2,
        SE_F2,
        SE_G2,
        SE_H2,
        SE_I2,
        SE_J2,
        SE_A3,
        SE_B3,
        SE_C3,
        SE_D3,
        SE_E3,
        SE_F3,
        SE_G3,
        SE_H3,
        SE_I3,
        SE_J3,
        SE_A4,
        SE_B4,
        SE_C4,
        SE_D4,
        SE_E4,
        SE_F4,
        SE_G4,
        SE_H4,
        SE_I4,
        SE_J4,
        SE_A5,
        SE_B5,
        SE_C5,
        SE_D5,
        SE_E5,
        SE_F5,
        SE_G5,
        SE_H5,
        SE_I5,
        SE_J5,
        SE_A6,
        SE_B6,
        SE_C6,
        SE_D6,
        SE_E6,
        SE_F6,
        SE_G6,
        SE_H6,
        SE_I6,
        SE_J6,
        SE_A7,
        SE_B7,
        SE_C7,
        SE_D7,
        SE_E7,
        SE_F7,
        SE_G7,
        SE_H7,
        SE_I7,
        SE_J7,
        SE_A8,
        SE_B8,
        SE_C8,
        SE_D8,
        SE_E8,
        SE_F8,
        SE_G8,
        SE_H8,
        SE_I8,
        SE_J8,
        SE_A9,
        SE_B9,
        SE_C9,
        SE_D9,
        SE_E9,
        SE_F9,
        SE_G9,
        SE_H9,
        SE_I9,
        SE_J9,
        SELimit,
    };

    ActivateEnumOperation(SquareEdge);

    File GetFile(SquareEdge);
    Rank GetRank(SquareEdge);

    // Square

    enum Square : int
    {
        SquareInvalid = -1,
        NumberOfSquare = 81,
    };

    Square MakeSquare(SquareEdge, SquareEdge);

    ActivateEnumOperation(Square);

    // Fence

    enum Fence : int
    {
        FenceInvalid = -1,
        NumberOfFence = 128,
    };

    Fence MakeFence(SquareEdge, SquareEdge);

    ActivateEnumOperation(Fence);

    WallDir GetWallDir(Fence);

    // Move

    enum Move : int
    {
        MoveInvalid = -1,
        NumberOfMove = 209,
    };

    Move MakeMove(SquareEdge, SquareEdge);

    ActivateEnumOperation(Move);

    bool IsKingMove(Move);
    bool IsFenceMove(Move);

    // casting functions

    Move CastToMove(Square);
    Move CastToMove(Fence);
    Square CastToSquare(Move);
    Fence CastToFence(Move);

    /**
     * @brief make objects expressed by two SquareEdge objects forcibily, no error will be detected.
     * @note follow the rule that se1 should be less than se2
     *
     * @tparam Type
     * @param se1 should be less than se2
     * @param se2
     * @return Type
     */
    template <typename Type>
    Type MakeObjectForce(SquareEdge se1, SquareEdge se2)
    {
        return Type(se1 + (se2 << 8));
    }

    /**
     * @brief extract lower one of SquareEdge objects structuring Move.
     */
    SquareEdge ExtractSquareEdgeLower(Move);
    /**
     * @brief extract upper one of SquareEdge objects strcuturing Move.
     */
    SquareEdge ExtractSquareEdgeUpper(Move);
}
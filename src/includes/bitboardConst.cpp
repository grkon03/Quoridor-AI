#include "bitboardConst.hpp"
#include "indexer/IndexerAllIncludes.hpp"

namespace QuoridorAI::Constant
{
    namespace
    {
        Bitboard96 _1 = 1;
    }

    const Bitboard96 oneBitMask96[96] = {
        _1 << 0,
        _1 << 1,
        _1 << 2,
        _1 << 3,
        _1 << 4,
        _1 << 5,
        _1 << 6,
        _1 << 7,
        _1 << 8,
        _1 << 9,
        _1 << 10,
        _1 << 11,
        _1 << 12,
        _1 << 13,
        _1 << 14,
        _1 << 15,
        _1 << 16,
        _1 << 17,
        _1 << 18,
        _1 << 19,
        _1 << 20,
        _1 << 21,
        _1 << 22,
        _1 << 23,
        _1 << 24,
        _1 << 25,
        _1 << 26,
        _1 << 27,
        _1 << 28,
        _1 << 29,
        _1 << 30,
        _1 << 31,
        _1 << 32,
        _1 << 33,
        _1 << 34,
        _1 << 35,
        _1 << 36,
        _1 << 37,
        _1 << 38,
        _1 << 39,
        _1 << 40,
        _1 << 41,
        _1 << 42,
        _1 << 43,
        _1 << 44,
        _1 << 45,
        _1 << 46,
        _1 << 47,
        _1 << 48,
        _1 << 49,
        _1 << 50,
        _1 << 51,
        _1 << 52,
        _1 << 53,
        _1 << 54,
        _1 << 55,
        _1 << 56,
        _1 << 57,
        _1 << 58,
        _1 << 59,
        _1 << 60,
        _1 << 61,
        _1 << 62,
        _1 << 63,
        _1 << 64,
        _1 << 65,
        _1 << 66,
        _1 << 67,
        _1 << 68,
        _1 << 69,
        _1 << 70,
        _1 << 71,
        _1 << 72,
        _1 << 73,
        _1 << 74,
        _1 << 75,
        _1 << 76,
        _1 << 77,
        _1 << 78,
        _1 << 79,
        _1 << 80,
        _1 << 81,
        _1 << 82,
        _1 << 83,
        _1 << 84,
        _1 << 85,
        _1 << 86,
        _1 << 87,
        _1 << 88,
        _1 << 89,
        _1 << 90,
        _1 << 91,
        _1 << 92,
        _1 << 93,
        _1 << 94,
        _1 << 95,
    };

    const Bitboard96 fenceMaskByIndex[NumberOfFence] = {
        // vertical

        oneBitMask96[0] | oneBitMask96[8],
        oneBitMask96[1] | oneBitMask96[9],
        oneBitMask96[2] | oneBitMask96[10],
        oneBitMask96[3] | oneBitMask96[11],
        oneBitMask96[4] | oneBitMask96[12],
        oneBitMask96[5] | oneBitMask96[13],
        oneBitMask96[6] | oneBitMask96[14],
        oneBitMask96[7] | oneBitMask96[15],
        oneBitMask96[8] | oneBitMask96[16],
        oneBitMask96[9] | oneBitMask96[17],
        oneBitMask96[10] | oneBitMask96[18],
        oneBitMask96[11] | oneBitMask96[19],
        oneBitMask96[12] | oneBitMask96[20],
        oneBitMask96[13] | oneBitMask96[21],
        oneBitMask96[14] | oneBitMask96[22],
        oneBitMask96[15] | oneBitMask96[23],
        oneBitMask96[16] | oneBitMask96[24],
        oneBitMask96[17] | oneBitMask96[25],
        oneBitMask96[18] | oneBitMask96[26],
        oneBitMask96[19] | oneBitMask96[27],
        oneBitMask96[20] | oneBitMask96[28],
        oneBitMask96[21] | oneBitMask96[29],
        oneBitMask96[22] | oneBitMask96[30],
        oneBitMask96[23] | oneBitMask96[31],
        oneBitMask96[24] | oneBitMask96[32],
        oneBitMask96[25] | oneBitMask96[33],
        oneBitMask96[26] | oneBitMask96[34],
        oneBitMask96[27] | oneBitMask96[35],
        oneBitMask96[28] | oneBitMask96[36],
        oneBitMask96[29] | oneBitMask96[37],
        oneBitMask96[30] | oneBitMask96[38],
        oneBitMask96[31] | oneBitMask96[39],
        oneBitMask96[32] | oneBitMask96[40],
        oneBitMask96[33] | oneBitMask96[41],
        oneBitMask96[34] | oneBitMask96[42],
        oneBitMask96[35] | oneBitMask96[43],
        oneBitMask96[36] | oneBitMask96[44],
        oneBitMask96[37] | oneBitMask96[45],
        oneBitMask96[38] | oneBitMask96[46],
        oneBitMask96[39] | oneBitMask96[47],
        oneBitMask96[40] | oneBitMask96[48],
        oneBitMask96[41] | oneBitMask96[49],
        oneBitMask96[42] | oneBitMask96[40],
        oneBitMask96[43] | oneBitMask96[51],
        oneBitMask96[44] | oneBitMask96[52],
        oneBitMask96[45] | oneBitMask96[53],
        oneBitMask96[46] | oneBitMask96[54],
        oneBitMask96[47] | oneBitMask96[55],
        oneBitMask96[48] | oneBitMask96[56],
        oneBitMask96[49] | oneBitMask96[57],
        oneBitMask96[50] | oneBitMask96[58],
        oneBitMask96[51] | oneBitMask96[59],
        oneBitMask96[52] | oneBitMask96[60],
        oneBitMask96[53] | oneBitMask96[61],
        oneBitMask96[54] | oneBitMask96[62],
        oneBitMask96[55] | oneBitMask96[63],
        oneBitMask96[56] | oneBitMask96[64],
        oneBitMask96[57] | oneBitMask96[65],
        oneBitMask96[58] | oneBitMask96[66],
        oneBitMask96[59] | oneBitMask96[67],
        oneBitMask96[60] | oneBitMask96[68],
        oneBitMask96[61] | oneBitMask96[69],
        oneBitMask96[62] | oneBitMask96[70],
        oneBitMask96[63] | oneBitMask96[71],

        // horizontal

        oneBitMask96[0] | oneBitMask96[1],
        oneBitMask96[1] | oneBitMask96[2],
        oneBitMask96[2] | oneBitMask96[3],
        oneBitMask96[3] | oneBitMask96[4],
        oneBitMask96[4] | oneBitMask96[5],
        oneBitMask96[5] | oneBitMask96[6],
        oneBitMask96[6] | oneBitMask96[7],
        oneBitMask96[7] | oneBitMask96[8],
        oneBitMask96[9] | oneBitMask96[10],
        oneBitMask96[10] | oneBitMask96[11],
        oneBitMask96[11] | oneBitMask96[12],
        oneBitMask96[12] | oneBitMask96[13],
        oneBitMask96[13] | oneBitMask96[14],
        oneBitMask96[14] | oneBitMask96[15],
        oneBitMask96[15] | oneBitMask96[16],
        oneBitMask96[16] | oneBitMask96[17],
        oneBitMask96[18] | oneBitMask96[19],
        oneBitMask96[19] | oneBitMask96[20],
        oneBitMask96[20] | oneBitMask96[21],
        oneBitMask96[21] | oneBitMask96[22],
        oneBitMask96[22] | oneBitMask96[23],
        oneBitMask96[23] | oneBitMask96[24],
        oneBitMask96[24] | oneBitMask96[25],
        oneBitMask96[25] | oneBitMask96[26],
        oneBitMask96[27] | oneBitMask96[28],
        oneBitMask96[28] | oneBitMask96[29],
        oneBitMask96[29] | oneBitMask96[30],
        oneBitMask96[30] | oneBitMask96[31],
        oneBitMask96[31] | oneBitMask96[32],
        oneBitMask96[32] | oneBitMask96[33],
        oneBitMask96[33] | oneBitMask96[34],
        oneBitMask96[34] | oneBitMask96[35],
        oneBitMask96[36] | oneBitMask96[37],
        oneBitMask96[37] | oneBitMask96[38],
        oneBitMask96[38] | oneBitMask96[39],
        oneBitMask96[39] | oneBitMask96[40],
        oneBitMask96[40] | oneBitMask96[41],
        oneBitMask96[41] | oneBitMask96[42],
        oneBitMask96[42] | oneBitMask96[43],
        oneBitMask96[43] | oneBitMask96[44],
        oneBitMask96[45] | oneBitMask96[46],
        oneBitMask96[46] | oneBitMask96[47],
        oneBitMask96[47] | oneBitMask96[48],
        oneBitMask96[48] | oneBitMask96[49],
        oneBitMask96[49] | oneBitMask96[50],
        oneBitMask96[50] | oneBitMask96[51],
        oneBitMask96[51] | oneBitMask96[52],
        oneBitMask96[52] | oneBitMask96[53],
        oneBitMask96[54] | oneBitMask96[55],
        oneBitMask96[55] | oneBitMask96[56],
        oneBitMask96[56] | oneBitMask96[57],
        oneBitMask96[57] | oneBitMask96[58],
        oneBitMask96[58] | oneBitMask96[59],
        oneBitMask96[59] | oneBitMask96[60],
        oneBitMask96[60] | oneBitMask96[61],
        oneBitMask96[61] | oneBitMask96[62],
        oneBitMask96[63] | oneBitMask96[64],
        oneBitMask96[64] | oneBitMask96[65],
        oneBitMask96[65] | oneBitMask96[66],
        oneBitMask96[66] | oneBitMask96[67],
        oneBitMask96[67] | oneBitMask96[68],
        oneBitMask96[68] | oneBitMask96[69],
        oneBitMask96[69] | oneBitMask96[70],
        oneBitMask96[70] | oneBitMask96[71],
    };

    namespace
    {
        Map<Fence, Bitboard96> __fenceMaskByFence()
        {
            Map<Fence, Bitboard96> ret;

            SquareEdge se;
            Fence fence;

            // vertical
            for (se = SE_B0; se <= SE_I7; ++se)
            {
                fence = MakeFence(se, se + 20);
                if (fence != FenceInvalid)
                    ret[fence] = fenceMaskByIndex[Indexer::FenceToIndex(fence)];
            }

            // horizontal
            for (se = SE_A1; se <= SE_H8; ++se)
            {
                fence = MakeFence(se, se + 2);
                if (fence != FenceInvalid)
                {
                    ret[fence] = fenceMaskByIndex[Indexer::FenceToIndex(fence)];
                }
            }

            return ret;
        }

        Map<SquareEdge, Bitboard96> __fenceMaskBySquareEdge__V()
        {
            Map<SquareEdge, Bitboard96> ret;
            SquareEdge se;
            Fence fence;

            for (se = SE_B0; se <= SE_I7; ++se)
            {
                fence = MakeFence(se, se + 20);
                if (fence != FenceInvalid)
                    ret[se] = fenceMaskByIndex[Indexer::FenceToIndex(fence)];
            }

            return ret;
        }

        Map<SquareEdge, Bitboard96> __fenceMaskBySquareEdge__H()
        {
            Map<SquareEdge, Bitboard96> ret;
            SquareEdge se;
            Fence fence;

            for (se = SE_A1; se <= SE_H8; ++se)
            {
                fence = MakeFence(se, se + 2);
                if (fence != FenceInvalid)
                    ret[se] = fenceMaskByIndex[Indexer::FenceToIndex(fence)];
            }

            return ret;
        }
    }

    const Map<Fence, Bitboard96> fenceMaskByFence = __fenceMaskByFence();
    const Map<SquareEdge, Bitboard96> fenceMaskBySquareEdge[WallDirLimit] = {
        __fenceMaskBySquareEdge__V(),
        __fenceMaskBySquareEdge__H(),
    };

    const Bitboard64 availableFenceRemainMaskByIndex[NumberOfFence] = {
        // vertical

        ~(misc::oneBitMask64[0] | misc::oneBitMask64[8]),
        ~(misc::oneBitMask64[1] | misc::oneBitMask64[9]),
        ~(misc::oneBitMask64[2] | misc::oneBitMask64[10]),
        ~(misc::oneBitMask64[3] | misc::oneBitMask64[11]),
        ~(misc::oneBitMask64[4] | misc::oneBitMask64[12]),
        ~(misc::oneBitMask64[5] | misc::oneBitMask64[13]),
        ~(misc::oneBitMask64[6] | misc::oneBitMask64[14]),
        ~(misc::oneBitMask64[7] | misc::oneBitMask64[15]),
        ~(misc::oneBitMask64[0] | misc::oneBitMask64[8] | misc::oneBitMask64[16]),
        ~(misc::oneBitMask64[1] | misc::oneBitMask64[9] | misc::oneBitMask64[17]),
        ~(misc::oneBitMask64[2] | misc::oneBitMask64[10] | misc::oneBitMask64[18]),
        ~(misc::oneBitMask64[3] | misc::oneBitMask64[11] | misc::oneBitMask64[19]),
        ~(misc::oneBitMask64[4] | misc::oneBitMask64[12] | misc::oneBitMask64[20]),
        ~(misc::oneBitMask64[5] | misc::oneBitMask64[13] | misc::oneBitMask64[21]),
        ~(misc::oneBitMask64[6] | misc::oneBitMask64[14] | misc::oneBitMask64[22]),
        ~(misc::oneBitMask64[7] | misc::oneBitMask64[15] | misc::oneBitMask64[23]),
        ~(misc::oneBitMask64[8] | misc::oneBitMask64[16] | misc::oneBitMask64[24]),
        ~(misc::oneBitMask64[9] | misc::oneBitMask64[17] | misc::oneBitMask64[25]),
        ~(misc::oneBitMask64[10] | misc::oneBitMask64[18] | misc::oneBitMask64[26]),
        ~(misc::oneBitMask64[11] | misc::oneBitMask64[19] | misc::oneBitMask64[27]),
        ~(misc::oneBitMask64[12] | misc::oneBitMask64[20] | misc::oneBitMask64[28]),
        ~(misc::oneBitMask64[13] | misc::oneBitMask64[21] | misc::oneBitMask64[29]),
        ~(misc::oneBitMask64[14] | misc::oneBitMask64[22] | misc::oneBitMask64[30]),
        ~(misc::oneBitMask64[15] | misc::oneBitMask64[23] | misc::oneBitMask64[31]),
        ~(misc::oneBitMask64[16] | misc::oneBitMask64[24] | misc::oneBitMask64[32]),
        ~(misc::oneBitMask64[17] | misc::oneBitMask64[25] | misc::oneBitMask64[33]),
        ~(misc::oneBitMask64[18] | misc::oneBitMask64[26] | misc::oneBitMask64[34]),
        ~(misc::oneBitMask64[19] | misc::oneBitMask64[27] | misc::oneBitMask64[35]),
        ~(misc::oneBitMask64[20] | misc::oneBitMask64[28] | misc::oneBitMask64[36]),
        ~(misc::oneBitMask64[21] | misc::oneBitMask64[29] | misc::oneBitMask64[37]),
        ~(misc::oneBitMask64[22] | misc::oneBitMask64[30] | misc::oneBitMask64[38]),
        ~(misc::oneBitMask64[23] | misc::oneBitMask64[31] | misc::oneBitMask64[39]),
        ~(misc::oneBitMask64[24] | misc::oneBitMask64[32] | misc::oneBitMask64[40]),
        ~(misc::oneBitMask64[25] | misc::oneBitMask64[33] | misc::oneBitMask64[41]),
        ~(misc::oneBitMask64[26] | misc::oneBitMask64[34] | misc::oneBitMask64[42]),
        ~(misc::oneBitMask64[27] | misc::oneBitMask64[35] | misc::oneBitMask64[43]),
        ~(misc::oneBitMask64[28] | misc::oneBitMask64[36] | misc::oneBitMask64[44]),
        ~(misc::oneBitMask64[29] | misc::oneBitMask64[37] | misc::oneBitMask64[45]),
        ~(misc::oneBitMask64[30] | misc::oneBitMask64[38] | misc::oneBitMask64[46]),
        ~(misc::oneBitMask64[31] | misc::oneBitMask64[39] | misc::oneBitMask64[47]),
        ~(misc::oneBitMask64[32] | misc::oneBitMask64[40] | misc::oneBitMask64[48]),
        ~(misc::oneBitMask64[33] | misc::oneBitMask64[41] | misc::oneBitMask64[49]),
        ~(misc::oneBitMask64[34] | misc::oneBitMask64[42] | misc::oneBitMask64[50]),
        ~(misc::oneBitMask64[35] | misc::oneBitMask64[43] | misc::oneBitMask64[51]),
        ~(misc::oneBitMask64[36] | misc::oneBitMask64[44] | misc::oneBitMask64[52]),
        ~(misc::oneBitMask64[37] | misc::oneBitMask64[45] | misc::oneBitMask64[53]),
        ~(misc::oneBitMask64[38] | misc::oneBitMask64[46] | misc::oneBitMask64[54]),
        ~(misc::oneBitMask64[39] | misc::oneBitMask64[47] | misc::oneBitMask64[55]),
        ~(misc::oneBitMask64[40] | misc::oneBitMask64[48] | misc::oneBitMask64[56]),
        ~(misc::oneBitMask64[41] | misc::oneBitMask64[49] | misc::oneBitMask64[57]),
        ~(misc::oneBitMask64[42] | misc::oneBitMask64[50] | misc::oneBitMask64[58]),
        ~(misc::oneBitMask64[43] | misc::oneBitMask64[51] | misc::oneBitMask64[59]),
        ~(misc::oneBitMask64[44] | misc::oneBitMask64[52] | misc::oneBitMask64[60]),
        ~(misc::oneBitMask64[45] | misc::oneBitMask64[53] | misc::oneBitMask64[61]),
        ~(misc::oneBitMask64[46] | misc::oneBitMask64[54] | misc::oneBitMask64[62]),
        ~(misc::oneBitMask64[47] | misc::oneBitMask64[55] | misc::oneBitMask64[63]),
        ~(misc::oneBitMask64[48] | misc::oneBitMask64[56]),
        ~(misc::oneBitMask64[49] | misc::oneBitMask64[57]),
        ~(misc::oneBitMask64[50] | misc::oneBitMask64[58]),
        ~(misc::oneBitMask64[51] | misc::oneBitMask64[59]),
        ~(misc::oneBitMask64[52] | misc::oneBitMask64[60]),
        ~(misc::oneBitMask64[53] | misc::oneBitMask64[61]),
        ~(misc::oneBitMask64[54] | misc::oneBitMask64[62]),
        ~(misc::oneBitMask64[55] | misc::oneBitMask64[63]),

        // horizontal

        ~(misc::oneBitMask64[0] | misc::oneBitMask64[1]),
        ~(misc::oneBitMask64[0] | misc::oneBitMask64[1] | misc::oneBitMask64[2]),
        ~(misc::oneBitMask64[1] | misc::oneBitMask64[2] | misc::oneBitMask64[3]),
        ~(misc::oneBitMask64[2] | misc::oneBitMask64[3] | misc::oneBitMask64[4]),
        ~(misc::oneBitMask64[3] | misc::oneBitMask64[4] | misc::oneBitMask64[5]),
        ~(misc::oneBitMask64[4] | misc::oneBitMask64[5] | misc::oneBitMask64[6]),
        ~(misc::oneBitMask64[5] | misc::oneBitMask64[6] | misc::oneBitMask64[7]),
        ~(misc::oneBitMask64[6] | misc::oneBitMask64[7]),
        ~(misc::oneBitMask64[8] | misc::oneBitMask64[9]),
        ~(misc::oneBitMask64[8] | misc::oneBitMask64[9] | misc::oneBitMask64[10]),
        ~(misc::oneBitMask64[9] | misc::oneBitMask64[10] | misc::oneBitMask64[11]),
        ~(misc::oneBitMask64[10] | misc::oneBitMask64[11] | misc::oneBitMask64[12]),
        ~(misc::oneBitMask64[11] | misc::oneBitMask64[12] | misc::oneBitMask64[13]),
        ~(misc::oneBitMask64[12] | misc::oneBitMask64[13] | misc::oneBitMask64[14]),
        ~(misc::oneBitMask64[13] | misc::oneBitMask64[14] | misc::oneBitMask64[15]),
        ~(misc::oneBitMask64[14] | misc::oneBitMask64[15]),
        ~(misc::oneBitMask64[16] | misc::oneBitMask64[17]),
        ~(misc::oneBitMask64[16] | misc::oneBitMask64[17] | misc::oneBitMask64[18]),
        ~(misc::oneBitMask64[17] | misc::oneBitMask64[18] | misc::oneBitMask64[19]),
        ~(misc::oneBitMask64[18] | misc::oneBitMask64[19] | misc::oneBitMask64[20]),
        ~(misc::oneBitMask64[19] | misc::oneBitMask64[20] | misc::oneBitMask64[21]),
        ~(misc::oneBitMask64[20] | misc::oneBitMask64[21] | misc::oneBitMask64[22]),
        ~(misc::oneBitMask64[21] | misc::oneBitMask64[22] | misc::oneBitMask64[23]),
        ~(misc::oneBitMask64[22] | misc::oneBitMask64[23]),
        ~(misc::oneBitMask64[24] | misc::oneBitMask64[25]),
        ~(misc::oneBitMask64[24] | misc::oneBitMask64[25] | misc::oneBitMask64[26]),
        ~(misc::oneBitMask64[25] | misc::oneBitMask64[26] | misc::oneBitMask64[27]),
        ~(misc::oneBitMask64[26] | misc::oneBitMask64[27] | misc::oneBitMask64[28]),
        ~(misc::oneBitMask64[27] | misc::oneBitMask64[28] | misc::oneBitMask64[29]),
        ~(misc::oneBitMask64[28] | misc::oneBitMask64[29] | misc::oneBitMask64[30]),
        ~(misc::oneBitMask64[29] | misc::oneBitMask64[30] | misc::oneBitMask64[31]),
        ~(misc::oneBitMask64[30] | misc::oneBitMask64[31]),
        ~(misc::oneBitMask64[32] | misc::oneBitMask64[33]),
        ~(misc::oneBitMask64[32] | misc::oneBitMask64[33] | misc::oneBitMask64[34]),
        ~(misc::oneBitMask64[33] | misc::oneBitMask64[34] | misc::oneBitMask64[35]),
        ~(misc::oneBitMask64[34] | misc::oneBitMask64[35] | misc::oneBitMask64[36]),
        ~(misc::oneBitMask64[35] | misc::oneBitMask64[36] | misc::oneBitMask64[37]),
        ~(misc::oneBitMask64[36] | misc::oneBitMask64[37] | misc::oneBitMask64[38]),
        ~(misc::oneBitMask64[37] | misc::oneBitMask64[38] | misc::oneBitMask64[39]),
        ~(misc::oneBitMask64[38] | misc::oneBitMask64[39]),
        ~(misc::oneBitMask64[40] | misc::oneBitMask64[41]),
        ~(misc::oneBitMask64[40] | misc::oneBitMask64[41] | misc::oneBitMask64[42]),
        ~(misc::oneBitMask64[41] | misc::oneBitMask64[42] | misc::oneBitMask64[43]),
        ~(misc::oneBitMask64[42] | misc::oneBitMask64[43] | misc::oneBitMask64[44]),
        ~(misc::oneBitMask64[43] | misc::oneBitMask64[44] | misc::oneBitMask64[45]),
        ~(misc::oneBitMask64[44] | misc::oneBitMask64[45] | misc::oneBitMask64[46]),
        ~(misc::oneBitMask64[45] | misc::oneBitMask64[46] | misc::oneBitMask64[47]),
        ~(misc::oneBitMask64[46] | misc::oneBitMask64[47]),
        ~(misc::oneBitMask64[48] | misc::oneBitMask64[49]),
        ~(misc::oneBitMask64[48] | misc::oneBitMask64[49] | misc::oneBitMask64[50]),
        ~(misc::oneBitMask64[49] | misc::oneBitMask64[50] | misc::oneBitMask64[51]),
        ~(misc::oneBitMask64[50] | misc::oneBitMask64[51] | misc::oneBitMask64[52]),
        ~(misc::oneBitMask64[51] | misc::oneBitMask64[52] | misc::oneBitMask64[53]),
        ~(misc::oneBitMask64[52] | misc::oneBitMask64[53] | misc::oneBitMask64[54]),
        ~(misc::oneBitMask64[53] | misc::oneBitMask64[54] | misc::oneBitMask64[55]),
        ~(misc::oneBitMask64[54] | misc::oneBitMask64[55]),
        ~(misc::oneBitMask64[56] | misc::oneBitMask64[57]),
        ~(misc::oneBitMask64[56] | misc::oneBitMask64[57] | misc::oneBitMask64[58]),
        ~(misc::oneBitMask64[57] | misc::oneBitMask64[58] | misc::oneBitMask64[59]),
        ~(misc::oneBitMask64[58] | misc::oneBitMask64[59] | misc::oneBitMask64[60]),
        ~(misc::oneBitMask64[59] | misc::oneBitMask64[60] | misc::oneBitMask64[61]),
        ~(misc::oneBitMask64[60] | misc::oneBitMask64[61] | misc::oneBitMask64[62]),
        ~(misc::oneBitMask64[61] | misc::oneBitMask64[62] | misc::oneBitMask64[63]),
        ~(misc::oneBitMask64[62] | misc::oneBitMask64[63]),
    };

    namespace
    {

        Map<SquareEdge, Bitboard64> __availableFenceRemainMaskBySquareEdge__V()
        {
            Map<SquareEdge, Bitboard64> ret;
            SquareEdge se;
            Fence fence;

            for (se = SE_B0; se <= SE_I7; ++se)
            {
                fence = MakeFence(se, se + 20);
                if (fence != FenceInvalid)
                    ret[se] = availableFenceRemainMaskByIndex[Indexer::FenceToIndex(fence)];
            }

            return ret;
        }

        Map<SquareEdge, Bitboard64> __availableFenceRemainMaskBySquareEdge__H()
        {
            Map<SquareEdge, Bitboard64> ret;
            SquareEdge se;
            Fence fence;

            for (se = SE_A1; se <= SE_H8; ++se)
            {
                fence = MakeFence(se, se + 2);
                if (fence != FenceInvalid)
                    ret[se] = availableFenceRemainMaskByIndex[Indexer::FenceToIndex(fence)];
            }

            return ret;
        }
    }

    const Map<SquareEdge, Bitboard64> availableFenceRemainMaskBySquareEdge[WallDirLimit] = {
        __availableFenceRemainMaskBySquareEdge__V(),
        __availableFenceRemainMaskBySquareEdge__H(),
    };
}
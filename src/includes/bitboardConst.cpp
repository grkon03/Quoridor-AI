#include "bitboardConst.hpp"
#include "indexer/IndexerAllIncludes.hpp"

namespace QuoridorAI::Constant
{
    namespace
    {
        Bitboard128 _1 = 1;
    }

    const Bitboard128 oneBitMask128[128] = {
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
        _1 << 96,
        _1 << 97,
        _1 << 98,
        _1 << 99,
        _1 << 100,
        _1 << 101,
        _1 << 102,
        _1 << 103,
        _1 << 104,
        _1 << 105,
        _1 << 106,
        _1 << 107,
        _1 << 108,
        _1 << 109,
        _1 << 110,
        _1 << 111,
        _1 << 112,
        _1 << 113,
        _1 << 114,
        _1 << 115,
        _1 << 116,
        _1 << 117,
        _1 << 118,
        _1 << 119,
        _1 << 120,
        _1 << 121,
        _1 << 122,
        _1 << 123,
        _1 << 124,
        _1 << 125,
        _1 << 126,
        _1 << 127,
    };

    const Bitboard128 fenceMaskByIndex[NumberOfFence] = {
        // vertical

        oneBitMask128[0] | oneBitMask128[8],
        oneBitMask128[1] | oneBitMask128[9],
        oneBitMask128[2] | oneBitMask128[10],
        oneBitMask128[3] | oneBitMask128[11],
        oneBitMask128[4] | oneBitMask128[12],
        oneBitMask128[5] | oneBitMask128[13],
        oneBitMask128[6] | oneBitMask128[14],
        oneBitMask128[7] | oneBitMask128[15],
        oneBitMask128[8] | oneBitMask128[16],
        oneBitMask128[9] | oneBitMask128[17],
        oneBitMask128[10] | oneBitMask128[18],
        oneBitMask128[11] | oneBitMask128[19],
        oneBitMask128[12] | oneBitMask128[20],
        oneBitMask128[13] | oneBitMask128[21],
        oneBitMask128[14] | oneBitMask128[22],
        oneBitMask128[15] | oneBitMask128[23],
        oneBitMask128[16] | oneBitMask128[24],
        oneBitMask128[17] | oneBitMask128[25],
        oneBitMask128[18] | oneBitMask128[26],
        oneBitMask128[19] | oneBitMask128[27],
        oneBitMask128[20] | oneBitMask128[28],
        oneBitMask128[21] | oneBitMask128[29],
        oneBitMask128[22] | oneBitMask128[30],
        oneBitMask128[23] | oneBitMask128[31],
        oneBitMask128[24] | oneBitMask128[32],
        oneBitMask128[25] | oneBitMask128[33],
        oneBitMask128[26] | oneBitMask128[34],
        oneBitMask128[27] | oneBitMask128[35],
        oneBitMask128[28] | oneBitMask128[36],
        oneBitMask128[29] | oneBitMask128[37],
        oneBitMask128[30] | oneBitMask128[38],
        oneBitMask128[31] | oneBitMask128[39],
        oneBitMask128[32] | oneBitMask128[40],
        oneBitMask128[33] | oneBitMask128[41],
        oneBitMask128[34] | oneBitMask128[42],
        oneBitMask128[35] | oneBitMask128[43],
        oneBitMask128[36] | oneBitMask128[44],
        oneBitMask128[37] | oneBitMask128[45],
        oneBitMask128[38] | oneBitMask128[46],
        oneBitMask128[39] | oneBitMask128[47],
        oneBitMask128[40] | oneBitMask128[48],
        oneBitMask128[41] | oneBitMask128[49],
        oneBitMask128[42] | oneBitMask128[50],
        oneBitMask128[43] | oneBitMask128[51],
        oneBitMask128[44] | oneBitMask128[52],
        oneBitMask128[45] | oneBitMask128[53],
        oneBitMask128[46] | oneBitMask128[54],
        oneBitMask128[47] | oneBitMask128[55],
        oneBitMask128[48] | oneBitMask128[56],
        oneBitMask128[49] | oneBitMask128[57],
        oneBitMask128[50] | oneBitMask128[58],
        oneBitMask128[51] | oneBitMask128[59],
        oneBitMask128[52] | oneBitMask128[60],
        oneBitMask128[53] | oneBitMask128[61],
        oneBitMask128[54] | oneBitMask128[62],
        oneBitMask128[55] | oneBitMask128[63],
        oneBitMask128[56] | oneBitMask128[64],
        oneBitMask128[57] | oneBitMask128[65],
        oneBitMask128[58] | oneBitMask128[66],
        oneBitMask128[59] | oneBitMask128[67],
        oneBitMask128[60] | oneBitMask128[68],
        oneBitMask128[61] | oneBitMask128[69],
        oneBitMask128[62] | oneBitMask128[70],
        oneBitMask128[63] | oneBitMask128[71],

        // horizontal

        oneBitMask128[0] | oneBitMask128[1],
        oneBitMask128[1] | oneBitMask128[2],
        oneBitMask128[2] | oneBitMask128[3],
        oneBitMask128[3] | oneBitMask128[4],
        oneBitMask128[4] | oneBitMask128[5],
        oneBitMask128[5] | oneBitMask128[6],
        oneBitMask128[6] | oneBitMask128[7],
        oneBitMask128[7] | oneBitMask128[8],
        oneBitMask128[9] | oneBitMask128[10],
        oneBitMask128[10] | oneBitMask128[11],
        oneBitMask128[11] | oneBitMask128[12],
        oneBitMask128[12] | oneBitMask128[13],
        oneBitMask128[13] | oneBitMask128[14],
        oneBitMask128[14] | oneBitMask128[15],
        oneBitMask128[15] | oneBitMask128[16],
        oneBitMask128[16] | oneBitMask128[17],
        oneBitMask128[18] | oneBitMask128[19],
        oneBitMask128[19] | oneBitMask128[20],
        oneBitMask128[20] | oneBitMask128[21],
        oneBitMask128[21] | oneBitMask128[22],
        oneBitMask128[22] | oneBitMask128[23],
        oneBitMask128[23] | oneBitMask128[24],
        oneBitMask128[24] | oneBitMask128[25],
        oneBitMask128[25] | oneBitMask128[26],
        oneBitMask128[27] | oneBitMask128[28],
        oneBitMask128[28] | oneBitMask128[29],
        oneBitMask128[29] | oneBitMask128[30],
        oneBitMask128[30] | oneBitMask128[31],
        oneBitMask128[31] | oneBitMask128[32],
        oneBitMask128[32] | oneBitMask128[33],
        oneBitMask128[33] | oneBitMask128[34],
        oneBitMask128[34] | oneBitMask128[35],
        oneBitMask128[36] | oneBitMask128[37],
        oneBitMask128[37] | oneBitMask128[38],
        oneBitMask128[38] | oneBitMask128[39],
        oneBitMask128[39] | oneBitMask128[40],
        oneBitMask128[40] | oneBitMask128[41],
        oneBitMask128[41] | oneBitMask128[42],
        oneBitMask128[42] | oneBitMask128[43],
        oneBitMask128[43] | oneBitMask128[44],
        oneBitMask128[45] | oneBitMask128[46],
        oneBitMask128[46] | oneBitMask128[47],
        oneBitMask128[47] | oneBitMask128[48],
        oneBitMask128[48] | oneBitMask128[49],
        oneBitMask128[49] | oneBitMask128[50],
        oneBitMask128[50] | oneBitMask128[51],
        oneBitMask128[51] | oneBitMask128[52],
        oneBitMask128[52] | oneBitMask128[53],
        oneBitMask128[54] | oneBitMask128[55],
        oneBitMask128[55] | oneBitMask128[56],
        oneBitMask128[56] | oneBitMask128[57],
        oneBitMask128[57] | oneBitMask128[58],
        oneBitMask128[58] | oneBitMask128[59],
        oneBitMask128[59] | oneBitMask128[60],
        oneBitMask128[60] | oneBitMask128[61],
        oneBitMask128[61] | oneBitMask128[62],
        oneBitMask128[63] | oneBitMask128[64],
        oneBitMask128[64] | oneBitMask128[65],
        oneBitMask128[65] | oneBitMask128[66],
        oneBitMask128[66] | oneBitMask128[67],
        oneBitMask128[67] | oneBitMask128[68],
        oneBitMask128[68] | oneBitMask128[69],
        oneBitMask128[69] | oneBitMask128[70],
        oneBitMask128[70] | oneBitMask128[71],
    };

    namespace
    {
        Map<Fence, Bitboard128> __fenceMaskByFence()
        {
            Map<Fence, Bitboard128> ret;

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

        Map<SquareEdge, Bitboard128> __fenceMaskBySquareEdge__V()
        {
            Map<SquareEdge, Bitboard128> ret;
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

        Map<SquareEdge, Bitboard128> __fenceMaskBySquareEdge__H()
        {
            Map<SquareEdge, Bitboard128> ret;
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

    const Map<Fence, Bitboard128> fenceMaskByFence = __fenceMaskByFence();
    const Map<SquareEdge, Bitboard128> fenceMaskBySquareEdge[WallDirLimit] = {
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

    const Bitboard128 usedSquareEdgeByFenceBB[NumberOfFence] = {
        // vertical

        oneBitMask128[1] | oneBitMask128[11] | oneBitMask128[21],
        oneBitMask128[2] | oneBitMask128[12] | oneBitMask128[22],
        oneBitMask128[3] | oneBitMask128[13] | oneBitMask128[23],
        oneBitMask128[4] | oneBitMask128[14] | oneBitMask128[24],
        oneBitMask128[5] | oneBitMask128[15] | oneBitMask128[25],
        oneBitMask128[6] | oneBitMask128[16] | oneBitMask128[26],
        oneBitMask128[7] | oneBitMask128[17] | oneBitMask128[27],
        oneBitMask128[8] | oneBitMask128[18] | oneBitMask128[28],
        oneBitMask128[11] | oneBitMask128[21] | oneBitMask128[31],
        oneBitMask128[12] | oneBitMask128[22] | oneBitMask128[32],
        oneBitMask128[13] | oneBitMask128[23] | oneBitMask128[33],
        oneBitMask128[14] | oneBitMask128[24] | oneBitMask128[34],
        oneBitMask128[15] | oneBitMask128[25] | oneBitMask128[35],
        oneBitMask128[16] | oneBitMask128[26] | oneBitMask128[36],
        oneBitMask128[17] | oneBitMask128[27] | oneBitMask128[37],
        oneBitMask128[18] | oneBitMask128[28] | oneBitMask128[38],
        oneBitMask128[21] | oneBitMask128[31] | oneBitMask128[41],
        oneBitMask128[22] | oneBitMask128[32] | oneBitMask128[42],
        oneBitMask128[23] | oneBitMask128[33] | oneBitMask128[43],
        oneBitMask128[24] | oneBitMask128[34] | oneBitMask128[44],
        oneBitMask128[25] | oneBitMask128[35] | oneBitMask128[45],
        oneBitMask128[26] | oneBitMask128[36] | oneBitMask128[46],
        oneBitMask128[27] | oneBitMask128[37] | oneBitMask128[47],
        oneBitMask128[28] | oneBitMask128[38] | oneBitMask128[48],
        oneBitMask128[31] | oneBitMask128[41] | oneBitMask128[51],
        oneBitMask128[32] | oneBitMask128[42] | oneBitMask128[52],
        oneBitMask128[33] | oneBitMask128[43] | oneBitMask128[53],
        oneBitMask128[34] | oneBitMask128[44] | oneBitMask128[54],
        oneBitMask128[35] | oneBitMask128[45] | oneBitMask128[55],
        oneBitMask128[36] | oneBitMask128[46] | oneBitMask128[56],
        oneBitMask128[37] | oneBitMask128[47] | oneBitMask128[57],
        oneBitMask128[38] | oneBitMask128[48] | oneBitMask128[58],
        oneBitMask128[41] | oneBitMask128[51] | oneBitMask128[61],
        oneBitMask128[42] | oneBitMask128[52] | oneBitMask128[62],
        oneBitMask128[43] | oneBitMask128[53] | oneBitMask128[63],
        oneBitMask128[44] | oneBitMask128[54] | oneBitMask128[64],
        oneBitMask128[45] | oneBitMask128[55] | oneBitMask128[65],
        oneBitMask128[46] | oneBitMask128[56] | oneBitMask128[66],
        oneBitMask128[47] | oneBitMask128[57] | oneBitMask128[67],
        oneBitMask128[48] | oneBitMask128[58] | oneBitMask128[68],
        oneBitMask128[51] | oneBitMask128[61] | oneBitMask128[71],
        oneBitMask128[52] | oneBitMask128[62] | oneBitMask128[72],
        oneBitMask128[53] | oneBitMask128[63] | oneBitMask128[73],
        oneBitMask128[54] | oneBitMask128[64] | oneBitMask128[74],
        oneBitMask128[55] | oneBitMask128[65] | oneBitMask128[75],
        oneBitMask128[56] | oneBitMask128[66] | oneBitMask128[76],
        oneBitMask128[57] | oneBitMask128[67] | oneBitMask128[77],
        oneBitMask128[58] | oneBitMask128[68] | oneBitMask128[78],
        oneBitMask128[61] | oneBitMask128[71] | oneBitMask128[81],
        oneBitMask128[62] | oneBitMask128[72] | oneBitMask128[82],
        oneBitMask128[63] | oneBitMask128[73] | oneBitMask128[83],
        oneBitMask128[64] | oneBitMask128[74] | oneBitMask128[84],
        oneBitMask128[65] | oneBitMask128[75] | oneBitMask128[85],
        oneBitMask128[66] | oneBitMask128[76] | oneBitMask128[86],
        oneBitMask128[67] | oneBitMask128[77] | oneBitMask128[87],
        oneBitMask128[68] | oneBitMask128[78] | oneBitMask128[88],
        oneBitMask128[71] | oneBitMask128[81] | oneBitMask128[91],
        oneBitMask128[72] | oneBitMask128[82] | oneBitMask128[92],
        oneBitMask128[73] | oneBitMask128[83] | oneBitMask128[93],
        oneBitMask128[74] | oneBitMask128[84] | oneBitMask128[94],
        oneBitMask128[75] | oneBitMask128[85] | oneBitMask128[95],
        oneBitMask128[76] | oneBitMask128[86] | oneBitMask128[96],
        oneBitMask128[77] | oneBitMask128[87] | oneBitMask128[97],
        oneBitMask128[78] | oneBitMask128[88] | oneBitMask128[98],

        // horizontal

        oneBitMask128[10] | oneBitMask128[11] | oneBitMask128[12],
        oneBitMask128[11] | oneBitMask128[12] | oneBitMask128[13],
        oneBitMask128[12] | oneBitMask128[13] | oneBitMask128[14],
        oneBitMask128[13] | oneBitMask128[14] | oneBitMask128[15],
        oneBitMask128[14] | oneBitMask128[15] | oneBitMask128[16],
        oneBitMask128[15] | oneBitMask128[16] | oneBitMask128[17],
        oneBitMask128[16] | oneBitMask128[17] | oneBitMask128[18],
        oneBitMask128[17] | oneBitMask128[18] | oneBitMask128[19],
        oneBitMask128[20] | oneBitMask128[21] | oneBitMask128[22],
        oneBitMask128[21] | oneBitMask128[22] | oneBitMask128[23],
        oneBitMask128[22] | oneBitMask128[23] | oneBitMask128[24],
        oneBitMask128[23] | oneBitMask128[24] | oneBitMask128[25],
        oneBitMask128[24] | oneBitMask128[25] | oneBitMask128[26],
        oneBitMask128[25] | oneBitMask128[26] | oneBitMask128[27],
        oneBitMask128[26] | oneBitMask128[27] | oneBitMask128[28],
        oneBitMask128[27] | oneBitMask128[28] | oneBitMask128[29],
        oneBitMask128[30] | oneBitMask128[31] | oneBitMask128[32],
        oneBitMask128[31] | oneBitMask128[32] | oneBitMask128[33],
        oneBitMask128[32] | oneBitMask128[33] | oneBitMask128[34],
        oneBitMask128[33] | oneBitMask128[34] | oneBitMask128[35],
        oneBitMask128[34] | oneBitMask128[35] | oneBitMask128[36],
        oneBitMask128[35] | oneBitMask128[36] | oneBitMask128[37],
        oneBitMask128[36] | oneBitMask128[37] | oneBitMask128[38],
        oneBitMask128[37] | oneBitMask128[38] | oneBitMask128[39],
        oneBitMask128[40] | oneBitMask128[41] | oneBitMask128[42],
        oneBitMask128[41] | oneBitMask128[42] | oneBitMask128[43],
        oneBitMask128[42] | oneBitMask128[43] | oneBitMask128[44],
        oneBitMask128[43] | oneBitMask128[44] | oneBitMask128[45],
        oneBitMask128[44] | oneBitMask128[45] | oneBitMask128[46],
        oneBitMask128[45] | oneBitMask128[46] | oneBitMask128[47],
        oneBitMask128[46] | oneBitMask128[47] | oneBitMask128[48],
        oneBitMask128[47] | oneBitMask128[48] | oneBitMask128[49],
        oneBitMask128[50] | oneBitMask128[51] | oneBitMask128[52],
        oneBitMask128[51] | oneBitMask128[52] | oneBitMask128[53],
        oneBitMask128[52] | oneBitMask128[53] | oneBitMask128[54],
        oneBitMask128[53] | oneBitMask128[54] | oneBitMask128[55],
        oneBitMask128[54] | oneBitMask128[55] | oneBitMask128[56],
        oneBitMask128[55] | oneBitMask128[56] | oneBitMask128[57],
        oneBitMask128[56] | oneBitMask128[57] | oneBitMask128[58],
        oneBitMask128[57] | oneBitMask128[58] | oneBitMask128[59],
        oneBitMask128[60] | oneBitMask128[61] | oneBitMask128[62],
        oneBitMask128[61] | oneBitMask128[62] | oneBitMask128[63],
        oneBitMask128[62] | oneBitMask128[63] | oneBitMask128[64],
        oneBitMask128[63] | oneBitMask128[64] | oneBitMask128[65],
        oneBitMask128[64] | oneBitMask128[65] | oneBitMask128[66],
        oneBitMask128[65] | oneBitMask128[66] | oneBitMask128[67],
        oneBitMask128[66] | oneBitMask128[67] | oneBitMask128[68],
        oneBitMask128[67] | oneBitMask128[68] | oneBitMask128[69],
        oneBitMask128[70] | oneBitMask128[71] | oneBitMask128[72],
        oneBitMask128[71] | oneBitMask128[72] | oneBitMask128[73],
        oneBitMask128[72] | oneBitMask128[73] | oneBitMask128[74],
        oneBitMask128[73] | oneBitMask128[74] | oneBitMask128[75],
        oneBitMask128[74] | oneBitMask128[75] | oneBitMask128[76],
        oneBitMask128[75] | oneBitMask128[76] | oneBitMask128[77],
        oneBitMask128[76] | oneBitMask128[77] | oneBitMask128[78],
        oneBitMask128[77] | oneBitMask128[78] | oneBitMask128[79],
        oneBitMask128[80] | oneBitMask128[81] | oneBitMask128[82],
        oneBitMask128[81] | oneBitMask128[82] | oneBitMask128[83],
        oneBitMask128[82] | oneBitMask128[83] | oneBitMask128[84],
        oneBitMask128[83] | oneBitMask128[84] | oneBitMask128[85],
        oneBitMask128[84] | oneBitMask128[85] | oneBitMask128[86],
        oneBitMask128[85] | oneBitMask128[86] | oneBitMask128[87],
        oneBitMask128[86] | oneBitMask128[87] | oneBitMask128[88],
        oneBitMask128[87] | oneBitMask128[88] | oneBitMask128[89],
    };
}
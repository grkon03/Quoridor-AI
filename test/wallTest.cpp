#include <gtest/gtest.h>
#include "../src/includes/wall.hpp"
#include "../src/includes/indexer/IndexerAllIncludes.hpp"

using namespace QuoridorAI;

TEST(WallBBODTest, WallBBODHorizontalIsThereWallTest)
{
    WallBBOD<Horizontal> hw;

    /*
        wall existing at: a1-b1, b2-c2, c3-d3, d4-e4, e5-f5, f6-g6, g7-h7, i8-j8
    */
    hw = WallBBOD<Horizontal>(Bitboard128(
        "0b100000000001000000000100000000010000000001000000000100000000010000000001"));

    // all the true conditions

    EXPECT_TRUE(hw.IsThereWall(FileA, Rank1));
    EXPECT_TRUE(hw.IsThereWall(FileB, Rank2));
    EXPECT_TRUE(hw.IsThereWall(FileC, Rank3));
    EXPECT_TRUE(hw.IsThereWall(FileD, Rank4));
    EXPECT_TRUE(hw.IsThereWall(FileE, Rank5));
    EXPECT_TRUE(hw.IsThereWall(FileF, Rank6));
    EXPECT_TRUE(hw.IsThereWall(FileG, Rank7));
    EXPECT_TRUE(hw.IsThereWall(FileI, Rank8));

    // some false conditions

    EXPECT_FALSE(hw.IsThereWall(FileB, Rank1));
    EXPECT_FALSE(hw.IsThereWall(FileD, Rank8));
    EXPECT_FALSE(hw.IsThereWall(FileE, Rank2));
    EXPECT_FALSE(hw.IsThereWall(FileF, Rank3));
    EXPECT_FALSE(hw.IsThereWall(FileH, Rank7));
}

TEST(WallBBODTest, WallBBODVerticalIsThereWallTest)
{
    WallBBOD<Vertical> vw;

    /*
        wall existing at: b0-b1, c2-c3, d3-d4, e4-e5, f5-f6, g6-g7, h7-h8, i8-i9
    */
    vw = WallBBOD<Vertical>(Bitboard128(
        "0b100000000100000000100000000100000000100000000100000000100000000000000001"));

    // all the true conditions

    EXPECT_TRUE(vw.IsThereWall(FileB, Rank0));
    EXPECT_TRUE(vw.IsThereWall(FileC, Rank2));
    EXPECT_TRUE(vw.IsThereWall(FileD, Rank3));
    EXPECT_TRUE(vw.IsThereWall(FileE, Rank4));
    EXPECT_TRUE(vw.IsThereWall(FileF, Rank5));
    EXPECT_TRUE(vw.IsThereWall(FileG, Rank6));
    EXPECT_TRUE(vw.IsThereWall(FileH, Rank7));
    EXPECT_TRUE(vw.IsThereWall(FileI, Rank8));

    // some false conditions

    EXPECT_FALSE(vw.IsThereWall(FileB, Rank1));
    EXPECT_FALSE(vw.IsThereWall(FileD, Rank8));
    EXPECT_FALSE(vw.IsThereWall(FileE, Rank3));
    EXPECT_FALSE(vw.IsThereWall(FileF, Rank6));
    EXPECT_FALSE(vw.IsThereWall(FileH, Rank5));
}

TEST(WallBBsTest, WallBBsPutFenceByFenceTest)
{
    WallBBs wbs;

    wbs.PutFence(MakeFence(SE_B3, SE_D3));
    wbs.PutFence(MakeFence(SE_E5, SE_E7));

    // existing

    EXPECT_TRUE(wbs.IsThereWall(SE_B3, SE_C3));
    EXPECT_TRUE(wbs.IsThereWall(SE_C3, SE_D3));
    EXPECT_TRUE(wbs.IsThereWall(SE_E5, SE_E6));
    EXPECT_TRUE(wbs.IsThereWall(SE_E6, SE_E7));

    // no existing

    EXPECT_FALSE(wbs.IsThereWall(SE_C5, SE_C6));
    EXPECT_FALSE(wbs.IsThereWall(SE_E3, SE_E4));
}

TEST(WallBBsTest, WallBBsPutFenceByDirSquareEdgeTest)
{
    WallBBs wbs;

    wbs.PutFence<Horizontal>(SE_A1);
    wbs.PutFence<Vertical>(SE_H7);

    // existing

    EXPECT_TRUE(wbs.IsThereWall(SE_A1, SE_B1));
    EXPECT_TRUE(wbs.IsThereWall(SE_B1, SE_C1));
    EXPECT_TRUE(wbs.IsThereWall(SE_H7, SE_H8));
    EXPECT_TRUE(wbs.IsThereWall(SE_H8, SE_H9));

    // no existing

    EXPECT_FALSE(wbs.IsThereWall(SE_C1, SE_C2));
    EXPECT_FALSE(wbs.IsThereWall(SE_H6, SE_H7));
}

TEST(WallBBsTest, WallBBsPutFenceByIndexTest)
{
    WallBBs wbs;

    wbs.PutFence(Indexer::FenceToIndex(MakeFence(SE_H8, SE_J8)));
    wbs.PutFence(Indexer::FenceToIndex(MakeFence(SE_D0, SE_D2)));

    // existing

    EXPECT_TRUE(wbs.IsThereWall(SE_H8, SE_I8));
    EXPECT_TRUE(wbs.IsThereWall(SE_H8, SE_I8));
    EXPECT_TRUE(wbs.IsThereWall(SE_D0, SE_D1));
    EXPECT_TRUE(wbs.IsThereWall(SE_D1, SE_D2));

    // no existing

    EXPECT_FALSE(wbs.IsThereWall(SE_C1, SE_C2));
    EXPECT_FALSE(wbs.IsThereWall(SE_D6, SE_D7));
}

TEST(WallBBsTest, WallBBsIsThereWallVarietiesTest)
{
    WallBBs wbs;

    wbs.PutFence(MakeFence(SE_H6, SE_H8));
    wbs.PutFence(MakeFence(SE_C1, SE_E1));

    // WallDir and SquareEdge

    // existing

    EXPECT_TRUE(wbs.IsThereWall<Vertical>(SE_H6));
    EXPECT_TRUE(wbs.IsThereWall<Vertical>(SE_H7));
    EXPECT_TRUE(wbs.IsThereWall<Horizontal>(SE_C1));
    EXPECT_TRUE(wbs.IsThereWall<Horizontal>(SE_D1));

    // no existing

    EXPECT_FALSE(wbs.IsThereWall<Vertical>(SE_H5));
    EXPECT_FALSE(wbs.IsThereWall<Horizontal>(SE_E1));

    // WallDir, File and Rank

    // existing

    EXPECT_TRUE(wbs.IsThereWall<Vertical>(FileH, Rank6));
    EXPECT_TRUE(wbs.IsThereWall<Vertical>(FileH, Rank7));
    EXPECT_TRUE(wbs.IsThereWall<Horizontal>(FileC, Rank1));
    EXPECT_TRUE(wbs.IsThereWall<Horizontal>(FileD, Rank1));

    // no existing

    EXPECT_FALSE(wbs.IsThereWall<Vertical>(FileH, Rank5));
    EXPECT_FALSE(wbs.IsThereWall<Horizontal>(FileE, Rank1));
}

// includeing tests of IsOverlap functions
TEST(WallBBsTest, WallBBsPutFenceWithOverlapVerificationTest)
{
    WallBBs wbs;

    // make base

    // able to put

    wbs.PutFenceWithOverlapVerification(MakeFence(SE_B3, SE_B5));
    wbs.PutFenceWithOverlapVerification(MakeFence(SE_H1, SE_J1));

    // unable to put

    // verify

    EXPECT_FALSE(wbs.IsThereWall(SE_B2, SE_B3));
    EXPECT_TRUE(wbs.IsThereWall(SE_B3, SE_B4));
    EXPECT_TRUE(wbs.IsThereWall(SE_B4, SE_B5));
    EXPECT_FALSE(wbs.IsThereWall(SE_B5, SE_B6));
    EXPECT_FALSE(wbs.IsThereWall(SE_G1, SE_H1));
    EXPECT_TRUE(wbs.IsThereWall(SE_H1, SE_I1));
    EXPECT_TRUE(wbs.IsThereWall(SE_I1, SE_J1));

    // try

    wbs.PutFenceWithOverlapVerification(MakeFence(SE_B2, SE_B4));
    wbs.PutFenceWithOverlapVerification(MakeFence(SE_B4, SE_B6));
    wbs.PutFenceWithOverlapVerification(MakeFence(SE_G1, SE_I1));

    // verify

    EXPECT_FALSE(wbs.IsThereWall(SE_B2, SE_B3));
    EXPECT_TRUE(wbs.IsThereWall(SE_B3, SE_B4));
    EXPECT_TRUE(wbs.IsThereWall(SE_B4, SE_B5));
    EXPECT_FALSE(wbs.IsThereWall(SE_B5, SE_B6));
    EXPECT_FALSE(wbs.IsThereWall(SE_G1, SE_H1));
    EXPECT_TRUE(wbs.IsThereWall(SE_H1, SE_I1));
    EXPECT_TRUE(wbs.IsThereWall(SE_I1, SE_J1));

    // try

    wbs.PutFenceWithOverlapVerification(Indexer::FenceToIndex(MakeFence(SE_B2, SE_B4)));
    wbs.PutFenceWithOverlapVerification(Indexer::FenceToIndex(MakeFence(SE_B4, SE_B6)));
    wbs.PutFenceWithOverlapVerification(Indexer::FenceToIndex(MakeFence(SE_G1, SE_I1)));

    // verify

    EXPECT_FALSE(wbs.IsThereWall(SE_B2, SE_B3));
    EXPECT_TRUE(wbs.IsThereWall(SE_B3, SE_B4));
    EXPECT_TRUE(wbs.IsThereWall(SE_B4, SE_B5));
    EXPECT_FALSE(wbs.IsThereWall(SE_B5, SE_B6));
    EXPECT_FALSE(wbs.IsThereWall(SE_G1, SE_H1));
    EXPECT_TRUE(wbs.IsThereWall(SE_H1, SE_I1));
    EXPECT_TRUE(wbs.IsThereWall(SE_I1, SE_J1));

    // try

    wbs.PutFenceWithOverlapVerification<Vertical>(SE_B2);
    wbs.PutFenceWithOverlapVerification<Vertical>(SE_B4);
    wbs.PutFenceWithOverlapVerification<Horizontal>(SE_G1);

    // verify

    EXPECT_FALSE(wbs.IsThereWall(SE_B2, SE_B3));
    EXPECT_TRUE(wbs.IsThereWall(SE_B3, SE_B4));
    EXPECT_TRUE(wbs.IsThereWall(SE_B4, SE_B5));
    EXPECT_FALSE(wbs.IsThereWall(SE_B5, SE_B6));
    EXPECT_FALSE(wbs.IsThereWall(SE_G1, SE_H1));
    EXPECT_TRUE(wbs.IsThereWall(SE_H1, SE_I1));
    EXPECT_TRUE(wbs.IsThereWall(SE_I1, SE_J1));
}
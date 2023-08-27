#include <gtest/gtest.h>

#include "../src/includes/wallman.hpp"
#include "../src/includes/indexer/IndexerAllIncludes.hpp"

using namespace QuoridorAI;

TEST(WallManTest, WallManPutFenceByFenceTest)
{
    WallMan wallman;
    WallBBs wallBBs;

    // no intersection test

    wallman.PutFence(MakeFence(SE_A3, SE_C3));
    wallman.PutFence(MakeFence(SE_G6, SE_I6));
    wallman.PutFence(MakeFence(SE_I6, SE_I8));
    wallman.PutFence(MakeFence(SE_C0, SE_C2));

    wallBBs = wallman.GetWallBBs();

    EXPECT_TRUE(wallBBs.IsThereWall(SE_A3, SE_B3));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_B3, SE_C3));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_G6, SE_H6));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_H6, SE_I6));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_I6, SE_I7));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_I7, SE_I8));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_C0, SE_C1));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_C1, SE_C2));

    // intersect test

    wallman.PutFence(MakeFence(SE_B2, SE_B4));
    wallman.PutFence(MakeFence(SE_H5, SE_H7));
    wallman.PutFence(MakeFence(SE_H7, SE_J7));
    wallman.PutFence(MakeFence(SE_B1, SE_D1));

    wallBBs = wallman.GetWallBBs();

    EXPECT_FALSE(wallBBs.IsThereWall(SE_B2, SE_B3));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_B3, SE_B4));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_H5, SE_H6));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_H6, SE_H7));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_H7, SE_I7));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_I7, SE_J7));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_B1, SE_C1));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_C1, SE_D1));

    // no intersect test after overlap

    wallman.PutFence(MakeFence(SE_B3, SE_D3));
    wallman.PutFence(MakeFence(SE_I7, SE_I9));

    wallBBs = wallman.GetWallBBs();

    EXPECT_FALSE(wallBBs.IsThereWall(SE_C3, SE_D3));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_I8, SE_I9));

    wallman.PutFence(MakeFence(SE_C2, SE_C4));
    wallman.PutFence(MakeFence(SE_H8, SE_J8));

    wallBBs = wallman.GetWallBBs();

    EXPECT_TRUE(wallBBs.IsThereWall(SE_C2, SE_C3));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_C3, SE_C4));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_H8, SE_I8));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_I8, SE_J8));
}

TEST(WallManTest, WallManPutFenceByIndexTest)
{
    WallMan wallman;
    WallBBs wallBBs;

    // no intersection test

    wallman.PutFence(Indexer::FenceToIndex(MakeFence(SE_A3, SE_C3)));
    wallman.PutFence(Indexer::FenceToIndex(MakeFence(SE_G6, SE_I6)));
    wallman.PutFence(Indexer::FenceToIndex(MakeFence(SE_I6, SE_I8)));
    wallman.PutFence(Indexer::FenceToIndex(MakeFence(SE_C0, SE_C2)));

    wallBBs = wallman.GetWallBBs();

    EXPECT_TRUE(wallBBs.IsThereWall(SE_A3, SE_B3));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_B3, SE_C3));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_G6, SE_H6));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_H6, SE_I6));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_I6, SE_I7));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_I7, SE_I8));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_C0, SE_C1));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_C1, SE_C2));

    // intersect test

    wallman.PutFence(Indexer::FenceToIndex(MakeFence(SE_B2, SE_B4)));
    wallman.PutFence(Indexer::FenceToIndex(MakeFence(SE_H5, SE_H7)));
    wallman.PutFence(Indexer::FenceToIndex(MakeFence(SE_H7, SE_J7)));
    wallman.PutFence(Indexer::FenceToIndex(MakeFence(SE_B1, SE_D1)));

    wallBBs = wallman.GetWallBBs();

    EXPECT_FALSE(wallBBs.IsThereWall(SE_B2, SE_B3));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_B3, SE_B4));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_H5, SE_H6));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_H6, SE_H7));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_H7, SE_I7));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_I7, SE_J7));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_B1, SE_C1));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_C1, SE_D1));

    // no intersect test after overlap

    wallman.PutFence(Indexer::FenceToIndex(MakeFence(SE_B3, SE_D3)));
    wallman.PutFence(Indexer::FenceToIndex(MakeFence(SE_I7, SE_I9)));

    wallBBs = wallman.GetWallBBs();

    EXPECT_FALSE(wallBBs.IsThereWall(SE_C3, SE_D3));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_I8, SE_I9));

    wallman.PutFence(Indexer::FenceToIndex(MakeFence(SE_C2, SE_C4)));
    wallman.PutFence(Indexer::FenceToIndex(MakeFence(SE_H8, SE_J8)));

    wallBBs = wallman.GetWallBBs();

    EXPECT_TRUE(wallBBs.IsThereWall(SE_C2, SE_C3));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_C3, SE_C4));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_H8, SE_I8));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_I8, SE_J8));
}

TEST(WallManTest, WallManPutFenceByDirSquareEdgeTest)
{
    WallMan wallman;
    WallBBs wallBBs;

    // no intersection test

    wallman.PutFence<Horizontal>(SE_A3);
    wallman.PutFence<Horizontal>(SE_G6);
    wallman.PutFence<Vertical>(SE_I6);
    wallman.PutFence<Vertical>(SE_C0);

    wallBBs = wallman.GetWallBBs();

    EXPECT_TRUE(wallBBs.IsThereWall(SE_A3, SE_B3));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_B3, SE_C3));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_G6, SE_H6));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_H6, SE_I6));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_I6, SE_I7));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_I7, SE_I8));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_C0, SE_C1));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_C1, SE_C2));

    // intersect test

    wallman.PutFence<Vertical>(SE_B2);
    wallman.PutFence<Vertical>(SE_H5);
    wallman.PutFence<Horizontal>(SE_H7);
    wallman.PutFence<Horizontal>(SE_B1);

    wallBBs = wallman.GetWallBBs();

    EXPECT_FALSE(wallBBs.IsThereWall(SE_B2, SE_B3));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_B3, SE_B4));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_H5, SE_H6));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_H6, SE_H7));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_H7, SE_I7));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_I7, SE_J7));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_B1, SE_C1));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_C1, SE_D1));

    // no intersect test after overlap

    wallman.PutFence<Horizontal>(SE_B3);
    wallman.PutFence<Vertical>(SE_I7);

    wallBBs = wallman.GetWallBBs();

    EXPECT_FALSE(wallBBs.IsThereWall(SE_C3, SE_D3));
    EXPECT_FALSE(wallBBs.IsThereWall(SE_I8, SE_I9));

    wallman.PutFence<Vertical>(SE_C2);
    wallman.PutFence<Horizontal>(SE_H8);

    wallBBs = wallman.GetWallBBs();

    EXPECT_TRUE(wallBBs.IsThereWall(SE_C2, SE_C3));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_C3, SE_C4));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_H8, SE_I8));
    EXPECT_TRUE(wallBBs.IsThereWall(SE_I8, SE_J8));
}

TEST(WallManTest, WallManCalcAvailableFenceBBTest)
{
    WallBBs wallBBs;
    WallMan wallMan, wallManCor;

    // first case

    wallBBs = WallBBs();

    wallBBs.PutFence(MakeFence(SE_D1, SE_D3));
    wallBBs.PutFence(MakeFence(SE_D5, SE_D7));
    wallBBs.PutFence(MakeFence(SE_D7, SE_D9));
    wallBBs.PutFence(MakeFence(SE_F3, SE_F5));
    wallBBs.PutFence(MakeFence(SE_I0, SE_I2));
    wallBBs.PutFence(MakeFence(SE_D2, SE_F2));
    wallBBs.PutFence(MakeFence(SE_F2, SE_H2));
    wallBBs.PutFence(MakeFence(SE_H2, SE_J2));
    wallBBs.PutFence(MakeFence(SE_A5, SE_C5));

    wallMan = WallMan(wallBBs);

    wallManCor = WallMan();

    wallManCor.PutFence(MakeFence(SE_D1, SE_D3));
    wallManCor.PutFence(MakeFence(SE_D5, SE_D7));
    wallManCor.PutFence(MakeFence(SE_D7, SE_D9));
    wallManCor.PutFence(MakeFence(SE_F3, SE_F5));
    wallManCor.PutFence(MakeFence(SE_I0, SE_I2));
    wallManCor.PutFence(MakeFence(SE_D2, SE_F2));
    wallManCor.PutFence(MakeFence(SE_F2, SE_H2));
    wallManCor.PutFence(MakeFence(SE_H2, SE_J2));
    wallManCor.PutFence(MakeFence(SE_A5, SE_C5));

    EXPECT_EQ(wallMan.GetAvailableFenceBB<Vertical>(), wallManCor.GetAvailableFenceBB<Vertical>());
    EXPECT_EQ(wallMan.GetAvailableFenceBB<Horizontal>(), wallManCor.GetAvailableFenceBB<Horizontal>());

    wallBBs = WallBBs();

    // second case

    wallBBs.PutFence(MakeFence(SE_C1, SE_C3));
    wallBBs.PutFence(MakeFence(SE_B3, SE_D3));
    wallBBs.PutFence(MakeFence(SE_C3, SE_C5));
    wallBBs.PutFence(MakeFence(SE_D5, SE_F5));
    wallBBs.PutFence(MakeFence(SE_I3, SE_I5));
    wallBBs.PutFence(MakeFence(SE_H5, SE_J5));
    wallBBs.PutFence(MakeFence(SE_C5, SE_C7));
    wallBBs.PutFence(MakeFence(SE_B1, SE_B3));
    wallBBs.PutFence(MakeFence(SE_F0, SE_F2));

    wallMan = WallMan(wallBBs);

    wallManCor = WallMan();

    wallManCor.PutFence(MakeFence(SE_C1, SE_C3));
    wallManCor.PutFence(MakeFence(SE_B3, SE_D3));
    wallManCor.PutFence(MakeFence(SE_C3, SE_C5));
    wallManCor.PutFence(MakeFence(SE_D5, SE_F5));
    wallManCor.PutFence(MakeFence(SE_I3, SE_I5));
    wallManCor.PutFence(MakeFence(SE_H5, SE_J5));
    wallManCor.PutFence(MakeFence(SE_C5, SE_C7));
    wallManCor.PutFence(MakeFence(SE_B1, SE_B3));
    wallManCor.PutFence(MakeFence(SE_F0, SE_F2));

    EXPECT_EQ(wallMan.GetAvailableFenceBB<Vertical>(), wallManCor.GetAvailableFenceBB<Vertical>());
    EXPECT_EQ(wallMan.GetAvailableFenceBB<Horizontal>(), wallManCor.GetAvailableFenceBB<Horizontal>());
}
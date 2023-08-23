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
}
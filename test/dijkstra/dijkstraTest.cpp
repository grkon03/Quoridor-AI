#include <gtest/gtest.h>

#include "../../src/includes/dijkstra/DijkstraAllIncludes.hpp"

#include <iostream>

using namespace QuoridorAI;

namespace QuoridorAI::DijkstraTester
{
    extern const Distance correctAnswer1[ColorLimit][NumberOfSquare];
    extern const Distance correctAnswer2[ColorLimit][NumberOfSquare];
}

using namespace QuoridorAI::DijkstraTester;

TEST(DijkstraTest, DijkstraMainAlgorithmTest)
{
    Dijkstra dijkstra;
    WallBBs wallBBs;

    Distance answer[ColorLimit][NumberOfSquare];

    // fist test

    wallBBs = WallBBs();

    wallBBs.PutFence(MakeFence(SE_F7, SE_H7));
    wallBBs.PutFence(MakeFence(SE_D4, SE_D6));
    wallBBs.PutFence(MakeFence(SE_H6, SE_J6));
    wallBBs.PutFence(MakeFence(SE_D4, SE_F4));
    wallBBs.PutFence(MakeFence(SE_I4, SE_I6));
    wallBBs.PutFence(MakeFence(SE_F2, SE_F4));

    dijkstra = Dijkstra(wallBBs);

    dijkstra.GetDistances(answer);

    for (int i = 0; i < NumberOfSquare; ++i)
    {
        EXPECT_EQ(answer[White][i], correctAnswer1[White][i]);
        EXPECT_EQ(answer[Black][i], correctAnswer1[Black][i]);
    }

    // second test

    wallBBs = WallBBs();

    wallBBs.PutFence(MakeFence(SE_E6, SE_E8));
    wallBBs.PutFence(MakeFence(SE_B5, SE_B7));
    wallBBs.PutFence(MakeFence(SE_H5, SE_H7));
    wallBBs.PutFence(MakeFence(SE_C4, SE_C6));
    wallBBs.PutFence(MakeFence(SE_D4, SE_D6));
    wallBBs.PutFence(MakeFence(SE_F3, SE_F5));
    wallBBs.PutFence(MakeFence(SE_H3, SE_H5));
    wallBBs.PutFence(MakeFence(SE_G1, SE_G3));
    wallBBs.PutFence(MakeFence(SE_H0, SE_H2));
    wallBBs.PutFence(MakeFence(SE_F7, SE_H7));
    wallBBs.PutFence(MakeFence(SE_C6, SE_E6));
    wallBBs.PutFence(MakeFence(SE_E6, SE_G6));
    wallBBs.PutFence(MakeFence(SE_A5, SE_C5));
    wallBBs.PutFence(MakeFence(SE_D5, SE_F5));
    wallBBs.PutFence(MakeFence(SE_F5, SE_H5));
    wallBBs.PutFence(MakeFence(SE_D3, SE_F3));
    wallBBs.PutFence(MakeFence(SE_F3, SE_H3));
    wallBBs.PutFence(MakeFence(SE_H2, SE_J2));

    dijkstra = Dijkstra(wallBBs);

    dijkstra.GetDistances(answer);

    for (int i = 0; i < NumberOfSquare; ++i)
    {
        EXPECT_EQ(answer[White][i], correctAnswer2[White][i]);
        EXPECT_EQ(answer[Black][i], correctAnswer2[Black][i]);
    }
}

TEST(DijkstraTest, DijkstraPutFenceTest)
{
}
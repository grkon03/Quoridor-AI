#pragma once

#include "../wallman.hpp"
#include "misc.hpp"

namespace QuoridorAI
{
    using Distance = signed char;

    class Dijkstra
    {
        // variables

        WallBBs wallBBs;
        Distance distances[ColorLimit][NumberOfSquare];

    public:
        // constructors

        Dijkstra();
        Dijkstra(const WallBBOD<Vertical> &, const WallBBOD<Horizontal> &);
        Dijkstra(const WallBBs &);
        Dijkstra(const WallMan &);
        Dijkstra(const Dijkstra &);

        // functions

        /**
         * @brief Get distances
         *
         * @param receiver received distances
         */
        void GetDistances(Distance &&receiver);

        /**
         * @brief Get the distance
         *
         * @param square the square
         * @param color color of the king
         */
        Distance GetDistance(Square square, Color color);

        /**
         * @brief Get the distance
         *
         * @param squareIndex index of the square
         * @param color color of the king
         */
        Distance GetDistance(int squareIndex, Color color);

        /**
         * @brief verify whether a king of the color can reach to his goal from the specified square
         *
         * @param square the square
         * @param color color of the king
         */
        bool IsThereReachableToGoal(Square square, Color color);

        /**
         * @brief verify whether a king of the color can reach to his goal from the specified square
         *
         * @param se left-bottom square edge of the square
         * @param color color of the king
         */
        bool IsThereReachableToGoal(SquareEdge se, Color color);

        /**
         * @brief verify whether a king of the color can reach to his goal from the specified square
         *
         * @param squareIndex index of the square by Indexer
         * @param color color of the king
         */
        bool IsThereReachableToGoal(int squareIndex, Color color);

    private:
        /**
         * @brief main process of dijkstra with recursive function
         *
         * @param color color of the king
         */
        void DijkstraRecursive(Color color);
    };
}
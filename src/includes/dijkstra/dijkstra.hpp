#pragma once

#include "../wall.hpp"
#include "misc.hpp"

namespace QuoridorAI
{
    using Distance = signed char;
    constexpr Distance Unreachable = 81;

    class WallMan;

    class Dijkstra
    {
        // variables

        WallBBs wallBBs;
        /**
         * @brief distances which a king of the color should walk from the square to his goal
         * @note a positive number < 81 expresses a proper distance
         * @note Unreachable = 81 expresses no way to goal from the square for the king of the color
         *
         */
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
        void GetDistances(Distance receiver[ColorLimit][NumberOfSquare]) const;

        /**
         * @brief Get the distance
         *
         * @param square the square
         * @param color color of the king
         */
        Distance GetDistance(Square square, Color color) const;

        /**
         * @brief Get the distance
         *
         * @param squareIndex index of the square
         * @param color color of the king
         */
        Distance GetDistance(int squareIndex, Color color) const;

        /**
         * @brief verify whether a king of the color can reach to his goal from the specified square
         *
         * @param square the square
         * @param color color of the king
         */
        bool IsThereReachableToGoal(Square square, Color color) const;

        /**
         * @brief verify whether a king of the color can reach to his goal from the specified square
         *
         * @param se left-bottom square edge of the square
         * @param color color of the king
         */
        bool IsThereReachableToGoal(SquareEdge se, Color color) const;

        /**
         * @brief verify whether a king of the color can reach to his goal from the specified square
         *
         * @param squareIndex index of the square by Indexer
         * @param color color of the king
         */
        bool IsThereReachableToGoal(int squareIndex, Color color) const;

        /**
         * @brief put fence
         *
         * @tparam direction direction of the fence
         * @param se left-bottom square edge of the fence
         */
        template <WallDir direction>
        void PutFence(SquareEdge se);

        /**
         * @brief put fence
         *
         * @param fence the fence
         */
        void PutFence(Fence fence);

        /**
         * @brief put fence
         *
         * @param fenceIndex index of the fence
         */
        void PutFence(int fenceIndex);

    private:
        /**
         * @brief main process of dijkstra with recursive function
         *
         * @param color color of the king
         * @param phase distance now searching
         */
        void DijkstraRecursive(const Color color, const Distance phase);

        /**
         * @brief calculate temporary distance of the square: 1 + minimum distance from 4 squares s.t. top, bottom, left, right.
         *
         * @param squareIndex index of the square
         * @param color color
         * @return Distance
         */
        Distance CalcTemporaryDistance(Color color, int squareIndex);

        /**
         * @brief To calculate squares which should be updated when fence is put, and set distances these squares to Unreachable
         *
         * @param color color of the king
         * @param squarseIndex index of the square
         * @param numOfSquaresToUpdate the number of squares to update
         * @param squaresToUpdate squares to update
         */
        void ReverseDijkstraRecursive(const Color color, const int squarseIndex, int *numOfSquaresToUpdate, int squaresToUpdate[81]);

        /**
         * @brief update distances after putting fence
         *
         * @param color color of the king
         * @param lbSquareIndex index of left-bottom square index to update
         */
        void UpdateDistancesByPutFence(const Color color, const int lbSquareIndex);
    };

    template <>
    inline void Dijkstra::PutFence<Vertical>(SquareEdge se)
    {
        wallBBs.PutFence<Vertical>(se);

        int lbSquareIndex = GetRank(se) * 9 + GetFile(se) - 1;

        UpdateDistancesByPutFence(White, lbSquareIndex);
        UpdateDistancesByPutFence(Black, lbSquareIndex);
    }

    template <>
    inline void Dijkstra::PutFence<Horizontal>(SquareEdge se)
    {
        wallBBs.PutFence<Horizontal>(se);

        int lbSquareIndex = (GetRank(se) - 1) * 9 + GetFile(se);

        UpdateDistancesByPutFence(White, lbSquareIndex);
        UpdateDistancesByPutFence(Black, lbSquareIndex);
    }
}
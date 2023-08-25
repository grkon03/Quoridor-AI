#include "../../src/includes/dijkstra/DijkstraAllIncludes.hpp"

namespace QuoridorAI::DijkstraTest
{

    extern constexpr Distance correctAnswer1[ColorLimit][NumberOfSquare] =
        {
            {
                8,
                8,
                8,
                9,
                10,
                9,
                9,
                10,
                11,
                7,
                7,
                7,
                8,
                9,
                8,
                8,
                9,
                10,
                6,
                6,
                6,
                7,
                8,
                7,
                7,
                8,
                9,
                5,
                5,
                5,
                6,
                7,
                6,
                6,
                7,
                8,
                4,
                4,
                4,
                4,
                4,
                5,
                5,
                6,
                9,
                3,
                3,
                3,
                3,
                3,
                4,
                4,
                5,
                10,
                2,
                2,
                2,
                2,
                2,
                3,
                3,
                2,
                2,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
            },
            {
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                3,
                3,
                3,
                3,
                3,
                3,
                3,
                3,
                3,
                4,
                4,
                4,
                6,
                5,
                4,
                4,
                4,
                4,
                5,
                5,
                5,
                7,
                6,
                5,
                5,
                5,
                5,
                6,
                6,
                6,
                7,
                7,
                6,
                6,
                7,
                8,
                7,
                7,
                7,
                8,
                8,
                9,
                9,
                8,
                9,
                8,
                8,
                8,
                9,
                9,
                10,
                10,
                9,
                10,
            },
    };

    extern constexpr Distance correctAnswer2[ColorLimit][NumberOfSquare] =
        {
            {15, 14, 13, 12, 11, 10, 9, Unreachable, Unreachable,
             16, 15, 14, 13, 12, 11, 8, Unreachable, Unreachable,
             17, 16, 15, 14, 13, 12, 7, 6, 6,
             18, 17, 16, 17, 18, Unreachable, Unreachable, 5, 5,
             19, 18, 17, 18, 19, Unreachable, Unreachable, 4, 4,
             3, 3, 18, 8, 7, 6, 5, 3, 3,
             2, 2, 2, 2, 2, 3, 4, 2, 2,
             1, 1, 1, 1, 1, 1, 1, 1, 1,
             0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0,
             1, 1, 1, 1, 1, 1, 1, 1, 1,
             2, 2, 2, 2, 2, 2, 2, 3, 4,
             3, 3, 3, 4, 5, Unreachable, Unreachable, 4, 5,
             4, 4, 4, 5, 6, Unreachable, Unreachable, 5, 6,
             19, 18, 5, 18, 17, 16, 15, 6, 7,
             18, 17, 16, 15, 12, 13, 14, 7, 8,
             17, 16, 15, 14, 11, 10, 9, 8, 9,
             16, 15, 14, 13, 12, 11, 10, 9, 10},
    };
}
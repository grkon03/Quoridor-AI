#pragma once

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
}
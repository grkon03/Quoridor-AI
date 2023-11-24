#include "moveAnalyze.hpp"

namespace QuoridorAI::Util
{
    std::vector<int> ExtractKingTracking(std::vector<int> moves, int startLocation)
    {
        std::vector<int> ret{startLocation};
        for (int i = 0; i < moves.size(); ++i)
        {
            if (moves[i] < 81)
                ret.push_back(moves[i]);
        }
        return ret;
    }
}
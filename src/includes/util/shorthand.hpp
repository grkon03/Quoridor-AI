#pragma once

#include "../types.hpp"
#include <string>
#include <vector>

namespace QuoridorAI::Util
{
    /**
     * @brief calculate index of the move by shorthand notation
     *
     * @param sn shorthand notation
     * @return index of the expressed move
     */
    int MakeIMoveSN(std::string sn);

    /**
     * @brief calculate indexes of the moves by shorthand notations
     *
     * @param sns shorthand notations
     * @return vectors of indexes of the expressed moves
     */
    std::vector<int> MakeIMoveSNs(std::vector<std::string> sns);
}
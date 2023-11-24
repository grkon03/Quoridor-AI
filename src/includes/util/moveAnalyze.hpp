#pragma once

#include "../types.hpp"
#include <vector>

namespace QuoridorAI::Util
{
    /**
     * @brief extract a king tracking (for kingRecorder)
     *
     * @param moves moves
     * @param startLocation a location of king at starting position
     * @return a king tracking
     */
    std::vector<int> ExtractKingTracking(std::vector<int> moves, int startLocation);
}
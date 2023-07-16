#include "random.hpp"

namespace QuoridorAI
{
    namespace Hasher
    {
        Randomizer::Randomizer() : size(64){};
        Randomizer::Randomizer(int _size) : size(_size){};
    }
}
#include "random.hpp"

namespace QuoridorAI
{
    namespace Hasher
    {
        RandomizerBase::RandomizerBase() : size(64){};
        RandomizerBase::RandomizerBase(int _size) : size(_size){};
    }
}
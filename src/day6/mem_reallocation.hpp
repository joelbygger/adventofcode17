#pragma once
#include <vector>

namespace Mem_reallocation
{
    // Returns number of run until an already visited state has been found, i.e. we're in a loop.
    int run(std::vector<int>& banks);
} // namespace Mem_reallocation

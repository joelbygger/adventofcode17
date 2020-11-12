#include "checksum.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>

namespace
{
    int row_checksum(const int val, const std::vector<int>& vec)
    {
        const auto [min, max] = std::minmax_element(vec.begin(), vec.end());
        return val + *max - *min;
    }
} // namespace

namespace Checksum
{
    int calc(const std::vector<std::vector<int>>& numbers)
    {
        int checksum = std::accumulate(numbers.begin(), numbers.end(), 0, row_checksum);
        return checksum;
    }
} // namespace Checksum

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

    int sum_even_divisible(const std::vector<std::vector<int>>& numbers)
    {
        int sum = 0;

        for (auto row : numbers) {
            for (auto it = row.begin(); it != row.end(); std::advance(it, 1)) {
                auto itNext = it;
                std::advance(itNext, 1);

                auto itRes = std::find_if(
                    itNext, row.end(), [&](const auto& val) { return *it > val ? *it % val == 0 : val % *it == 0; });

                if (itRes != row.end()) {
                    if (*it > *itRes) {
                        sum += *it / *itRes;
                    }
                    else {
                        sum += *itRes / *it;
                    }
                }
            }
        }
        return sum;
    }
} // namespace Checksum

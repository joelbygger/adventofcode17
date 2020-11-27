#include "mem_reallocation.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>

namespace
{
    void realloc(std::vector<int>& banks)
    {
        auto bank = std::max_element(banks.begin(), banks.end());
        auto blocks = *bank;
        *bank = 0;

        // First run is from block AFTER max block.
        std::advance(bank, 1);
        if (bank == banks.end()) {
            bank = banks.begin();
        }

        while (blocks > 0) {
            static_cast<void>(std::all_of(bank, banks.end(), [&](int& n) {
                n++;
                return --blocks > 0;
            }));

            bank = banks.begin(); // Next iteration, start from beginning.
        }
    }
} // namespace

namespace Mem_reallocation
{
    int run(std::vector<int>& banks)
    {
        int count = 0;
        std::vector<std::vector<int>> seen;

        // Reallocate until duplicate is found.
        while (std::find(seen.begin(), seen.end(), banks) == seen.end()) {
            seen.push_back(banks);
            realloc(banks);
            count++;
        }

        return count;
    }
} // namespace Mem_reallocation

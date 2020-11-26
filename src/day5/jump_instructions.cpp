#include "jump_instructions.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>

namespace Jump_instructions
{
    int to_exit(const std::vector<int>& instructions)
    {
        std::map<int, int> step_rules;
        int index = 0;
        int count = 0;

        while (index >= 0 && static_cast<size_t>(index) < instructions.size()) {
            const auto raw_val = instructions.at(static_cast<size_t>(index));
            step_rules.try_emplace(index, raw_val);

            const auto old_index = index;
            index += step_rules[index];
            step_rules.at(old_index)++;

            count++;
        }

        return count;
    }
} // namespace Jump_instructions

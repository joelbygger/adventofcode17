#include "jump_instructions.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <unordered_map>

namespace
{
    int calc_step(int a, int b, const std::function<int(int, int)>& op)
    {
        return op(a, b);
    }
} // namespace

namespace Jump_instructions
{
    int to_exit(const std::vector<int>& instructions, bool jump_cap)
    {
        std::unordered_map<int, int> step_rules;
        int index = 0;
        int count = 0;

        while (index >= 0 && static_cast<size_t>(index) < instructions.size()) {
            const auto raw_val = instructions.at(static_cast<size_t>(index));
            step_rules.try_emplace(index, raw_val);

            const auto curr_val = step_rules.at(index);
            auto new_val = 0;

            if (jump_cap && curr_val >= 3) {
                new_val = calc_step(curr_val, 1, std::minus<>());
            }
            else {
                new_val = calc_step(curr_val, 1, std::plus<>());
            }
            step_rules.at(index) = new_val;

            index += curr_val;
            count++;
        }

        return count;
    }
} // namespace Jump_instructions

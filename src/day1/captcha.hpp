#pragma once
#include <vector>

namespace Captcha
{
    enum class check_step
    {
        next,
        next_half
    };
    int accumulator(const std::vector<int>& captcha, check_step step);
} // namespace Captcha

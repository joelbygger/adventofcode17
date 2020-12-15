#include "captcha.hpp"
#include <iostream>
#include <numeric>

namespace
{
    std::size_t get_comp_index(std::size_t curr_index, std::size_t sz, Captcha::check_step step)
    {
        std::size_t i = 0;
        switch (step) {
        case Captcha::check_step::next:
            i = curr_index + 1;
            if (i > sz) {
                i = 0;
            }
            break;
        case Captcha::check_step::next_half:
            i = curr_index + sz / 2;
            if (i > sz) {
                i = i - sz;
            }
            break;
        }

        if (i == sz) {
            i = 0;
        }
        return i;
    }
} // namespace

namespace Captcha
{
    int accumulator(const std::vector<int>& captcha, check_step step)
    {
        int sum = 0;

        const auto sz = captcha.size();
        for (std::size_t i = 0; i < sz; i++) {
            const auto comp_index = get_comp_index(i, sz, step);
            if (captcha.at(i) == captcha.at(comp_index)) {
                sum += captcha.at(i);
            }
        }
        return sum;
    }
} // namespace Captcha

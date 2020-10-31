#include "captcha.hpp"
#include <iostream>
#include <numeric>

namespace Captcha
{
    int accumulator(const std::vector<int>& captcha)
    {
        int sum = 0;

        if (captcha.size() < 3) {
            std::cout << "This captscha is scary small.... Returning.\n";
        }
        else {
            for (std::size_t i = 0; i < captcha.size() - 1; i++) {
                if (captcha.at(i) == captcha.at(i + 1)) {
                    sum += captcha.at(i);
                }
            }
            if (captcha.front() == captcha.back()) {
                sum += captcha.front();
            }
        }

        return sum;
    }
} // namespace Captcha

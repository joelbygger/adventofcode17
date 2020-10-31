/**
 *
 * Program reads a file. A bit of error checking is applied.
 *
 */
#include "captcha.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace
{
    /**
     * Reads from file.
     * @param path Path to file.
     * @return File data to be used.
     */
    std::vector<int> getInput(const char* path)
    {
        std::vector<int> captcha;

        std::ifstream ifs(path, std::ios_base::in);
        if (!ifs) {
            std::cout << "Failed to open file.\n";
        }
        else {
            // Read the file.
            char c = 0;
            while (ifs.get(c)) {
                captcha.emplace_back(static_cast<int>(c) - static_cast<int>('0'));
            }
        }

        return captcha;
    }

} // namespace

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cout << "This program can only be run with a file name as an input. "
                     "File is expected to contains ASCII "
                     "chars only.\n"
                  << argc << "\n";
    }
    else {
        std::cout << "Received path: " << argv[1] << "\n";

        // Read the file.
        std::vector<int> captcha = getInput(argv[1]);
        if (!captcha.empty()) {
            std::cout << "Sum: " << Captcha::accumulator(captcha) << "\n";
        }
    }
    return 0;
}

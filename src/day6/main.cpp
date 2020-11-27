/**
 *
 * Program reads a file. A bit of error checking is applied.
 *
 */
#include "mem_reallocation.hpp"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
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
        std::ifstream ifs(path, std::ios_base::in);
        std::vector<int> banks;

        if (!ifs) {
            std::cout << "Failed to open file.\n";
        }
        else {
            // Read the file.
            std::string str;
            while (ifs >> str) {
                banks.push_back(std::stoi(str));
            }
        }

        return banks;
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

        std::vector<int> banks = getInput(argv[1]);
        if (!banks.empty()) {
            auto count = Mem_reallocation::run(banks);
            assert((count == 4074));
            std::cout << "Cycles until repeat, part 1: " << count << "\n";
        }
    }
    return 0;
}

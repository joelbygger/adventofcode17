/**
 *
 * Program reads a file. A bit of error checking is applied.
 *
 */
#include "jump_instructions.hpp"
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
        std::vector<int> instructions;

        if (!ifs) {
            std::cout << "Failed to open file.\n";
        }
        else {
            // Read the file.
            std::string row;
            while (std::getline(ifs, row)) {
                instructions.push_back(std::stoi(row));
            }
        }

        return instructions;
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

        std::vector<int> instructions = getInput(argv[1]);
        if (!instructions.empty()) {
            auto count = Jump_instructions::to_exit(instructions, false);
            assert((count == 356945));
            std::cout << "Steps to reach exit, part 1: " << count << "\n";

            count = Jump_instructions::to_exit(instructions, true);
            assert((count == 28372145));
            std::cout << "Steps to reach exit, part 2: " << count << "\n";
        }
    }
    return 0;
}

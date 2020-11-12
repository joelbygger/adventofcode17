/**
 *
 * Program reads a file. A bit of error checking is applied.
 *
 */
#include "checksum.hpp"
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
    std::vector<std::vector<int>> getInput(const char* path)
    {
        std::ifstream ifs(path, std::ios_base::in);
        std::vector<std::vector<int>> numbers;

        if (!ifs) {
            std::cout << "Failed to open file.\n";
        }
        else {
            // Read the file.
            std::string row;
            while (std::getline(ifs, row)) {
                std::istringstream rowSs(row);
                std::vector<int> rowVec;
                int num = 0;

                while (rowSs >> num) {
                    rowVec.push_back(num);
                }
                numbers.push_back(rowVec);
            }
        }

        return numbers;
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

        std::vector<std::vector<int>> numbers = getInput(argv[1]);
        if (!numbers.empty()) {
            auto checksum = Checksum::calc(numbers);
            assert((checksum == 45158));
            std::cout << "Checksum is: " << checksum << "\n";
        }
    }
    return 0;
}

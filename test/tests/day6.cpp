#include "mem_reallocation.hpp"
#include <catch2/catch.hpp>

TEST_CASE("Memory reallocations", "[woot]")
{
    SECTION("Task 1 examples")
    {
        std::vector<int> mem = { 0, 2, 7, 0 };
        REQUIRE(Mem_reallocation::run(mem) == 5);
    }
    SECTION("Task 2 examples")
    {
        std::vector<int> mem = { 0, 2, 7, 0 };
        REQUIRE(Mem_reallocation::run(mem) == 5);
        REQUIRE(Mem_reallocation::run(mem) == 4);
    }
}

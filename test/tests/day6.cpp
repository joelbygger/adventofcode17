#include "mem_reallocation.hpp"
#include <catch2/catch.hpp>

TEST_CASE("Memory reallocations", "[woot]")
{
    SECTION("Task 1 examples")
    {
        REQUIRE(Mem_reallocation::run({ 0, 2, 7, 0 }) == 5);
    }
}

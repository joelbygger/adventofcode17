#include "checksum.hpp"
#include <catch2/catch.hpp>

TEST_CASE("Checksum calculator", "[woot]")
{
    SECTION("Task 1 examples")
    {
        REQUIRE(Checksum::calc({ { 5, 1, 9, 5 }, { 7, 5, 3 }, { 2, 4, 6, 8 } }) == 18);
    }
}

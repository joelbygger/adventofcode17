#include "jump_instructions.hpp"
#include <catch2/catch.hpp>

TEST_CASE("Jump instructions calculator", "[woot]")
{
    SECTION("Task 1 examples")
    {
        REQUIRE(Jump_instructions::to_exit({ 0, 3, 0, 1, -3 }) == 5);
    }
}

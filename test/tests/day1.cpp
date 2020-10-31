#include "captcha.hpp"
#include <catch2/catch.hpp>

TEST_CASE("Captcha accumulator", "[woot]")
{
    SECTION("Test with Advents example captcha")
    {
        REQUIRE(Captcha::accumulator({ 1, 1, 2, 2 }) == 3);
        REQUIRE(Captcha::accumulator({ 1, 1, 1, 1 }) == 4);
        REQUIRE(Captcha::accumulator({ 1, 2, 3, 4 }) == 0);
        REQUIRE(Captcha::accumulator({ 9, 1, 2, 1, 2, 1, 2, 9 }) == 9);
    }
}

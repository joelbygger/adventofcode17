#include "captcha.hpp"
#include <catch2/catch.hpp>

TEST_CASE("Captcha accumulator", "[woot]")
{
    SECTION("Task 1 examples")
    {
        REQUIRE(Captcha::accumulator({ 1, 1, 2, 2 }, Captcha::check_step::next) == 3);
        REQUIRE(Captcha::accumulator({ 1, 1, 1, 1 }, Captcha::check_step::next) == 4);
        REQUIRE(Captcha::accumulator({ 1, 2, 3, 4 }, Captcha::check_step::next) == 0);
        REQUIRE(Captcha::accumulator({ 9, 1, 2, 1, 2, 1, 2, 9 }, Captcha::check_step::next) == 9);
    }

    SECTION("Task 2 examples")
    {
        REQUIRE(Captcha::accumulator({ 1, 2, 1, 2 }, Captcha::check_step::next_half) == 6);
        REQUIRE(Captcha::accumulator({ 1, 2, 2, 1 }, Captcha::check_step::next_half) == 0);
        REQUIRE(Captcha::accumulator({ 1, 2, 3, 4, 2, 5 }, Captcha::check_step::next_half) == 4);
        REQUIRE(Captcha::accumulator({ 1, 2, 3, 1, 2, 3 }, Captcha::check_step::next_half) == 12);
        REQUIRE(Captcha::accumulator({ 1, 2, 1, 3, 1, 4, 1, 5 }, Captcha::check_step::next_half) == 4);
    }
}

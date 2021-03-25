/*
 * Testing for Static Library
 */

#include "catch2/catch2.hpp"
#include "libstatic/StaticLib.h"

TEST_CASE("StaticLibTest", "[testStaticLib]") {
    StaticLib sl(42);

    REQUIRE(sl.testMe(5) == 47);
}
/*
 * Tests for Dynamic library
 */

#include "catch2/catch2.hpp"
#include "libdynamic/DynamicLib.h"


TEST_CASE("DynamicLibTests", "[testDynamicLib]") {

    DynamicLib dl("Ciao");

    SECTION("BOMBER") {
        REQUIRE(dl.yesItsMe(5) == "Ciao5");
        REQUIRE(dl.yesItsMe(5) == "Ciao5");
    }

    REQUIRE(dl.yesItsMe(5) == "Ciao5");

}




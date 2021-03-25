/*
 * Tests for plain and simple class not part of a library
 */

#include "catch2/catch2.hpp"
#include "A.h"

TEST_CASE("ATest", "[As]") {
    REQUIRE(A::yes(5) == 25);
}


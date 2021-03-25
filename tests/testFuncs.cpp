/*
 * Test for the collection of functions in funcs.h
 */
#include "catch2/catch2.hpp"
#include "funcs.h"


TEST_CASE("FuncsTest", "[funcs]") {
    // Just because we can
    for (int j = 0; j < 10; ++j) {
        REQUIRE(foo(j) == j * j);
    }
}
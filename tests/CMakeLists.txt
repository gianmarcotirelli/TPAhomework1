# Sources that contain the tests
add_executable(catch2Test catch2Main.cpp) # Just this one contains BOOST_TEST_MAIN
target_sources(catch2Test PRIVATE
        testFuncs.cpp
        testDynamicLib.cpp
        testStaticLib.cpp
        testA.cpp)

# Libraries used in the tests
target_link_libraries(catch2Test
        libStatic
        libDynamic)

# Including headers
target_include_directories(catch2Test PRIVATE
        ../include) # Including this allows to simply write #include "funcs.h"

# Including sources
target_sources(catch2Test PRIVATE
        ../src/A.cpp)

#target_compile_options(catch2Test PRIVATE -Wa,-mbig-obj) # Solves assembler error of file too big

# Basic reference on how to write Boost Tests:
# https://www.boost.org/doc/libs/1_45_0/libs/test/doc/html/tutorials/hello-the-testing-world.html
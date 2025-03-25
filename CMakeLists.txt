cmake_minimum_required(VERSION 3.14)
project(PR3_1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(../PR3_1/lib/googletest)

include_directories(/opt/homebrew/opt/ncurses/include)
link_directories(/opt/homebrew/opt/ncurses/lib)

add_executable(PR3_1
        main.cpp
)

target_link_libraries(PR3_1)

add_executable(PR3_1_tests
        tests/tests.cpp
)

target_link_libraries(PR3_1_tests gtest gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(PR3_1_tests)

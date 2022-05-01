cmake_minimum_required(VERSION 3.12)

project(linear-systems-solver)

include_directories(src/shared)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(lib/googletest)

add_test(NAME test-linear-systems-solver COMMAND test-linear-systems-solver)
enable_testing()

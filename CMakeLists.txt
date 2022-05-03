cmake_minimum_required(VERSION 3.12)

project(linear-systems-solver)


add_subdirectory(./src)
add_subdirectory(./lib)

enable_testing()
add_subdirectory(./tests)

cmake_minimum_required(VERSION 3.12)

project(linear-systems-solver)

include_directories(src/common)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(lib/googletest)
add_subdirectory(lib/CLI11)

add_test(
	NAME test-matrix
	COMMAND test-matrix
)
add_test(
	NAME test-bigint
	COMMAND test-bigint
)
add_test(
	NAME test-rational
	COMMAND test-rational
)

enable_testing()

include_directories(lib/googletest/googletest/include)
add_executable(test-linear-systems-solver
	init.cpp
	Matrix/test_Size.cpp
	Matrix/test_Matrix.cpp
	BigInt/test_BigInt.cpp
	Rational/test_Rational.cpp
)
target_link_libraries(test-linear-systems-solver PRIVATE gtest)
target_link_libraries(test-linear-systems-solver PRIVATE matrix)
target_link_libraries(test-linear-systems-solver PRIVATE bigint)
target_link_libraries(test-linear-systems-solver PRIVATE rational)

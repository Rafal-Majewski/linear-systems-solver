include_directories(lib/googletest/googletest/include)
add_executable(test-matrix
	init.cpp
	Matrix/test_Size.cpp
	Matrix/test_Matrix.cpp
)
target_link_libraries(test-matrix PRIVATE gtest)
target_link_libraries(test-matrix PRIVATE matrix)

add_executable(test-bigint
	init.cpp
	BigInt/test_BigInt.cpp
)
target_link_libraries(test-bigint PRIVATE gtest)
target_link_libraries(test-bigint PRIVATE bigint)


add_executable(test-rational
	init.cpp
	Rational/test_Rational.cpp
)
target_link_libraries(test-rational PRIVATE gtest)
target_link_libraries(test-rational PRIVATE rational)


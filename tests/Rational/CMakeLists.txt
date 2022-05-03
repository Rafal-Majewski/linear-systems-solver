add_executable(test-rational
	./init.cpp
	./test_Rational.cpp
)
target_link_libraries(test-rational PRIVATE gtest)
target_link_libraries(test-rational PRIVATE rational)


add_test(
	NAME test-rational
	COMMAND test-rational
)

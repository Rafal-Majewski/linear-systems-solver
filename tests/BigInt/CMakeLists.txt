add_executable(test-bigint
	./init.cpp
	./test_BigInt.cpp
)
target_link_libraries(test-bigint PRIVATE gtest)
target_link_libraries(test-bigint PRIVATE bigint)


add_test(
	NAME test-bigint
	COMMAND test-bigint
)

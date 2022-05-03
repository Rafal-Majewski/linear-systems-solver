add_executable(test-matrix
	./init.cpp
	./test_Size.cpp
	./test_Matrix.cpp
)
target_link_libraries(test-matrix PRIVATE gtest)
target_link_libraries(test-matrix PRIVATE matrix)


add_test(
	NAME test-matrix
	COMMAND test-matrix
)

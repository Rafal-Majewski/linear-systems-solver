include_directories(
	lib/CLI11/include/CLI
)

add_executable(matrix-calculator
	./main.cpp
)


target_link_libraries(matrix-calculator PRIVATE CLI11)

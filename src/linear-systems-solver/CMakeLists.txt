include_directories(
	lib/CLI11/include/CLI
)


include_directories(
	.
)

add_executable(linear-systems-solver
	./main.cpp
)

add_library(linear-system
	./LinearSystem/LinearSystem.cpp
)


add_library(linear-system-solver
	./LinearSystemSolver/LinearSystemSolver.cpp
	./LinearSystemSolver/SolvingMethod/SolvingMethod.cpp
)

target_link_libraries(linear-systems-solver PRIVATE CLI11)
target_link_libraries(linear-systems-solver PRIVATE linear-system-solver)
target_link_libraries(linear-systems-solver PRIVATE matrix)
target_link_libraries(linear-systems-solver PRIVATE linear-system)

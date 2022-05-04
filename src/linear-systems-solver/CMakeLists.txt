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
	./LinearSystem/LinearSystemSize/LinearSystemSize.cpp
)


add_library(linear-system-solver
	./LinearSystemSolver/LinearSystemSolver.cpp
	./LinearSystemSolver/SolvingMethod/SolvingMethod.cpp
)

add_library(linear-system-reader
	./LinearSystemReader/LinearSystemReader.cpp
)

add_library(datatype
	./Datatype/Datatype.cpp
)

target_link_libraries(linear-systems-solver PRIVATE CLI11)
target_link_libraries(linear-systems-solver PRIVATE linear-system-solver)
target_link_libraries(linear-systems-solver PRIVATE matrix)
target_link_libraries(linear-systems-solver PRIVATE linear-system)
target_link_libraries(linear-systems-solver PRIVATE linear-system-reader)

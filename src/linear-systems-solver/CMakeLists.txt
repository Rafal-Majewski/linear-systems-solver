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
	./LinearSystem/InvalidLinearSystemSizeException/InvalidLinearSystemSizeException.cpp
)

add_library(solving-method
	./SolvingMethod/SolvingMethod.cpp
)


add_library(linear-system-solver
	./LinearSystemSolver/LinearSystemSolver.cpp
)


target_link_libraries(linear-system-solver PUBLIC linear-system)

add_library(linear-system-reader
	./LinearSystemReader/LinearSystemReader.cpp
)

add_library(datatype
	./Datatype/Datatype.cpp
)

add_library(linear-system-printer
	./LinearSystemPrinter/LinearSystemPrinter.cpp
)

add_library(linear-system-solving-algorithms
	./solvingalgorithms/GaussAlgorithm/GaussAlgorithm.cpp
)
target_link_libraries(linear-system-solving-algorithms
	PUBLIC linear-system-solver
)
target_link_libraries(linear-system-solving-algorithms
	PUBLIC linear-system
)


target_link_libraries(linear-systems-solver PUBLIC linear-system-solving-algorithms)
target_link_libraries(linear-systems-solver PUBLIC CLI11)
target_link_libraries(linear-systems-solver PUBLIC linear-system-solver)
target_link_libraries(linear-systems-solver PUBLIC matrix)
target_link_libraries(linear-systems-solver PUBLIC linear-system)
target_link_libraries(linear-systems-solver PUBLIC linear-system-reader)
target_link_libraries(linear-systems-solver PUBLIC linear-system-printer)
target_link_libraries(linear-systems-solver PUBLIC datatype)
target_link_libraries(linear-systems-solver PUBLIC bigint)
target_link_libraries(linear-systems-solver PUBLIC rational)


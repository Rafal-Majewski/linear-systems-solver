include_directories(
	lib/CLI11/include/CLI
)

include_directories(
	lib/eigen3/Eigen
)

include_directories(
	.
)

add_executable(matrix-calculator
	./main.cpp
)

add_library(matrix-reader
	./MatrixReader/MatrixReader.cpp
)
target_link_libraries(matrix-reader
	matrix
)

add_library(matrix-printer
	./MatrixPrinter/MatrixPrinter.cpp
)
target_link_libraries(matrix-printer
	matrix
)

add_library(matrix-operator
	./MatrixOperator/MatrixOperator.cpp
	./MatrixOperator/MatrixAdditionOperator.cpp
	./MatrixOperator/MatrixMultiplicationOperator.cpp
)
target_link_libraries(matrix-operator PUBLIC matrix)
add_library(matrix-generator
	./MatrixGenerator/MatrixGenerator.cpp
)
target_link_libraries(matrix-generator PUBLIC matrix)
target_link_libraries(matrix-calculator PUBLIC CLI11)
target_link_libraries(matrix-calculator PUBLIC matrix-reader)
target_link_libraries(matrix-calculator PUBLIC matrix-operator)
target_link_libraries(matrix-calculator PUBLIC matrix-generator)
target_link_libraries(matrix-calculator PUBLIC rational)
target_link_libraries(matrix-calculator PUBLIC bigint)
target_link_libraries(matrix-calculator PUBLIC matrix-printer)

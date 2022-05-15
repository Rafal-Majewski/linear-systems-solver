include_directories(
	lib/CLI11/include/CLI
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
add_library(matrix-operator
	./MatrixOperator/MatrixOperator.cpp
	./MatrixOperator/MatrixAdditionOperator.cpp
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

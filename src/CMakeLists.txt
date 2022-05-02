include_directories(
	lib/CLI11/include/CLI
)

add_executable(linear-systems-solver
	linear-systems-solver/main.cpp
)

add_executable(matrix-calculator
	matrix-calculator/main.cpp
)

add_library(matrix
	common/Matrix/Matrix.cpp
	common/Matrix/Size/Size.cpp
	common/Matrix/InvalidMatrixSizeException/InvalidMatrixSizeException.cpp
)

add_library(bigint
	common/BigInt/BigInt.cpp
	common/BigInt/utils/digitsOperations.cpp
)

add_library(rational
	common/Rational/Rational.cpp
)

add_library(linear-system
	common/LinearSystem/SolvingMethod/SolvingMethod.h
)

target_link_libraries(linear-systems-solver PRIVATE CLI11)

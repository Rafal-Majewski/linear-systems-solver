add_executable(linear-systems-solver
	linear-systems-solver/main.cpp
	linear-systems-solver/utils/ArgumentsManager/ArgumentsManager.cpp
	linear-systems-solver/utils/ArgumentsManager/Arguments/Arguments.cpp
	linear-systems-solver/utils/ArgumentsManager/ArgumentsBuilder/ArgumentsBuilder.cpp
)

add_executable(matrix-calculator matrix-calculator/main.cpp)

add_library(matrix
	shared/Matrix/Matrix.cpp
	shared/Matrix/Size/Size.cpp
	shared/Matrix/WrongMatrixSizeException/WrongMatrixSizeException.cpp
)

add_library(bigint
	shared/BigInt/BigInt.cpp
	shared/BigInt/utils/digitsOperations.cpp
)

add_library(rational
	shared/Rational/Rational.cpp
)

add_library(abstractargumentsmanager
	shared/AbstractArgumentsManager/AbstractArgumentsManager.cpp
	shared/AbstractArgumentsManager/AbstractArgumentsBuilder/AbstractArgumentsBuilder.cpp
	shared/AbstractArgumentsManager/Parameter/Parameter.cpp
	shared/AbstractArgumentsManager/Parameter/ValuedParameter.cpp
	shared/AbstractArgumentsManager/Parameter/NonValuedParameter.cpp
)

target_link_libraries(linear-systems-solver PRIVATE abstractargumentsmanager)

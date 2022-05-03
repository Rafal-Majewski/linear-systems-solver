add_library(matrix
	./Matrix/Matrix.cpp
	./Matrix/Size/Size.cpp
	./Matrix/InvalidMatrixSizeException/InvalidMatrixSizeException.cpp
)

add_library(bigint
	./BigInt/BigInt.cpp
	./BigInt/utils/digitsOperations.cpp
)

add_library(rational
	./Rational/Rational.cpp
)


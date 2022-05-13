add_library(matrix
	./Matrix/Matrix.cpp
	./Matrix/MatrixSize/MatrixSize.cpp
	./Matrix/InvalidMatrixSizeException/InvalidMatrixSizeException.cpp
)

add_library(bigint
	./BigInt/BigInt.cpp
	./BigInt/BigIntDigits/BigIntDigits.cpp
)

add_library(rational
	./Rational/Rational.cpp
)

add_library(datatype
	./Datatype/Datatype.cpp
)

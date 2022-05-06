add_library(matrix
	./Matrix/Matrix.tpp
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

# target_link_libraries(matrix
# 	bigint
# )

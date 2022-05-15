#include "./MatrixGenerator.hpp"


template <typename T>
long MatrixGenerator<T>::generateRandomLong() const {
	long randomLong;
	for (int i = 0; i < sizeof(long); ++i) {
		randomLong <<= 8;
		randomLong += rand() % 256;
	}
	return randomLong;
}

template <typename T>
T MatrixGenerator<T>::generateRandomNumber() const {
	return T(double(generateRandomLong() % (max - min + 1) + min)) / T(double(divisor));
}

template <typename T>
MatrixGenerator<T>::MatrixGenerator(
	int min,
	int max,
	int divisor
) : min(min),
	max(max),
	divisor(divisor) {
}


template <typename T>
Matrix<T> MatrixGenerator<T>::generate(MatrixSize size) {
	Matrix<T> matrix(size);
	for (int i = 0; i < size.rowsCount; ++i) {
		for (int j = 0; j < size.columnsCount; ++j) {
			matrix.set(i, j, generateRandomNumber());
		}
	}
	return matrix;
}

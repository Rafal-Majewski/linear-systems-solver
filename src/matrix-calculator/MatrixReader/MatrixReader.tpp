#include "./MatrixReader.hpp"


template <typename T>
MatrixSize MatrixReader<T>::readSize() const {
	int rowsCount;
	int columnsCount;
	std::cin >> rowsCount >> columnsCount;
	return MatrixSize(rowsCount, columnsCount);
}

template <typename T>
Matrix<T> MatrixReader<T>::readCoefficients(MatrixSize size) const {
	Matrix<T> coefficients(size);
	for (int y = 0; y < size.rowsCount; ++y) {
		for (int x = 0; x < size.columnsCount; ++x) {
			T coefficient;
			std::cin >> coefficient;
			coefficients.set(y, x, coefficient);
		}
	}
	return coefficients;
}

template <typename T>
Matrix<T> MatrixReader<T>::read() const {
	MatrixSize size = readSize();
	Matrix<T> coefficients = readCoefficients(size);
	return coefficients;
}

#include "./MatrixPrinter.hpp"
#include <iostream>


template <typename T>
void MatrixPrinter<T>::printSize(const Matrix<T>& matrix) const {
	std::cout << matrix.size.rowsCount << separator << matrix.size.columnsCount << std::endl;
}

template <typename T>
void MatrixPrinter<T>::printCoefficients(const Matrix<T>& matrix) const {
	for (int y = 0; y < matrix.size.rowsCount; y++) {
		std::cout << matrix.get(y, 0);
		for (int x = 1; x < matrix.size.columnsCount; x++) {
			std::cout << separator << matrix.get(y, x);
		}
		std::cout << '\n';
	}
}

template <typename T>
void MatrixPrinter<T>::print(const Matrix<T>& matrix) const {
	printSize(matrix);
	printCoefficients(matrix);
}

template <typename T>
MatrixPrinter<T>::MatrixPrinter(std::string separator) : separator(separator) {
}


#ifndef MATRIX_PRINTER_H_INCLUDED
#define MATRIX_PRINTER_H_INCLUDED

#include <Matrix/Matrix.hpp>


template <typename T>
class MatrixPrinter {
	private:
	void printSize(const Matrix<T>& matrix) const;
	void printCoefficients(const Matrix<T>& matrix) const;
	public:
	const std::string separator;
	void print(const Matrix<T>& matrix) const;
	MatrixPrinter(std::string separator);
};

#include "./MatrixPrinter.tpp"

#endif

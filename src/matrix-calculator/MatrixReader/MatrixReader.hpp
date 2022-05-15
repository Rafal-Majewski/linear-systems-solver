#ifndef MATRIX_READER_H_INCLUDED
#define MATRIX_READER_H_INCLUDED

#include <Matrix/Matrix.cpp>
#include <Matrix/MatrixSize/MatrixSize.cpp>
#include <iostream>


template <typename T>
class MatrixReader {
	private:
	MatrixSize readSize() const;
	Matrix<T> readCoefficients(MatrixSize size) const;

	public:
	Matrix<T> read() const;
};

#include "./MatrixReader.tpp"

#endif

#ifndef MATRIX_GENERATOR_H_INCLUDED
#define MATRIX_GENERATOR_H_INCLUDED

#include <iostream>
#include <random>
#include <vector>
#include <Matrix/Matrix.hpp>
#include <Matrix/MatrixSize/MatrixSize.hpp>


template <typename T>
class MatrixGenerator {
	private:
	long generateRandomLong() const;
	T generateRandomNumber() const;
	const int min;
	const int max;
	const int divisor;

	public:
	MatrixGenerator(int min, int max, int divisor);
	Matrix<T> generate(MatrixSize size);
};

#include "./MatrixGenerator.tpp"

#endif

#ifndef MATRIX_MULTIPLICATION_OPERATOR_H_INCLUDED
#define MATRIX_MULTIPLICATION_OPERATOR_H_INCLUDED

#include "./MatrixOperator.hpp"


template <typename T>
class MatrixMultiplicationOperator : public MatrixOperator<T> {
	public:
	Matrix<T> operate(Matrix<T> lhs, Matrix<T> rhs) const override;
};

#include "./MatrixMultiplicationOperator.tpp"

#endif
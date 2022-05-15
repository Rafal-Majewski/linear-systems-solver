#ifndef ADDITION_OPERATOR_H_INCLUDED
#define ADDITION_OPERATOR_H_INCLUDED

#include "./MatrixOperator.hpp"


template <typename T>
class MatrixAdditionOperator : public MatrixOperator<T> {
	public:
	Matrix<T> operate(Matrix<T> lhs, Matrix<T> rhs) const override;
};

#include "./MatrixAdditionOperator.tpp"

#endif
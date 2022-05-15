#ifndef MATRIX_OPERATOR_H_INCLUDED
#define MATRIX_OPERATOR_H_INCLUDED

#include <Matrix/Matrix.hpp>

template <typename T>
class MatrixOperator {
	public:
	virtual Matrix<T> operate(Matrix<T> lhs, Matrix<T> rhs) const;
};

#endif

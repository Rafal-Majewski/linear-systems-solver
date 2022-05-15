#include "./MatrixMultiplicationOperator.hpp"


template <typename T>
Matrix<T> MatrixMultiplicationOperator<T>::operate(Matrix<T> lhs, Matrix<T> rhs) const {
	return lhs * rhs;
}

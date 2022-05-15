#include "./MatrixAdditionOperator.hpp"


template <typename T>
Matrix<T> MatrixAdditionOperator<T>::operate(Matrix<T> lhs, Matrix<T> rhs) const {
	return lhs + rhs;
}

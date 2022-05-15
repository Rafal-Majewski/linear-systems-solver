#include "./LinearSystem.hpp"


template <typename T>
void LinearSystem<T>::assertValidCoefficientsCount() const {
	if (coefficients.size.rowsCount != size.equationsCount) {
		throw InvalidLinearSystemSizeException(
			"Coefficients rows count is not equal to constants count"
		);
	}
}

template <typename T>
void LinearSystem<T>::assertQuadraticSize() const {
	if (size.equationsCount != size.variablesCount) {
		throw InvalidLinearSystemSizeException(
			"Currently only quadratic systems are supported"
		);
	}
}

template <typename T>
void LinearSystem<T>::assertValidInput() const {
	assertValidCoefficientsCount();
	assertQuadraticSize();
}

template <typename T>
LinearSystem<T>::LinearSystem(
	Matrix<T> coefficients,
	std::vector<T> constants
) : size(LinearSystemSize(coefficients.size.rowsCount, coefficients.size.columnsCount)),
	coefficients(coefficients),
	constants(constants) {
	assertValidInput();
}

template <typename T>
LinearSystem<T>::LinearSystem(
	LinearSystemSize size,
	Matrix<T> coefficients,
	std::vector<T> constants
) : size(size),
	coefficients(coefficients),
	constants(constants) {
	assertValidInput();
}

template <typename T>
T LinearSystem<T>::getCoefficient(int equationIndex, int variableIndex) const {
	return coefficients.get(equationIndex, variableIndex);
}

template <typename T>
void LinearSystem<T>::substractRows(int targetRowIndex, int toSubstractRowIndex, T factor) {
	for (int x = 0; x < size.variablesCount; ++x) {
		coefficients.set(
			targetRowIndex,
			x,
			coefficients.get(targetRowIndex, x) - coefficients.get(toSubstractRowIndex, x) * factor
		);
	}
	constants[targetRowIndex] -= constants[toSubstractRowIndex] * factor;
}

template <typename T>
T LinearSystem<T>::getConstant(int equationIndex) const {
	return constants[equationIndex];
}

template <typename T>
void LinearSystem<T>::swapRows(int firstRowIndex, int secondRowIndex) {
	std::swap(constants[firstRowIndex], constants[secondRowIndex]);
	for (int x = 0; x < size.variablesCount; ++x) {
		T temp = coefficients.get(firstRowIndex, x);
		coefficients.set(firstRowIndex, x, coefficients.get(secondRowIndex, x));
		coefficients.set(secondRowIndex, x, temp);
	}
}

template <typename T>
void LinearSystem<T>::swapColumns(int firstColumnIndex, int secondColumnIndex) {
	for (int y = 0; y < size.equationsCount; ++y) {
		T temp = coefficients.get(y, firstColumnIndex);
		coefficients.set(y, firstColumnIndex, coefficients.get(y, secondColumnIndex));
		coefficients.set(y, secondColumnIndex, temp);
	}
}

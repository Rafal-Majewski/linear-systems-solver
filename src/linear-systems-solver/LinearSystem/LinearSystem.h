#ifndef LINEAR_SYSTEM_H_INCLUDED
#define LINEAR_SYSTEM_H_INCLUDED

// #include <matrix/Matrix.h>
#include <vector>
#include <string>
#include "./InvalidLinearSystemSizeException/InvalidLinearSystemSizeException.h"
#include <Matrix/Matrix.h>
#include <iostream>



template <typename T>
class LinearSystem {
	private:
	Matrix<T> coefficients;
	std::vector<T> constants;
	std::vector<std::string> variables;
	void assertValidVariablesCount() const;
	void assertValidCoefficientsCount() const;
	public:
	LinearSystem(
		Matrix<T> coefficients,
		std::vector<T> constants,
		std::vector<std::string> variables
	): coefficients(coefficients),
	constants(constants),
	variables(variables) {
		assertValidVariablesCount();
		assertValidCoefficientsCount();
	}
	template <typename>
	friend class LinearSystemPrinter;
};

template <typename T>
void LinearSystem<T>::assertValidVariablesCount() const {
	if (variables.size() != coefficients.size.columnsCount) {
		throw InvalidLinearSystemSizeException(
			"Variables count is not equal to coefficients columns count"
		);
	}
}

template <typename T>
void LinearSystem<T>::assertValidCoefficientsCount() const {
	if (coefficients.size.rowsCount != constants.size()) {
		throw InvalidLinearSystemSizeException(
			"Coefficients rows count is not equal to constants count"
		);
	}
}

// template <typename T>
// void LinearSystem<T>::updateIsDone() {
// 	isDone = false;
// }

#endif // LINEAR_SYSTEM_H_INCLUDED

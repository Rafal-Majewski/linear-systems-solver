#include "./LinearSystem.hpp"


template <typename T>
void LinearSystem<T>::assertValidVariablesCount() const {
	if (variables.size() != size.variablesCount) {
		throw InvalidLinearSystemSizeException(
			"Variables count is not equal to coefficients columns count"
		);
	}
}

template <typename T>
void LinearSystem<T>::assertValidCoefficientsCount() const {
	if (coefficients.size.rowsCount != size.equationsCount) {
		throw InvalidLinearSystemSizeException(
			"Coefficients rows count is not equal to constants count"
		);
	}
}

template <typename T>
LinearSystem<T>::LinearSystem(
	Matrix<T> coefficients,
	std::vector<T> constants,
	std::vector<std::string> variables
) : size(LinearSystemSize(coefficients.size.rowsCount, coefficients.size.columnsCount)),
	coefficients(coefficients),
	constants(constants),
	variables(variables) {
	assertValidVariablesCount();
	assertValidCoefficientsCount();
}

template <typename T>
LinearSystem<T>::LinearSystem(
	LinearSystemSize size,
	Matrix<T> coefficients,
	std::vector<T> constants,
	std::vector<std::string> variables
) : size(size),
	coefficients(coefficients),
	constants(constants),
	variables(variables) {
	assertValidVariablesCount();
	assertValidCoefficientsCount();
}

template <typename T>
T LinearSystem<T>::getCoefficient(int equationIndex, int variableIndex) const {
	return coefficients.get(equationIndex, variableIndex);
}

template <typename T>
void LinearSystem<T>::substractRows(int sourceRowIndex, int operandRowIndex, T factor) {
	std::cout << "Substracting rows " << sourceRowIndex << " and " << operandRowIndex << " with factor " << factor << std::endl;
	for (int x = 0; x < size.variablesCount; ++x) {
		std::cout << "debug: " << sourceRowIndex << " " << operandRowIndex << " " << x << " " << factor << " " << coefficients.get(sourceRowIndex, x) - coefficients.get(operandRowIndex, x) * factor << std::endl;
		coefficients.set(
			sourceRowIndex,
			x,
			coefficients.get(sourceRowIndex, x) - coefficients.get(operandRowIndex, x) * factor
		);
	}
	constants[sourceRowIndex] -= constants[operandRowIndex] * factor;
}




	// LinearSystem(
	// 	Matrix<T> coefficients,
	// 	std::vector<T> constants,
	// 	std::vector<std::string> variables
	// ): coefficients(coefficients),
	// constants(constants),
	// variables(variables) {
	// 	assertValidVariablesCount();
	// 	assertValidCoefficientsCount();
	// }
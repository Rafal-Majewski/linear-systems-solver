// #include <matrix/Matrix.h>
#include <vector>
#include <string>
#include "./InvalidLinearSystemSizeException/InvalidLinearSystemSizeException.h"
#include <Matrix/Matrix.h>

template <typename T>
class LinearSystem {
	private:
	bool isDone;
	Matrix<T> coefficients;
	std::vector<T> constants;
	std::vector<std::string> variables;
	void updateIsDone();
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
		updateIsDone();
	}
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

template <typename T>
void LinearSystem<T>::updateIsDone() {
	isDone = false;
}

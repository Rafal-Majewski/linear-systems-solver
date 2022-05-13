#ifndef LINEAR_SYSTEM_H_INCLUDED
#define LINEAR_SYSTEM_H_INCLUDED


#include <vector>
#include <string>
#include "./InvalidLinearSystemSizeException/InvalidLinearSystemSizeException.hpp"
#include <Matrix/Matrix.hpp>
#include "./LinearSystemSize/LinearSystemSize.hpp"


template <typename T>
class LinearSystem {
	private:
	Matrix<T> coefficients;
	std::vector<T> constants;
	std::vector<std::string> variables;
	void assertValidVariablesCount() const;
	void assertValidCoefficientsCount() const;
	void assertQuadraticSize() const;
	void assertValidInput() const;
	public:
	T getCoefficient(int equationIndex, int variableIndex) const;
	T getConstant(int equationIndex) const;
	std::string getVariable(int variableIndex) const;
	void substractRows(int targetRowIndex, int toSubstractRowIndex, T factor);
	const LinearSystemSize size;
	LinearSystem(
		Matrix<T> coefficients,
		std::vector<T> constants,
		std::vector<std::string> variables
	);
	LinearSystem(
		LinearSystemSize size,
		Matrix<T> coefficients,
		std::vector<T> constants,
		std::vector<std::string> variables
	);
};

#include "./LinearSystem.tpp"

#endif // LINEAR_SYSTEM_H_INCLUDED

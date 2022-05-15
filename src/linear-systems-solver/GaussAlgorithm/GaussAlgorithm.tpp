#include "./GaussAlgorithm.hpp"


template <typename T>
LinearSystem<T> AbstractGaussAlgorithm<T>::eliminate(
	LinearSystem<T> a_linearSystem,
	std::vector<int> &originalVariablesIndexes
) const {
	LinearSystem<T> linearSystem = a_linearSystem;
	for (int x = 0; x < linearSystem.size.variablesCount; ++x) {
		choose(linearSystem, x, x, originalVariablesIndexes);
		for (int y = x + 1; y < linearSystem.size.equationsCount; ++y) {
			linearSystem.substractRows(
				y,
				x,
				linearSystem.getCoefficient(y, x) / linearSystem.getCoefficient(x, x)
			);
		}
	}
	return linearSystem;
}

template <typename T>
std::vector<T> AbstractGaussAlgorithm<T>::extractSolutions(
	const LinearSystem<T> &linearSystem,
	std::vector<int> &originalVariablesIndexes
) const {
	std::vector<T> solutions(linearSystem.size.variablesCount);
	for (int y = linearSystem.size.variablesCount - 1; y >= 0; --y) {
		T value = linearSystem.getConstant(y);
		for (int x = y + 1; x < linearSystem.size.variablesCount; ++x) {
			value -= linearSystem.getCoefficient(y, x) * solutions[x];
		} 
		value /= linearSystem.getCoefficient(y, y);
		solutions[y] = value;
	}
	std::vector<T> originalSolutions(solutions.size());
	for (int i = 0; i < originalSolutions.size(); ++i) {
		originalSolutions[originalVariablesIndexes[i]] = solutions[i];
	}
	return originalSolutions;
}

template <typename T>
std::vector<T> AbstractGaussAlgorithm<T>::solve(
	LinearSystem<T> a_linearSystem
) const {
	std::vector<int> originalVariablesIndexes(a_linearSystem.size.variablesCount);
	for (int i = 0; i < a_linearSystem.size.variablesCount; ++i) {
		originalVariablesIndexes[i] = i;
	}
	LinearSystem<T> linearSystem = eliminate(a_linearSystem, originalVariablesIndexes);
	return extractSolutions(linearSystem, originalVariablesIndexes);
}

template <typename T>
void GaussAlgorithm<T>::choose(
	LinearSystem<T> &linearSystem,
	int equationIndex,
	int variableIndex,
	std::vector<int> &originalVariablesIndexes
) const {
}

template <typename T>
void PartialGaussAlgorithm<T>::choose(
	LinearSystem<T> &linearSystem,
	int equationIndex,
	int variableIndex,
	std::vector<int> &originalVariablesIndexes
) const {
	using std::abs;
	T maxCoefficient = abs(linearSystem.getCoefficient(equationIndex, variableIndex));
	int maxCoefficientEquationIndex = equationIndex;
	for (int y = equationIndex + 1; y < linearSystem.size.equationsCount; ++y) {
		T coefficient = abs(linearSystem.getCoefficient(y, variableIndex));
		if (coefficient > maxCoefficient) {
			maxCoefficient = coefficient;
			maxCoefficientEquationIndex = y;
		}
	}
	if (maxCoefficientEquationIndex != equationIndex) {
		linearSystem.swapRows(equationIndex, maxCoefficientEquationIndex);
	}
}

template <typename T>
void FullGaussAlgorithm<T>::choose(
	LinearSystem<T> &linearSystem,
	int equationIndex,
	int variableIndex,
	std::vector<int> &originalVariablesIndexes
) const {
	using std::abs;
	T maxCoefficient = T(0);
	int maxCoefficientEquationIndex = equationIndex;
	int maxCoefficientVariableIndex = variableIndex;
	for (int y = equationIndex; y < linearSystem.size.equationsCount; ++y) {
		for (int x = variableIndex; x < linearSystem.size.variablesCount; ++x) {
			T coefficient = abs(linearSystem.getCoefficient(y, x));
			if (coefficient > maxCoefficient) {
				maxCoefficient = coefficient;
				maxCoefficientEquationIndex = y;
				maxCoefficientVariableIndex = x;
			}
		}
	}
	if (maxCoefficientEquationIndex != equationIndex) {
		linearSystem.swapRows(equationIndex, maxCoefficientEquationIndex);
	}
	if (maxCoefficientVariableIndex != variableIndex) {
		linearSystem.swapColumns(variableIndex, maxCoefficientVariableIndex);
		std::swap(originalVariablesIndexes[variableIndex], originalVariablesIndexes[maxCoefficientVariableIndex]);
	}
}

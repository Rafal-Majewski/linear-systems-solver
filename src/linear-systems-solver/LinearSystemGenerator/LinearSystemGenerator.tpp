#include "./LinearSystemGenerator.hpp"
#include <Matrix/MatrixSize/MatrixSize.hpp>


template <typename T>
std::string LinearSystemGenerator<T>::generateVariable(int variableIndex) {
	return "x" + std::to_string(variableIndex);
}

template <typename T>
long LinearSystemGenerator<T>::generateRandomLong() {
	long randomLong;
	for (int i = 0; i < sizeof(long); ++i) {
		randomLong <<= 8;
		randomLong += rand() % 256;
	}
	return randomLong;
}

template <typename T>
T LinearSystemGenerator<T>::generateRandomNumber() {
	return T(generateRandomLong() % (max - min + 1) + min) / T(divisor);
}

template <typename T>
LinearSystemGenerator<T>::LinearSystemGenerator(
	int a_size,
	int min,
	int max,
	int divisor
) : size(LinearSystemSize(a_size, a_size)),
	min(min),
	max(max),
	divisor(divisor) {
}


template <typename T>
LinearSystem<T> LinearSystemGenerator<T>::generate() {
	std::vector<std::string> variables(size.variablesCount);
	for (int variableIndex = 0; variableIndex < size.variablesCount; ++variableIndex) {
		variables[variableIndex] = generateVariable(variableIndex);
	}
	std::vector<T> constants(size.equationsCount);
	for (int equationIndex = 0; equationIndex < size.equationsCount; ++equationIndex) {
		constants[equationIndex] = generateRandomNumber();
	}
	Matrix<T> coefficients(MatrixSize(size.equationsCount, size.variablesCount));
	for (int equationIndex = 0; equationIndex < size.equationsCount; ++equationIndex) {
		for (int variableIndex = 0; variableIndex < size.variablesCount; ++variableIndex) {
			coefficients.set(
				equationIndex,
				variableIndex,
				generateRandomNumber()
			);
		}
	}
	return LinearSystem<T>(size, coefficients, constants, variables);
}
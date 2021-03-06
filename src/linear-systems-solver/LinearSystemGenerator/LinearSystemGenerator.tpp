#include "./LinearSystemGenerator.hpp"
#include <Matrix/MatrixSize/MatrixSize.hpp>


template <typename T>
long LinearSystemGenerator<T>::generateRandomLong() const {
	long randomLong;
	for (int i = 0; i < sizeof(long); ++i) {
		randomLong <<= 8;
		randomLong += rand() % 256;
	}
	return randomLong;
}

template <typename T>
T LinearSystemGenerator<T>::generateRandomNumber() const {
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
std::pair<LinearSystem<T>, std::vector<T>> LinearSystemGenerator<T>::generate() const {
	std::vector<T> solutions(size.variablesCount);
	for (int y = 0; y < size.variablesCount; ++y) {
		solutions[y] = generateRandomNumber();
	}
	Matrix<T> solutionsMatrix(solutions);
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
	Matrix<T> constantsMatrix = coefficients * solutionsMatrix;
	std::vector<T> constants(size.equationsCount);
	for (int equationIndex = 0; equationIndex < size.equationsCount; ++equationIndex) {
		constants[equationIndex] = constantsMatrix.get(equationIndex, 0);
	}
	return std::make_pair(
		LinearSystem<T>(size, coefficients, constants),
		solutions
	);
}

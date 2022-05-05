#include <LinearSystem/LinearSystem.h>
#include <LinearSystem/LinearSystemSize/LinearSystemSize.h>
#include <iostream>


template <typename T>
class LinearSystemReader {
	private:
	LinearSystemSize readSize() const;
	std::pair<Matrix<T>, std::vector<T>> readCoefficientsAndConstants(LinearSystemSize size) const;
	std::vector<std::string> readVariables(LinearSystemSize size) const;

	public:
	LinearSystem<T> read() const;
};

template <typename T>
LinearSystemSize LinearSystemReader<T>::readSize() const {
	int equationsCount;
	int variablesCount;
	std::cin >> equationsCount >> variablesCount;
	return LinearSystemSize(equationsCount, variablesCount);
}

template <typename T>
std::vector<std::string> LinearSystemReader<T>::readVariables(LinearSystemSize size) const {
	std::vector<std::string> variables(size.variablesCount);
	for (int i = 0; i < size.variablesCount; i++) {
		std::cin >> variables[i];
	}
	return variables;
}

template <typename T>
std::pair<Matrix<T>, std::vector<T>> LinearSystemReader<T>::readCoefficientsAndConstants(LinearSystemSize size) const {
	Matrix<T> coefficients(MatrixSize(size.equationsCount, size.variablesCount));
	std::vector<T> constants(size.equationsCount);
	for (int ei = 0; ei < size.equationsCount; ++ei) {
		for (int vi = 0; vi < size.variablesCount; ++vi) {
			std::cin >> coefficients[ei][vi];
		}
		std::cin >> constants[ei];
	}
	return std::make_pair(coefficients, constants);
}

template <typename T>
LinearSystem<T> LinearSystemReader<T>::read() const {
	LinearSystemSize size = readSize();
	auto [coefficients, constants] = readCoefficientsAndConstants(size);
	std::vector<std::string> variables = readVariables(size);
	return LinearSystem<T>(coefficients, constants, variables);
}

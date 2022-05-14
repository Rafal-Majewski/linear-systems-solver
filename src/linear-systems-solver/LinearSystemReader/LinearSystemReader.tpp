#include "./LinearSystemReader.hpp"


template <typename T>
LinearSystemSize LinearSystemReader<T>::readSize() const {
	int equationsCount;
	int variablesCount;
	std::cin >> equationsCount >> variablesCount;
	return LinearSystemSize(equationsCount, variablesCount);
}

template <typename T>
std::pair<Matrix<T>, std::vector<T>> LinearSystemReader<T>::readCoefficientsAndConstants(LinearSystemSize size) const {
	Matrix<T> coefficients(MatrixSize(size.equationsCount, size.variablesCount));
	std::vector<T> constants(size.equationsCount);
	for (int ei = 0; ei < size.equationsCount; ++ei) {
		for (int vi = 0; vi < size.variablesCount; ++vi) {
			T coefficient;
			std::cin >> coefficient;
			coefficients.set(ei, vi, coefficient);
		}
		T constant;
		std::cin >> constant;
		constants[ei] = constant;
	}
	return std::make_pair(coefficients, constants);
}

template <typename T>
LinearSystem<T> LinearSystemReader<T>::read() const {
	LinearSystemSize size = readSize();
	auto [coefficients, constants] = readCoefficientsAndConstants(size);
	
	return LinearSystem<T>(size, coefficients, constants);
}

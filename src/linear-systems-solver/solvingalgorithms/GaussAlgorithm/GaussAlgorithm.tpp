#include "./GaussAlgorithm.hpp"


template <typename T>
LinearSystem<T> GaussAlgorithm<T>::eliminate(LinearSystem<T> a_linearSystem) const {
	LinearSystem<T> linearSystem = a_linearSystem;
	for (int x = 0; x < linearSystem.size.variablesCount; ++x) {
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
std::vector<T> GaussAlgorithm<T>::extractSolutions(const LinearSystem<T> &linearSystem) const {
	std::vector<T> solutions(linearSystem.size.variablesCount);
	for (int y = linearSystem.size.variablesCount - 1; y >= 0; --y) {
		T value = linearSystem.getConstant(y);
		for (int x = y + 1; x < linearSystem.size.variablesCount; ++x) {
			value -= linearSystem.getCoefficient(y, x) * solutions[x];
		} 
		value /= linearSystem.getCoefficient(y, y);
		solutions[y] = value;
	}
	return solutions;
}


template <typename T>
std::vector<T> GaussAlgorithm<T>::solve(LinearSystem<T> a_linearSystem) const {
	LinearSystem<T> linearSystem = eliminate(a_linearSystem);
	return extractSolutions(linearSystem);
}

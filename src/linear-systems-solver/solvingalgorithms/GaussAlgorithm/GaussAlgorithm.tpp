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
std::vector<std::pair<std::string, T>> GaussAlgorithm<T>::extractSolutions(const LinearSystem<T> &linearSystem) const {
	std::vector<std::pair<std::string, T>> solutions(linearSystem.size.variablesCount);
	for (int y = linearSystem.size.variablesCount - 1; y >= 0; --y) {
		std::string variable = linearSystem.getVariable(y);
		T value = linearSystem.getConstant(y);
		for (int x = y + 1; x < linearSystem.size.variablesCount; ++x) {
			value -= linearSystem.getCoefficient(y, x) * solutions[x].second;
		} 
		value /= linearSystem.getCoefficient(y, y);
		solutions[y] = std::make_pair(variable, value);
	}
	return solutions;
}


template <typename T>
std::vector<std::pair<std::string, T>> GaussAlgorithm<T>::solve(LinearSystem<T> a_linearSystem) const {
	LinearSystem<T> linearSystem = eliminate(a_linearSystem);
	return extractSolutions(linearSystem);
}


// template <typename T>
// bool GaussAlgorithm<T>::checkIsAlreadyDone() const {
// 	for (
// 		int y = 0, expectedStairX = 0;
// 		y < this->linearSystem.size.equationsCount;
// 		++y
// 	) {
// 		for (int x = 0; x < this->linearSystem.size.variablesCount; ++x) {
// 			if (this->linearSystem.getCoefficient(y, x) == 0) {
// 				if (x == expectedStairX) {
// 					++expectedStairX;
// 				}
// 				continue;
// 			}
// 			if (x < expectedStairX) {
// 				return false;
// 			}
// 			expectedStairX = x + 1;
// 			break;
// 		}
// 	}
// 	return true;
// }

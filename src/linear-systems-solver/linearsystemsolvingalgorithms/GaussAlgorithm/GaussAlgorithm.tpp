#include "./GaussAlgorithm.hpp"


template <typename T>
LinearSystem<T> GaussAlgorithm<T>::solve(LinearSystem<T> a_linearSystem) const {
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

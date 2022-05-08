#include "./GaussAlgorithm.hpp"


template <typename T>
bool GaussAlgorithm<T>::solveStep() {
	return false;
}

template <typename T>
bool GaussAlgorithm<T>::checkIsAlreadyDone() const {
	for (
		int y = 0, expectedStairX = 0;
		y < this->linearSystem.size.equationsCount;
		++y
	) {
		for (int x = 0; x < this->linearSystem.size.variablesCount; ++x) {
			if (this->linearSystem.getCoefficient(y, x) == 0) {
				if (x == expectedStairX) {
					++expectedStairX;
				}
				continue;
			}
			if (x < expectedStairX) {
				return false;
			}
			expectedStairX = x + 1;
			break;
		}
	}
	return true;
}

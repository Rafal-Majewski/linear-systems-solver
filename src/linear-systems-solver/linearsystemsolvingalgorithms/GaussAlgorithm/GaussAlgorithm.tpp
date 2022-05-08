#include "./GaussAlgorithm.hpp"


template <typename T>
bool GaussAlgorithm<T>::solveStep() {
	// todo coef[0][0] swap with non zero
	// error todo here
	this->linearSystem.substractRows(
		1,
		0,
		this->linearSystem.getCoefficient(1, 0) / this->linearSystem.getCoefficient(0, 0)
	);
	return true;
}

#include <iostream>

template <typename T>
bool GaussAlgorithm<T>::checkIsAlreadyDone() const {
	for (
		int y = 0, expectedStairX = 0;
		y < this->linearSystem.size.equationsCount;
		++y
	) {
		for (int x = 0; x < this->linearSystem.size.variablesCount; ++x) {
			std::cout << "debug: " << y << " " << x << " " << expectedStairX << " " << this->linearSystem.getCoefficient(y, x) << std::endl;
			if (this->linearSystem.getCoefficient(y, x) == 0) {
				std::cout << "taken" << std::endl;
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

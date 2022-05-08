#include "./LinearSystemSolvingAlgorithm.hpp"


template <typename T>
LinearSystemSolvingAlgorithm<T>::LinearSystemSolvingAlgorithm(
	LinearSystem<T> &linearSystem
) : linearSystem(linearSystem) {
}

template <typename T>
LinearSystem<T> LinearSystemSolvingAlgorithm<T>::getLinearSystem() const {
	return linearSystem;
}


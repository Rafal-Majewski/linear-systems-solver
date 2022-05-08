#include "./LinearSystemSolvingAlgorithm.hpp"


template <typename T>
LinearSystemSolvingAlgorithm<T>::LinearSystemSolvingAlgorithm(
	LinearSystem<T> &linearSystem
) : linearSystem(linearSystem) {
}

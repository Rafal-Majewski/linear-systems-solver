#include "./LinearSystemSolver.hpp"
#include "./LinearSystemSolvingAlgorithm/LinearSystemSolvingAlgorithm.hpp"


template <typename T>
bool LinearSystemSolver<T>::getIsDone() const {
	return isDone;
}

template <typename T>
LinearSystem<T> LinearSystemSolver<T>::getLinearSystem() const {
	return linearSystem;
}

template <typename T>
LinearSystemSolver<T>::LinearSystemSolver(
	LinearSystem<T> linearSystem,
	LinearSystemSolvingAlgorithm<T> *algorithm
) : linearSystem(linearSystem), algorithm(algorithm) {

	isDone = algorithm->checkIsAlreadyDone();
}

template <typename T>
void LinearSystemSolver<T>::solveStep() {
	isDone = algorithm->solveStep();
}

#include "./LinearSystemSolver.hpp"
#include "./LinearSystemSolvingAlgorithm/LinearSystemSolvingAlgorithm.hpp"


template <typename T>
bool LinearSystemSolver<T>::getIsDone() const {
	return isDone;
}

template <typename T>
LinearSystem<T> LinearSystemSolver<T>::getLinearSystem() const {
	return algorithm->getLinearSystem();
}

template <typename T>
LinearSystemSolver<T>::LinearSystemSolver(
	LinearSystemSolvingAlgorithm<T> *algorithm
) : algorithm(algorithm) {
	isDone = algorithm->checkIsAlreadyDone();
}

template <typename T>
void LinearSystemSolver<T>::solveStep() {
	isDone = algorithm->solveStep();
}

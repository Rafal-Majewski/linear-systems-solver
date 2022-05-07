#include "./LinearSystemSolver.hpp"


template <typename T>
LinearSystem<T> LinearSystemSolver<T>::getLinearSystem() const {
	return linearSystem;
}

template <typename T>
void LinearSystemSolver<T>::updateIsDone() {
	// todo
	isDone = true;
}



template <typename T>
LinearSystemSolver<T>::LinearSystemSolver(
	SolvingMethod solvingMethod,
	LinearSystem<T> linearSystem
) : solvingMethod(solvingMethod), linearSystem(linearSystem) {
	updateIsDone();
};

template <typename T>
bool LinearSystemSolver<T>::getIsDone() const {
	return isDone;
}

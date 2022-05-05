#ifndef LINEAR_SYSTEM_SOLVER_H_INCLUDED
#define LINEAR_SYSTEM_SOLVER_H_INCLUDED

#include "./SolvingMethod/SolvingMethod.h"
#include "../LinearSystem/LinearSystem.h"
#include <iostream>


template <typename T>
class LinearSystemSolver {
	private:
	const LinearSystem<T> linearSystem;
	bool isDone = false;
	void updateIsDone();
	public:
	bool getIsDone() const;
	LinearSystem<T> getLinearSystem() const;
	const SolvingMethod solvingMethod;
	LinearSystemSolver(
		SolvingMethod solvingMethod,
		LinearSystem<T> linearSystem
	);
};

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

#endif

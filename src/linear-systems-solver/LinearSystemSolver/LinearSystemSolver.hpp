#ifndef LINEAR_SYSTEM_SOLVER_H_INCLUDED
#define LINEAR_SYSTEM_SOLVER_H_INCLUDED

#include "./SolvingMethod/SolvingMethod.hpp"
#include <LinearSystem/LinearSystem.hpp>
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

#include "./LinearSystemSolver.tpp"

#endif

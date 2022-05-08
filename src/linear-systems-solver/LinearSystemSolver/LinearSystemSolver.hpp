#ifndef LINEAR_SYSTEM_SOLVER_H_INCLUDED
#define LINEAR_SYSTEM_SOLVER_H_INCLUDED


#include <LinearSystem/LinearSystem.hpp>
#include "./LinearSystemSolvingAlgorithm/LinearSystemSolvingAlgorithm.hpp"


template <typename T>
class LinearSystemSolver {
	private:
	const LinearSystem<T> linearSystem;
	LinearSystemSolvingAlgorithm<T> *algorithm;
	bool isDone;
	public:
	bool getIsDone() const;
	LinearSystem<T> getLinearSystem() const;
	LinearSystemSolver(
		LinearSystem<T> linearSystem,
		LinearSystemSolvingAlgorithm<T> *algorithm
	);
	void solveStep();
};

#include "./LinearSystemSolver.tpp"

#endif

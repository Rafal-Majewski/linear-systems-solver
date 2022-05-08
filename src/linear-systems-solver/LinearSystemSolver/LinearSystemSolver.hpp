#ifndef LINEAR_SYSTEM_SOLVER_H_INCLUDED
#define LINEAR_SYSTEM_SOLVER_H_INCLUDED


#include <LinearSystem/LinearSystem.hpp>
#include "./LinearSystemSolvingAlgorithm/LinearSystemSolvingAlgorithm.hpp"


template <typename T>
class LinearSystemSolver {
	private:
	LinearSystemSolvingAlgorithm<T> *algorithm;
	bool isDone;
	public:
	bool getIsDone() const;
	LinearSystem<T> getLinearSystem() const;
	LinearSystemSolver(
		LinearSystemSolvingAlgorithm<T> *algorithm
	);
	void solveStep();
};

#include "./LinearSystemSolver.tpp"

#endif

#ifndef LINEAR_SYSTEM_SOLVER_G_H_INCLUDED
#define LINEAR_SYSTEM_SOLVER_G_H_INCLUDED


#include <LinearSystemSolver/LinearSystemSolver.hpp>


template <typename T>
class LinearSystemSolverG : public LinearSystemSolver<T> {
	private:
	void checkIsAlreadyDone();
	public:
	void solveStep() override;
	LinearSystemSolverG(
		LinearSystem<T> linearSystem
	);
};

#include "./LinearSystemSolverG.tpp"

#endif

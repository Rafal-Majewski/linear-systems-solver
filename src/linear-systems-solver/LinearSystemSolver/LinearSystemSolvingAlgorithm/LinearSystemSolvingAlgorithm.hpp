#ifndef LINEAR_SYSTEM_SOLVING_ALGORITHM_H_INCLUDED
#define LINEAR_SYSTEM_SOLVING_ALGORITHM_H_INCLUDED

#include <LinearSystem/LinearSystem.hpp>


template <typename T>
class LinearSystemSolvingAlgorithm {
	LinearSystem<T> &linearSystem;
	public:
	LinearSystem<T> getLinearSystem() const;
	virtual bool checkIsAlreadyDone() const = 0;
	virtual bool solveStep() = 0;
	LinearSystemSolvingAlgorithm(LinearSystem<T> &linearSystem);
};

#include "./LinearSystemSolvingAlgorithm.tpp"

#endif

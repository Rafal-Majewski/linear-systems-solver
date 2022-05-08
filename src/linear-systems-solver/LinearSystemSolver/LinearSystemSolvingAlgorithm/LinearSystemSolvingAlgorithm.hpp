#ifndef LINEAR_SYSTEM_SOLVING_ALGORITHM_H_INCLUDED
#define LINEAR_SYSTEM_SOLVING_ALGORITHM_H_INCLUDED

#include <LinearSystem/LinearSystem.hpp>


template <typename T>
class LinearSystemSolvingAlgorithm {
	LinearSystem<T> &linearSystem;
	LinearSystemSolvingAlgorithm(LinearSystem<T> &linearSystem);
	public:
	virtual bool checkIsAlreadyDone() = 0;
	virtual bool solveStep() = 0;
};

#include "./LinearSystemSolvingAlgorithm.tpp"

#endif

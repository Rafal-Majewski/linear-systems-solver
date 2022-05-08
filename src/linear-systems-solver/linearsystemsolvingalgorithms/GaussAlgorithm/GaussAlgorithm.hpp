#ifndef GAUSS_ALGORITHM_H_INCLUDED
#define GAUSS_ALGORITHM_H_INCLUDED


#include <LinearSystemSolver/LinearSystemSolvingAlgorithm/LinearSystemSolvingAlgorithm.hpp>


template <typename T>
class GaussAlgorithm : public LinearSystemSolvingAlgorithm<T> {
	private:
	bool checkIsAlreadyDone() const override;
	bool solveStep() override;
	public:
	// GaussAlgorithm(
	// 	LinearSystem<T> linearSystem
	// );
	using LinearSystemSolvingAlgorithm<T>::LinearSystemSolvingAlgorithm;
};

#include "./GaussAlgorithm.tpp"

#endif

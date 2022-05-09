#ifndef GAUSS_ALGORITHM_H_INCLUDED
#define GAUSS_ALGORITHM_H_INCLUDED


#include <LinearSystemSolver/LinearSystemSolver.hpp>
#include <LinearSystem/LinearSystem.hpp>


template <typename T>
class GaussAlgorithm : public LinearSystemSolver<T> {
	public:
	LinearSystem<T> solve(LinearSystem<T> linearSystem) const override;
};

#include "./GaussAlgorithm.tpp"

#endif

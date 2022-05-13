#ifndef GAUSS_ALGORITHM_H_INCLUDED
#define GAUSS_ALGORITHM_H_INCLUDED


#include <LinearSystemSolver/LinearSystemSolver.hpp>
#include <LinearSystem/LinearSystem.hpp>


template <typename T>
class GaussAlgorithm : public LinearSystemSolver<T> {
	private:
	LinearSystem<T> eliminate(LinearSystem<T> linearSystem) const;
	std::vector<std::pair<std::string, T>> extractSolutions(const LinearSystem<T> &linearSystem) const;
	public:
	std::vector<std::pair<std::string, T>> solve(LinearSystem<T> linearSystem) const override;
};

#include "./GaussAlgorithm.tpp"

#endif

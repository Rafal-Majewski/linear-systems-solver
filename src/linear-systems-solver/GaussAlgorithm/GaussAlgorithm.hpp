#ifndef GAUSS_ALGORITHM_H_INCLUDED
#define GAUSS_ALGORITHM_H_INCLUDED


#include <LinearSystemSolver/LinearSystemSolver.hpp>
#include <LinearSystem/LinearSystem.hpp>


template <typename T>
class AbstractGaussAlgorithm : public LinearSystemSolver<T> {
	private:
	LinearSystem<T> eliminate(
		LinearSystem<T> linearSystem,
		std::vector<int> &originalVariablesIndexes
	) const;
	inline virtual void choose(
		LinearSystem<T> &linearSystem,
		int equationIndex,
		int variableIndex,
		std::vector<int> &originalVariablesIndexes
	) const = 0;
	std::vector<T> extractSolutions(
		const LinearSystem<T> &linearSystem,
		std::vector<int> &originalVariablesIndexes
	) const;
	public:
	std::vector<T> solve(LinearSystem<T> linearSystem) const override;
};

template <typename T>
class GaussAlgorithm : public AbstractGaussAlgorithm<T> {
	private:
	void choose(
		LinearSystem<T> &linearSystem,
		int equationIndex,
		int variableIndex,
		std::vector<int> &originalVariablesIndexes
	) const override;
};

template <typename T>
class PartialGaussAlgorithm : public AbstractGaussAlgorithm<T> {
	private:
	void choose(
		LinearSystem<T> &linearSystem,
		int equationIndex,
		int variableIndex,
		std::vector<int> &originalVariablesIndexes
	) const override;
};

template <typename T>
class FullGaussAlgorithm : public AbstractGaussAlgorithm<T> {
	private:
	void choose(
		LinearSystem<T> &linearSystem,
		int equationIndex,
		int variableIndex,
		std::vector<int> &originalVariablesIndexes
	) const override;
};

#include "./GaussAlgorithm.tpp"

#endif

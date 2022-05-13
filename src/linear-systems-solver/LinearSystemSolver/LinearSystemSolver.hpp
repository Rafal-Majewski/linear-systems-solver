#ifndef LINEAR_SYSTEM_SOLVER_H_INCLUDED
#define LINEAR_SYSTEM_SOLVER_H_INCLUDED


#include <LinearSystem/LinearSystem.hpp>


template <typename T>
class LinearSystemSolver {
	public:
	virtual std::vector<std::pair<std::string, T>> solve(LinearSystem<T> linearSystem) const = 0;
};

#endif

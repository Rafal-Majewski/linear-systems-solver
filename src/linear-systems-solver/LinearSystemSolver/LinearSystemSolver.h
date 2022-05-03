#include "./SolvingMethod/SolvingMethod.h"
#include "../LinearSystem/LinearSystem.h"

template <typename T>
class LinearSystemSolver {
	private:
	const LinearSystem<T> linearSystem;
	public:
	const SolvingMethod solvingMethod;
	LinearSystemSolver(
		SolvingMethod solvingMethod,
		LinearSystem<T> linearSystem
	);
};

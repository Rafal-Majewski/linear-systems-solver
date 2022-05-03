// #include <matrix/Matrix.h>
#include <vector>
#include <string>


template <typename T>
class LinearSystem {
	private:
	bool isDone;
	// Matrix<T> coefficients;
	std::vector<T> constants;
	std::vector<std::string> variables;
	void updateIsDone();
	public:
	LinearSystem(
		// Matrix<T> coefficients,
		std::vector<T> constants,
		std::vector<std::string> variables
	): coefficients(coefficients),
	constants(constants),
	variables(variables) {
		updateIsDone();
	}
};

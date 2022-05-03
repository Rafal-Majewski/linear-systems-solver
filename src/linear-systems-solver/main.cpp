#include <iostream>
#include <CLI/CLI.hpp>
#include <LinearSystemSolver/SolvingMethod/SolvingMethod.h>
#include <Matrix/Matrix.h>
#include <Matrix/Size/Size.h>




int main(int argc, char *argv[]) {
	CLI::App app{"Linear Systems Solver"};

	SolvingMethod solvingMethod;
	app.add_option("-m,--method", solvingMethod, "Solving method")
		->required()
		->transform(CLI::CheckedTransformer(solvingMethodByString, CLI::ignore_case));


	CLI11_PARSE(app, argc, argv);

	std::cout << solvingMethod << std::endl;

	Matrix<double> coefficients(Size(3, 2));
	std::cout << coefficients << std::endl;

	return 0;
}

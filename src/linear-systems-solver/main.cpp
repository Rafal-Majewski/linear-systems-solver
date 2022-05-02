#include <iostream>
#include <CLI/CLI.hpp>
#include <LinearSystem/SolvingMethod/SolvingMethod.h>




int main(int argc, char *argv[]) {
	CLI::App app{"Linear Systems Solver"};

	SolvingMethod solvingMethod;
	app.add_option("-m,--method", solvingMethod, "Solving method")
		->required()
		->transform(CLI::CheckedTransformer(solvingMethodByString, CLI::ignore_case));


	CLI11_PARSE(app, argc, argv);

	std::cout << solvingMethod << std::endl;

	return 0;
}

#include <iostream>
#include <CLI/CLI.hpp>
#include <LinearSystemSolver/SolvingMethod/SolvingMethod.h>
#include <Matrix/Matrix.h>
#include <Matrix/Size/Size.h>
#include <LinearSystemReader/LinearSystemReader.h>


void run(SolvingMethod solvingMethod) {
	LinearSystemReader linearSystemReader = LinearSystemReader<float>();
}
void applyOptions(
	CLI::App& app,
	SolvingMethod& solvingMethod
) {
	app.add_option("-m,--method", solvingMethod, "Solving method")
		->required()
		->transform(CLI::CheckedTransformer(solvingMethodByString, CLI::ignore_case));
}



int main(int argc, char *argv[]) {
	CLI::App app{"Linear Systems Solver"};

	SolvingMethod solvingMethod;
	applyOptions(app, solvingMethod);
	CLI11_PARSE(app, argc, argv);
	run(solvingMethod);

	return 0;
}

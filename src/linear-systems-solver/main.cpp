#include <iostream>
#include <CLI/CLI.hpp>
#include <LinearSystemSolver/SolvingMethod/SolvingMethod.h>
#include <Matrix/Matrix.h>
#include <Matrix/MatrixSize/MatrixSize.h>
#include "./linearsystemreaders/FloatLinearSystemReader/FloatLinearSystemReader.h"
#include <Datatype/Datatype.h>
#include <Rational/Rational.h>
#include <BigInt/BigInt.h>


void run(
	SolvingMethod solvingMethod,
	Datatype datatype
) {
	LinearSystemReader linearSystemReader = FloatLinearSystemReader();
		// : throw std::runtime_error("Unknown datatype");
	linearSystemReader.read();
	//LinearSystem<float> linearSystem = 
}

void applyOptions(
	CLI::App& app,
	SolvingMethod& solvingMethod,
	Datatype& datatype
) {
	app.add_option("-m,--method", solvingMethod, "Solving method")
		->required()
		->transform(CLI::CheckedTransformer(solvingMethodByString, CLI::ignore_case));
	app.add_option("-d,--datatype", datatype, "Datatype")
		->required()
		->transform(CLI::CheckedTransformer(datatypeByString, CLI::ignore_case));
}

int main(int argc, char *argv[]) {
	CLI::App app{"Linear Systems Solver"};

	SolvingMethod solvingMethod;
	Datatype datatype;
	applyOptions(app, solvingMethod, datatype);
	CLI11_PARSE(app, argc, argv);
	run(solvingMethod, datatype);

	return 0;
}

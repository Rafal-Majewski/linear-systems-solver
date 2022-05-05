#include <iostream>
#include <CLI/CLI.hpp>
#include <LinearSystemSolver/LinearSystemSolver.h>
#include <LinearSystemSolver/SolvingMethod/SolvingMethod.h>

#include <Matrix/Matrix.h>
#include <Matrix/MatrixSize/MatrixSize.h>
#include <LinearSystemReader/LinearSystemReader.h>
#include <Datatype/Datatype.h>
#include <Rational/Rational.h>
#include <BigInt/BigInt.h>
#include <LinearSystemPrinter/LinearSystemPrinter.h>

template <typename T>
void solve(
	LinearSystemSolver<T> linearSystemSolver
) {
	LinearSystemPrinter<T> linearSystemPrinter = LinearSystemPrinter<T>();
	while(!linearSystemSolver.getIsDone()) {
		// linearSystemSolver.print();
		// linearSystemSolver.solveStep();
	}
	linearSystemPrinter.print(linearSystemSolver.getLinearSystem());

}


template <typename T>
void runForDatatype(
	SolvingMethod solvingMethod
) {
	LinearSystemReader<T> linearSystemReader;
	LinearSystem<T> linearSystem = linearSystemReader.read();
	LinearSystemSolver<T> linearSystemSolver(solvingMethod, linearSystem);
	solve(linearSystemSolver);
}


void run(
	SolvingMethod solvingMethod,
	Datatype datatype
) {
	switch (datatype) {
		case Datatype::RATIONAL:
			return runForDatatype<Rational<BigInt>>(solvingMethod);
		case Datatype::FLOAT:
			return runForDatatype<float>(solvingMethod);
		case Datatype::DOUBLE:
			return runForDatatype<double>(solvingMethod);
		default:
			throw std::runtime_error("Unknown datatype");
	}
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

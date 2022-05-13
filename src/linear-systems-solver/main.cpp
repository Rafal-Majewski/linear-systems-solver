#include <iostream>
#include <CLI/CLI.hpp>
#include <LinearSystemSolver/LinearSystemSolver.hpp>
#include <SolvingMethod/SolvingMethod.hpp>
#include <Matrix/Matrix.hpp>
#include <LinearSystemPrinter/LinearSystemPrinter.hpp>
#include <Matrix/MatrixSize/MatrixSize.hpp>
#include <LinearSystemReader/LinearSystemReader.hpp>
#include <Datatype/Datatype.hpp>
#include <Rational/Rational.hpp>
#include <BigInt/BigInt.hpp>
#include <linearsystemsolvingalgorithms/GaussAlgorithm/GaussAlgorithm.hpp>

template <typename T>
void solve(
	LinearSystemSolver<T> *linearSystemSolver,
	LinearSystem<T> linearSystem
) {
	LinearSystemPrinter<T> linearSystemPrinter = LinearSystemPrinter<T>(" ");
	linearSystemPrinter.print(
		linearSystemSolver->solve(linearSystem)
	);
}

template <typename T>
void runWithDatatype(
	SolvingMethod solvingMethod
) {
	LinearSystemReader<T> linearSystemReader;
	LinearSystem<T> linearSystem = linearSystemReader.read();
	LinearSystemSolver<T> *linearSystemSolver = nullptr;
	switch(solvingMethod) {
		case SolvingMethod::G:
			linearSystemSolver = new GaussAlgorithm<T>();
			break;
		default:
			throw std::runtime_error("Unknown solving method");
	}
	solve<T>(linearSystemSolver, linearSystem);
}


void run(
	SolvingMethod solvingMethod,
	Datatype datatype
) {
	switch (datatype) {
		case Datatype::RATIONAL:
			return runWithDatatype<Rational<BigInt>>(solvingMethod);
		case Datatype::FLOAT:
			return runWithDatatype<float>(solvingMethod);
		case Datatype::DOUBLE:
			return runWithDatatype<double>(solvingMethod);
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

#include <iostream>
#include <CLI/CLI.hpp>
#include <LinearSystemSolver/LinearSystemSolver.hpp>
#include <SolvingMethod/SolvingMethod.hpp>
#include <Matrix/Matrix.hpp>
#include <Matrix/MatrixSize/MatrixSize.hpp>
#include <LinearSystemReader/LinearSystemReader.hpp>
#include <Datatype/Datatype.hpp>
#include <Rational/Rational.hpp>
#include <BigInt/BigInt.hpp>
#include <LinearSystemPrinter/LinearSystemPrinter.hpp>
#include <linearsystemsolvingalgorithms/GaussAlgorithm/GaussAlgorithm.hpp>

// #include <LinearSystemSolver/implementations/LinearSystemSolverG/LinearSystemSolverG.hpp>
// #include <LinearSystemSolver/implementations/LinearSystemSolverPG/LinearSystemSolverPG.hpp>
// #include <LinearSystemSolver/implementations/LinearSystemSolverFG/LinearSystemSolverFG.hpp>


template <typename T>
void solve(
	LinearSystemSolver<T> &linearSystemSolver,
	void (*solveStepCallback)(LinearSystemSolver<T> &, LinearSystemPrinter<T> &)
) {
	LinearSystemPrinter<T> linearSystemPrinter = LinearSystemPrinter<T>();
	while(!linearSystemSolver.getIsDone()) {
		solveStepCallback(linearSystemSolver, linearSystemPrinter);
	}
	linearSystemPrinter.print(linearSystemSolver.getLinearSystem());
}

template <typename T>
void solveStepDefaultCallback(
	LinearSystemSolver<T> &linearSystemSolver,
	LinearSystemPrinter<T> &linearSystemPrinter
) {
	linearSystemSolver.solveStep();
}

template <typename T>
void solveStepVerboseCallback(
	LinearSystemSolver<T> &linearSystemSolver,
	LinearSystemPrinter<T> &linearSystemPrinter
) {
	linearSystemPrinter.print(linearSystemSolver.getLinearSystem());
	linearSystemSolver.solveStep();
}



template <typename T>
void runWithDatatype(
	SolvingMethod solvingMethod,
	bool isVerbose
) {
	// pointer to function
	void (*solveStepCallback)(
		LinearSystemSolver<T> &,
		LinearSystemPrinter<T> &
	);
	solveStepCallback = isVerbose ? &solveStepVerboseCallback<T> : &solveStepDefaultCallback<T>;
	LinearSystemReader<T> linearSystemReader;
	LinearSystem<T> linearSystem = linearSystemReader.read();
	LinearSystemSolvingAlgorithm<T> *algorithm = nullptr;
	switch(solvingMethod) {
		case SolvingMethod::G:
			algorithm = new GaussAlgorithm<T>(linearSystem);
			break;
		default:
			throw std::runtime_error("Unknown solving method");
	}
	LinearSystemSolver<T> linearSystemSolver = LinearSystemSolver<T>(algorithm);
	solve(linearSystemSolver, solveStepCallback);
}


void run(
	SolvingMethod solvingMethod,
	Datatype datatype,
	bool isVerbose
) {
	switch (datatype) {
		case Datatype::RATIONAL:
			return runWithDatatype<Rational<BigInt>>(solvingMethod, isVerbose);
		case Datatype::FLOAT:
			return runWithDatatype<float>(solvingMethod, isVerbose);
		case Datatype::DOUBLE:
			return runWithDatatype<double>(solvingMethod, isVerbose);
		default:
			throw std::runtime_error("Unknown datatype");
	}
}

void applyOptions(
	CLI::App& app,
	SolvingMethod& solvingMethod,
	Datatype& datatype,
	bool isVerbose
) {
	app.add_option("-m,--method", solvingMethod, "Solving method")
		->required()
		->transform(CLI::CheckedTransformer(solvingMethodByString, CLI::ignore_case));
	app.add_option("-d,--datatype", datatype, "Datatype")
		->required()
		->transform(CLI::CheckedTransformer(datatypeByString, CLI::ignore_case));
	app.add_option("-v,--verbose", isVerbose, "Print all steps");
}

int main(int argc, char *argv[]) {
	CLI::App app{"Linear Systems Solver"};

	SolvingMethod solvingMethod;
	Datatype datatype;
	bool isVerbose;
	applyOptions(app, solvingMethod, datatype, isVerbose);
	CLI11_PARSE(app, argc, argv);
	run(solvingMethod, datatype, isVerbose);

	return 0;
}

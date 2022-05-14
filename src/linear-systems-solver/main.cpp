#include <iostream>
#include <CLI/CLI.hpp>
#include <LinearSystemSolver/LinearSystemSolver.hpp>
#include <SolvingMethod/SolvingMethod.hpp>
#include <Matrix/Matrix.hpp>
#include <LinearSystemGenerator/LinearSystemGenerator.hpp>
#include <LinearSystemReader/LinearSystemReader.hpp>
#include <LinearSystemPrinter/LinearSystemPrinter.hpp>
#include <Matrix/MatrixSize/MatrixSize.hpp>
#include <Datatype/Datatype.hpp>
#include <Rational/Rational.hpp>
#include <BigInt/BigInt.hpp>
#include <solvingalgorithms/GaussAlgorithm/GaussAlgorithm.hpp>



template <typename DT, typename SL>
std::vector<std::pair<std::string, DT>> solve(
	LinearSystem<DT> linearSystem
) {
	SL linearSystemSolver = SL();
	return linearSystemSolver.solve(linearSystem);
}

template <typename DT, typename SL>
void runSolve(
) {
	LinearSystemReader<DT> linearSystemReader = LinearSystemReader<DT>();
	LinearSystem<DT> linearSystem = linearSystemReader.read();
	LinearSystemPrinter<DT> linearSystemPrinter(" ");
	linearSystemPrinter.print(solve<DT, SL>(linearSystem));
}

template <typename DT, typename SL>
void runBenchmark(
	int benchmarkIterations,
	int benchmarkSize
) {
	for (int i = 0; i < benchmarkIterations; ++i) {

	}
}

template <typename DT, typename SL>
void runWithDatatypeAndSolver(
	bool benchmark,
	int benchmarkIterations,
	int benchmarkSize
) {
	if (benchmark) {
		return runBenchmark<DT, SL>(benchmarkIterations, benchmarkSize);
	}
	return runSolve<DT, SL>();
}

template <typename DT>
void runWithDatatype(
	SolvingMethod solvingMethod,
	bool benchmark,
	int benchmarkIterations,
	int benchmarkSize
) {
	switch (solvingMethod) {
		case SolvingMethod::G:
			return runWithDatatypeAndSolver<DT, GaussAlgorithm<DT>>(
				benchmark, benchmarkIterations, benchmarkSize
			);
		default:
			throw std::runtime_error("Unknown solving method");
	}
}


void run(
	SolvingMethod solvingMethod,
	Datatype datatype,
	bool benchmark,
	int benchmarkIterations,
	int benchmarkSize
) {
	switch (datatype) {
		case Datatype::RATIONAL:
			return runWithDatatype<Rational<BigInt>>(
				solvingMethod, benchmark, benchmarkIterations, benchmarkSize
			);
		case Datatype::FLOAT:
			return runWithDatatype<float>(
				solvingMethod, benchmark, benchmarkIterations, benchmarkSize
			);
		case Datatype::DOUBLE:
			return runWithDatatype<double>(
				solvingMethod, benchmark, benchmarkIterations, benchmarkSize
			);
		default:
			throw std::runtime_error("Unknown datatype");
	}
}

void applyOptions(
	CLI::App& app,
	SolvingMethod& solvingMethod,
	Datatype& datatype,
	bool& benchmark,
	int& benchmarkIterations,
	int& benchmarkSize
) {
	app.add_option("-m,--method", solvingMethod, "Solving method")
		->required()
		->transform(CLI::CheckedTransformer(solvingMethodByString, CLI::ignore_case));
	app.add_option("-d,--datatype", datatype, "Datatype")
		->required()
		->transform(CLI::CheckedTransformer(datatypeByString, CLI::ignore_case));
	app.add_flag("-b,--benchmark", benchmark, "Benchmark");
	app.add_option("-i,--benchmark-iterations", benchmarkIterations, "Benchmark iterations");
	app.add_option("-s,--benchmark-size", benchmarkSize, "Benchmark size");
}

int main(int argc, char *argv[]) {
	CLI::App app{"Linear Systems Solver"};

	SolvingMethod solvingMethod;
	Datatype datatype;
	bool benchmark = false;
	int benchmarkIterations = 0;
	int benchmarkSize = 0;
	applyOptions(
		app, solvingMethod, datatype,
		benchmark, benchmarkIterations, benchmarkSize
	);
	CLI11_PARSE(app, argc, argv);
	run(
		solvingMethod, datatype,
		benchmark, benchmarkIterations, benchmarkSize
	);

	return 0;
}

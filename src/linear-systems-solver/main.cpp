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
#include <iomanip>


template <typename DT, typename SL>
std::vector<DT> solve(
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
template <typename DT>
double calculateError(std::vector<DT> expected, std::vector<DT> actual) {
	double error = 0;
	for (int i = 0; i < expected.size(); i++) {
		DT difference = expected[i] - actual[i];
		error += double((difference < 0) ? -difference : difference);
	}
	return error;
}

template <typename DT, typename SL>
void runBenchmark(
	int benchmarkIterations,
	int benchmarkSize
) {
	LinearSystemGenerator<DT> linearSystemGenerator(
		benchmarkSize,
		-0b10000000000000000l,
		0b10000000000000000l,
		0b10000000000000000l
	);
	LinearSystemPrinter<DT> linearSystemPrinter(" ");
	SL linearSystemSolver = SL();
	std::cout << "Iteration" << '\t' << "Error_(abs)" << '\t' << "Time_(s)" << '\n';
	for (int i = 0; i < benchmarkIterations; ++i) {
		auto [linearSystem, expectedSolutions] = linearSystemGenerator.generate();
		auto start = std::chrono::high_resolution_clock::now();
		std::vector<DT> actualSolutions = linearSystemSolver.solve(linearSystem);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> float_ms = end - start;
		std::cout << i + 1 << '\t';
		std::cout << calculateError(expectedSolutions, actualSolutions) << '\t';
		std::cout << float_ms.count() / 1000 << '\n';
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
	std::cout << std::setprecision(20);
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
	app.add_option("-i,--benchmark-iterations", benchmarkIterations, "Benchmark iterations")
		->default_val(0);
	app.add_option("-s,--benchmark-size", benchmarkSize, "Benchmark size")
		->default_val(0);
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

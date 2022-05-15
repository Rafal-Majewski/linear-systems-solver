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
#include <GaussAlgorithm/GaussAlgorithm.hpp>
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
double calculateAbsError(std::vector<DT> expected, std::vector<DT> actual) {
	double error = 0;
	for (int i = 0; i < expected.size(); i++) {
		DT difference = expected[i] - actual[i];
		error += double((difference < 0) ? -difference : difference);
	}
	return error;
}

template <typename DT, typename SL>
void runBenchmark(
	int benchmarkStartSize,
	int benchmarkStopSize,
	int benchmarkStepSize,
	int benchmarkBatchSize
) {
	LinearSystemPrinter<DT> linearSystemPrinter(" ");
	SL linearSystemSolver = SL();
	std::cout << "Size\tError\tTime" << '\n';

	for (int benchmarkSize = benchmarkStartSize; benchmarkSize <= benchmarkStopSize; benchmarkSize += benchmarkStepSize) {
		double averageError = 0;
		double averageTime = 0;
		LinearSystemGenerator<DT> linearSystemGenerator(
			benchmarkSize,
			-0b10000000000000000l,
			0b10000000000000000l,
			0b10000000000000000l
		);
		for (int i = 0; i < benchmarkBatchSize; ++i) {
			auto [linearSystem, expectedSolutions] = linearSystemGenerator.generate();
			auto start = std::chrono::high_resolution_clock::now();
			std::vector<DT> actualSolutions = linearSystemSolver.solve(linearSystem);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double, std::milli> float_ms = end - start;
			averageError += calculateAbsError(expectedSolutions, actualSolutions);
			averageTime += float_ms.count() / 1000;
		}
		averageError /= benchmarkBatchSize;
		averageTime /= benchmarkBatchSize;
		std::cout << benchmarkSize << '\t';
		std::cout << averageError << '\t';
		std::cout << averageTime << '\n';
	}
}

template <typename DT, typename SL>
void runWithDatatypeAndSolver(
	bool benchmark,
	int benchmarkStartSize,
	int benchmarkStopSize,
	int benchmarkStepSize,
	int benchmarkBatchSize
) {
	if (benchmark) {
		return runBenchmark<DT, SL>(
			benchmarkStartSize,
			benchmarkStopSize,
			benchmarkStepSize,
			benchmarkBatchSize
		);
	}
	return runSolve<DT, SL>();
}

template <typename DT>
void runWithDatatype(
	SolvingMethod solvingMethod,
	bool benchmark,
	int benchmarkStartSize,
	int benchmarkStopSize,
	int benchmarkStepSize,
	int benchmarkBatchSize
) {
	switch (solvingMethod) {
		case SolvingMethod::G:
			return runWithDatatypeAndSolver<DT, GaussAlgorithm<DT>>(
				benchmark,
				benchmarkStartSize, benchmarkStopSize, benchmarkStepSize, benchmarkBatchSize
			);
		case SolvingMethod::PG:
			return runWithDatatypeAndSolver<DT, PartialGaussAlgorithm<DT>>(
				benchmark,
				benchmarkStartSize, benchmarkStopSize, benchmarkStepSize, benchmarkBatchSize
			);
		case SolvingMethod::FG:
			return runWithDatatypeAndSolver<DT, FullGaussAlgorithm<DT>>(
				benchmark,
				benchmarkStartSize, benchmarkStopSize, benchmarkStepSize, benchmarkBatchSize
			);
		default:
			throw std::runtime_error("Unknown solving method");
	}
}


void run(
	SolvingMethod solvingMethod,
	Datatype datatype,
	bool benchmark,
	int benchmarkStartSize,
	int benchmarkStopSize,
	int benchmarkStepSize,
	int benchmarkBatchSize
) {
	std::cout << std::setprecision(20);
	switch (datatype) {
		case Datatype::RATIONAL:
			return runWithDatatype<Rational<BigInt>>(
				solvingMethod, benchmark,
				benchmarkStartSize, benchmarkStopSize, benchmarkStepSize, benchmarkBatchSize
			);
		case Datatype::FLOAT:
			return runWithDatatype<float>(
				solvingMethod, benchmark,
				benchmarkStartSize, benchmarkStopSize, benchmarkStepSize, benchmarkBatchSize
			);
		case Datatype::DOUBLE:
			return runWithDatatype<double>(
				solvingMethod, benchmark,
				benchmarkStartSize, benchmarkStopSize, benchmarkStepSize, benchmarkBatchSize
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
	int& benchmarkStartSize,
	int& benchmarkStopSize,
	int& benchmarkStepSize,
	int& benchmarkBatchSize,
	int& seed
) {
	app.add_option("-m,--method", solvingMethod, "Solving method")
		->required()
		->transform(CLI::CheckedTransformer(solvingMethodByString, CLI::ignore_case));
	app.add_option("-d,--datatype", datatype, "Datatype")
		->required()
		->transform(CLI::CheckedTransformer(datatypeByString, CLI::ignore_case));
	app.add_flag("-b,--benchmark", benchmark, "Benchmark");
	app.add_option("-s,--benchmark-start-size", benchmarkStartSize, "Benchmark start size")
		->default_val(0);
	app.add_option("-e,--benchmark-stop-size", benchmarkStopSize, "Benchmark stop size")
		->default_val(0);
	app.add_option("-i,--benchmark-step-size", benchmarkStepSize, "Benchmark step size")
		->default_val(1);
	app.add_option("-n,--benchmark-batch-size", benchmarkBatchSize, "Benchmark batch size")
		->default_val(0);
	app.add_option("-r,--seed", seed, "Seed")
		->default_val(0);
}

int main(int argc, char *argv[]) {
	CLI::App app{"Linear Systems Solver"};

	SolvingMethod solvingMethod;
	Datatype datatype;
	bool benchmark = false;
	int benchmarkStartSize;
	int benchmarkStopSize;
	int benchmarkStepSize;
	int benchmarkBatchSize;
	int seed;

	applyOptions(
		app, solvingMethod, datatype,
		benchmark,
		benchmarkStartSize,
		benchmarkStopSize,
		benchmarkStepSize,
		benchmarkBatchSize,
		seed
	);
	CLI11_PARSE(app, argc, argv);
	srand(seed);
	run(
		solvingMethod, datatype,
		benchmark,
		benchmarkStartSize,
		benchmarkStopSize,
		benchmarkStepSize,
		benchmarkBatchSize
	);

	return 0;
}

#include <iostream>
#include <CLI/CLI.hpp>
#include <map>
#include <Matrix/Matrix.hpp>
#include <Datatype/Datatype.hpp>
#include <Rational/Rational.hpp>
#include <BigInt/BigInt.hpp>
#include <MatrixOperator/MatrixOperator.hpp>
#include <MatrixOperator/MatrixAdditionOperator.hpp>
#include <MatrixGenerator/MatrixGenerator.hpp>
#include <MatrixReader/MatrixReader.hpp>
#include <TokensReader/TokensReader.hpp>

template <typename DT>
std::map<std::string, Matrix<DT>> generateVariables(
	std::vector<std::string> tokens,
	std::map<std::string, MatrixOperator<DT>*> operators,
	int matrixSize
) {
	MatrixGenerator<DT> generator(
		-0b10000000000000000l,
		0b10000000000000000l,
		0b10000000000000000l
	);
	std::map<std::string, Matrix<DT>> variables;
	for (int i = 0; i < tokens.size(); i++) {
		if (operators.contains(tokens[i])) {
			continue;
		}
		std::string variableName = tokens[i];
		Matrix<DT> matrix = generator.generate(
			MatrixSize(
				matrixSize,
				variableName[0] == '_' ? 1 : matrixSize
			)
		);
		variables.insert({variableName, matrix});
	}
	return variables;
}

template <typename DT>
std::map<std::string, Matrix<DT>> readVariables() {
	MatrixReader<DT> reader;
	std::map<std::string, Matrix<DT>> variables;
	int variablesCount;
	std::cin >> variablesCount;
	for (int i = 0; i < variablesCount; i++) {
		std::string variable;
		std::cin >> variable;
		Matrix<DT> matrix = reader.read();
		variables.insert({variable, matrix});
	}
	return variables;
}

template <typename DT>
void runBenchmark(
	std::vector<std::string> tokens,
	std::map<std::string, MatrixOperator<DT>*> operators,
	int benchmarkMatrixSize
) {
	std::map<std::string, Matrix<DT>> variables = generateVariables<DT>(
		tokens, operators, benchmarkMatrixSize
	);
}

template <typename DT>
void runSolve(
	std::vector<std::string> tokens,
	std::map<std::string, MatrixOperator<DT>*> operators
) {
	std::map<std::string, Matrix<DT>> variables = readVariables<DT>();
}

template <typename DT>
void runWithDatatype(
	bool benchmark,
	int benchmarkMatrixSize
) {
	TokensReader<DT> tokensReader = TokensReader<DT>();
	std::vector<std::string> tokens = tokensReader.read();

	MatrixAdditionOperator<DT> additionOperator = MatrixAdditionOperator<DT>();

	std::map<std::string, MatrixOperator<DT>*> matrixOperatorByToken = {
		{"+", &additionOperator}
	};
	if (benchmark) {
		runBenchmark<DT>(tokens, matrixOperatorByToken, benchmarkMatrixSize);
	} else {
		runSolver<DT>(tokens, matrixOperatorByToken);
	}
}


void run(
	Datatype datatype,
	bool benchmark,
	int benchmarkMatrixSize
) {
	std::cout << std::setprecision(20);
	switch (datatype) {
		case Datatype::RATIONAL:
			return runWithDatatype<Rational<BigInt>>(
				benchmark,
				benchmarkMatrixSize
			);
		case Datatype::FLOAT:
			return runWithDatatype<float>(
				benchmark,
				benchmarkMatrixSize
			);
		case Datatype::DOUBLE:
			return runWithDatatype<double>(
				benchmark,
				benchmarkMatrixSize
			);
		default:
			throw std::runtime_error("Unknown datatype");
	}
}

void applyOptions(
	CLI::App& app,
	Datatype& datatype,
	bool& benchmark,
	int& seed,
	int& benchmarkMatrixSize
) {
	app.add_option("-d,--datatype", datatype, "Datatype")
		->required()
		->transform(CLI::CheckedTransformer(datatypeByString, CLI::ignore_case));
	app.add_flag("-b,--benchmark", benchmark, "Benchmark");
	app.add_option("-r,--seed", seed, "Seed")
		->default_val(0);
	app.add_option("-s,--benchmark-matrix-size", benchmarkMatrixSize, "Benchmark matrix size");
}

int main(int argc, char *argv[]) {
	CLI::App app{"Matrix Calculator"};

	Datatype datatype;
	bool benchmark;
	int seed;
	int benchmarkMatrixSize;

	applyOptions(
		app, datatype,
		benchmark,
		seed,
		benchmarkMatrixSize
	);
	CLI11_PARSE(app, argc, argv);
	srand(seed);
	run(
		datatype,
		benchmark,
		benchmarkMatrixSize
	);

	return 0;
}

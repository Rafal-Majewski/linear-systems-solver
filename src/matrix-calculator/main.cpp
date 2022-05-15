#include <iostream>
#include <CLI/CLI.hpp>
#include <map>
#include <Matrix/Matrix.hpp>
#include <Datatype/Datatype.hpp>
#include <Rational/Rational.hpp>
#include <BigInt/BigInt.hpp>
#include <MatrixOperator/MatrixOperator.hpp>
#include <MatrixOperator/MatrixAdditionOperator.hpp>
#include <MatrixOperator/MatrixMultiplicationOperator.hpp>
#include <MatrixGenerator/MatrixGenerator.hpp>
#include <MatrixReader/MatrixReader.hpp>
#include <MatrixPrinter/MatrixPrinter.hpp>
#include <TokensReader/TokensReader.hpp>


template <typename DT>
Matrix<DT> solve(
	std::vector<std::string> tokens,
	std::map<std::string, MatrixOperator<DT>*> operators,
	std::map<std::string, Matrix<DT>> variables
) {
	std::vector<Matrix<DT>> stack;
	for (int i = 0; i < tokens.size(); ++i) {
		std::string token = tokens[i];
		if (operators.contains(token)) {
			MatrixOperator<DT>* op = operators[token];
			Matrix<DT> m2 = stack.back();
			stack.pop_back();
			Matrix<DT> m1 = stack.back();
			stack.pop_back();
			stack.push_back(op->operate(m1, m2));
		}
		else if (variables.contains(token)) {
			stack.push_back(Matrix<DT>(variables.at(token)));
		} else {
			throw std::invalid_argument("Invalid token: " + token);
		}
	}
	if (stack.size() != 1) {
		throw std::invalid_argument("Invalid expression");
	}
	Matrix<DT> result = stack[0];
	stack.pop_back();
	return result;
}

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
		std::string variableName;
		std::cin >> variableName;
		Matrix<DT> matrix = reader.read();
		variables.insert({variableName, matrix});
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
	auto start = std::chrono::high_resolution_clock::now();
	Matrix<DT> result = solve<DT>(tokens, operators, variables);
	solveEigen<DT>(tokens, operators, variables);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> float_ms = end - start;
	std::cout << float_ms.count() / 1000 << std::endl;
}

template <typename DT>
void runSolve(
	std::vector<std::string> tokens,
	std::map<std::string, MatrixOperator<DT>*> operators
) {
	std::map<std::string, Matrix<DT>> variables = readVariables<DT>();
	Matrix<DT> solution = solve<DT>(
		tokens, operators, variables
	);
	MatrixPrinter<DT> printer = MatrixPrinter<DT>(" ");
	printer.print(solution);
}

template <typename DT>
void runWithDatatype(
	bool benchmark,
	int benchmarkMatrixSize
) {
	TokensReader<DT> tokensReader = TokensReader<DT>();
	std::vector<std::string> tokens = tokensReader.read();

	MatrixAdditionOperator<DT> additionOperator = MatrixAdditionOperator<DT>();
	MatrixMultiplicationOperator<DT> multiplicationOperator = MatrixMultiplicationOperator<DT>();

	std::map<std::string, MatrixOperator<DT>*> matrixOperatorByToken = {
		{"+", &additionOperator},
		{"*", &multiplicationOperator}
	};
	if (benchmark) {
		runBenchmark<DT>(tokens, matrixOperatorByToken, benchmarkMatrixSize);
	} else {
		runSolve<DT>(tokens, matrixOperatorByToken);
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
	app.add_option("-s,--benchmark-matrix-size", benchmarkMatrixSize, "Benchmark matrix size")
		->default_val(0);	
}

int main(int argc, char *argv[]) {
	CLI::App app{"Matrix Calculator"};

	Datatype datatype;
	bool benchmark = false;
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

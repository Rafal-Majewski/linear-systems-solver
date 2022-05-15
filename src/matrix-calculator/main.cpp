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
double calculateAbsError(Matrix<Rational<BigInt>> expected, Matrix<DT> actual) {
	Rational<BigInt> error = (0);
	for (int y = 0; y < expected.size.rowsCount; y++) {
		for (int x = 0; x < expected.size.columnsCount; x++) {
			error += abs(expected.get(y, x) - Rational<BigInt>(actual.get(y, x)));
		}
	}
	return double(error);
}

template <typename DT>
void runBenchmark(
	std::vector<std::string> tokens,
	std::map<std::string, MatrixOperator<DT>*> operators,
	std::map<std::string, MatrixOperator<Rational<BigInt>>*> rationalOperators,
	int benchmarkStartSize,
	int benchmarkStopSize,
	int benchmarkStepSize,
	int benchmarkBatchSize
) {
	std::cout << "Size\tError\tTime" << '\n';
	for (int benchmarkSize = benchmarkStartSize; benchmarkSize <= benchmarkStopSize; benchmarkSize += benchmarkStepSize) {
		std::map<std::string, Matrix<DT>> variables = generateVariables<DT>(
			tokens, operators, benchmarkSize
		);
		std::map<std::string, Matrix<Rational<BigInt>>> rationalVariables;
		for (auto& pair : variables) {
			std::string variableName = pair.first;
			Matrix<DT> variableValue = pair.second;
			Matrix<Rational<BigInt>> rationalVariableValue = Matrix<Rational<BigInt>>(variableValue.size);
			for (int y = 0; y < variableValue.size.rowsCount; ++y) {
				for (int x = 0; x < variableValue.size.columnsCount; ++x) {
					rationalVariableValue.set(
						y,
						x,
						Rational<BigInt>(variableValue.get(y, x))
					);
				}
			}
			rationalVariables.insert({variableName, rationalVariableValue});
		}
		Matrix<Rational<BigInt>> expectedResult = solve<Rational<BigInt>>(
			tokens, rationalOperators, rationalVariables
		);
		double averageTime = 0;
		double averageError = 0;
		for (int i = 0; i < benchmarkBatchSize; ++i) {
			auto start = std::chrono::high_resolution_clock::now();
			Matrix<DT> actualResult = solve<DT>(tokens, operators, variables);
			auto end = std::chrono::high_resolution_clock::now();

			std::chrono::duration<double, std::milli> float_ms = end - start;
			averageTime += float_ms.count()/ 1000;
			averageError += calculateAbsError(expectedResult, actualResult);
			// double error = calculateAbsError(expectedResult, actualResult);
		}
		averageError /= benchmarkBatchSize;
		averageTime /= benchmarkBatchSize;
		std::cout << benchmarkSize << '\t' << averageError << '\t' << averageTime << '\n';
	}
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
	int benchmarkStartSize,
	int benchmarkStopSize,
	int benchmarkStepSize,
	int benchmarkBatchSize
) {
	TokensReader<DT> tokensReader = TokensReader<DT>();
	std::vector<std::string> tokens = tokensReader.read();

	MatrixAdditionOperator<DT> additionOperator = MatrixAdditionOperator<DT>();
	MatrixMultiplicationOperator<DT> multiplicationOperator = MatrixMultiplicationOperator<DT>();

	MatrixAdditionOperator<Rational<BigInt>> rationalAdditionOperator = MatrixAdditionOperator<Rational<BigInt>>();
	MatrixMultiplicationOperator<Rational<BigInt>> rationalMultiplicationOperator = MatrixMultiplicationOperator<Rational<BigInt>>();

	std::map<std::string, MatrixOperator<DT>*> matrixOperatorByToken = {
		{"+", &additionOperator},
		{"*", &multiplicationOperator}
	};

	std::map<std::string, MatrixOperator<Rational<BigInt>>*> rationalOperatorByToken = {
		{"+", &rationalAdditionOperator},
		{"*", &rationalMultiplicationOperator}
	};
	if (benchmark) {
		runBenchmark<DT>(
			tokens,
			matrixOperatorByToken,
			rationalOperatorByToken,
			benchmarkStartSize,
			benchmarkStopSize,
			benchmarkStepSize,
			benchmarkBatchSize
		);
	} else {
		runSolve<DT>(tokens, matrixOperatorByToken);
	}
}


void run(
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
				benchmark,
				benchmarkStartSize,
				benchmarkStopSize,
				benchmarkStepSize,
				benchmarkBatchSize
			);
		case Datatype::FLOAT:
			return runWithDatatype<float>(
				benchmark,
				benchmarkStartSize,
				benchmarkStopSize,
				benchmarkStepSize,
				benchmarkBatchSize
			);
		case Datatype::DOUBLE:
			return runWithDatatype<double>(
				benchmark,
				benchmarkStartSize,
				benchmarkStopSize,
				benchmarkStepSize,
				benchmarkBatchSize
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
	int& benchmarkStartSize,
	int& benchmarkStopSize,
	int& benchmarkStepSize,
	int& benchmarkBatchSize
) {
	app.add_option("-d,--datatype", datatype, "Datatype")
		->required()
		->transform(CLI::CheckedTransformer(datatypeByString, CLI::ignore_case));
	app.add_flag("-b,--benchmark", benchmark, "Benchmark");
	app.add_option("-r,--seed", seed, "Seed")
		->default_val(0);
	app.add_option("-s,--benchmark-start-size", benchmarkStartSize, "Benchmark start size")
		->default_val(0);
	app.add_option("-e,--benchmark-stop-size", benchmarkStopSize, "Benchmark stop size")
		->default_val(0);
	app.add_option("-i,--benchmark-step-size", benchmarkStepSize, "Benchmark step size")
		->default_val(1);
	app.add_option("-n,--benchmark-batch-size", benchmarkBatchSize, "Benchmark batch size")
		->default_val(0);
}

int main(int argc, char *argv[]) {
	CLI::App app{"Matrix Calculator"};

	Datatype datatype;
	bool benchmark = false;
	int seed;
	int benchmarkStartSize;
	int benchmarkStopSize;
	int benchmarkStepSize;
	int benchmarkBatchSize;

	applyOptions(
		app, datatype,
		benchmark,
		seed,
		benchmarkStartSize,
		benchmarkStopSize,
		benchmarkStepSize,
		benchmarkBatchSize
	);
	CLI11_PARSE(app, argc, argv);
	srand(seed);
	run(
		datatype,
		benchmark,
		benchmarkStartSize,
		benchmarkStopSize,
		benchmarkStepSize,
		benchmarkBatchSize
	);

	return 0;
}

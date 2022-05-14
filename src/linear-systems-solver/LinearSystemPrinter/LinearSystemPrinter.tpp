#include "./LinearSystemPrinter.hpp"
#include <iostream>


template <typename T>
void LinearSystemPrinter<T>::printSize(const LinearSystem<T>& linearSystem) const {
	std::cout << linearSystem.size.equationsCount << separator << linearSystem.size.variablesCount << '\n';
}

template <typename T>
void LinearSystemPrinter<T>::printVariables(const LinearSystem<T>& linearSystem) const {
	std::cout << linearSystem.getVariable(0);
	for (int i = 1; i < linearSystem.size.variablesCount; ++i) {
		std::cout << separator << linearSystem.getVariable(i);
	}
	std::cout << '\n';
}

template <typename T>
void LinearSystemPrinter<T>::printCoefficientsAndConstants(const LinearSystem<T>& linearSystem) const {
	for (int y = 0; y < linearSystem.size.equationsCount; ++y) {
		std::cout << linearSystem.getCoefficient(y, 0);
		for (int x = 1; x < linearSystem.size.variablesCount; ++x) {
			std::cout << separator << linearSystem.getCoefficient(y, x);
		}
		std::cout << separator << linearSystem.getConstant(y) << '\n';
	}
}

template <typename T>
void LinearSystemPrinter<T>::print(const LinearSystem<T>& linearSystem) const {
	printSize(linearSystem);
	if (linearSystem.size.variablesCount > 0) {
		printVariables(linearSystem);
	} else return;
	if (linearSystem.size.equationsCount > 0) {
		printCoefficientsAndConstants(linearSystem);
	}
}

template <typename T>
void LinearSystemPrinter<T>::print(const std::vector<T>& solutions) const {
	if (solutions.size() == 0) return;
	std::cout << solutions[0];
	for (int i = 1; i < solutions.size(); ++i) {
		std::cout << separator << solutions[i];
	}
	std::cout << '\n';
}

template <typename T>
LinearSystemPrinter<T>::LinearSystemPrinter(std::string separator) : separator(separator) {
}

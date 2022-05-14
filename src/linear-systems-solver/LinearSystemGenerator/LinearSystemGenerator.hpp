#ifndef LINEAR_SYSTEM_GENERATOR_H_INCLUDED
#define LINEAR_SYSTEM_GENERATOR_H_INCLUDED

#include <LinearSystem/LinearSystem.hpp>
#include <LinearSystem/LinearSystemSize/LinearSystemSize.hpp>
#include <iostream>
#include <random>


template <typename T>
class LinearSystemGenerator {
	private:
	long generateRandomLong();
	std::string generateVariable(int variableIndex);
	T generateRandomNumber();
	const int min;
	const int max;
	const int divisor;
	const LinearSystemSize size;
	public:
	LinearSystemGenerator(int a_size, int min, int max, int divisor);
	LinearSystem<T> generate();
};

#include "./LinearSystemGenerator.tpp"

#endif

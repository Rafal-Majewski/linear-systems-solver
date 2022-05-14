#ifndef LINEAR_SYSTEM_GENERATOR_H_INCLUDED
#define LINEAR_SYSTEM_GENERATOR_H_INCLUDED

#include <iostream>
#include <random>
#include <vector>
#include <LinearSystem/LinearSystem.hpp>
#include <LinearSystem/LinearSystemSize/LinearSystemSize.hpp>


template <typename T>
class LinearSystemGenerator {
	private:
	long generateRandomLong() const;
	T generateRandomNumber() const;
	const int min;
	const int max;
	const int divisor;
	const LinearSystemSize size;
	public:
	LinearSystemGenerator(int a_size, int min, int max, int divisor);
	std::pair<LinearSystem<T>, std::vector<T>> generate() const;
};

#include "./LinearSystemGenerator.tpp"

#endif

#ifndef LINEAR_SYSTEM_READER_H_INCLUDED
#define LINEAR_SYSTEM_READER_H_INCLUDED

#include <LinearSystem/LinearSystem.hpp>
#include <LinearSystem/LinearSystemSize/LinearSystemSize.hpp>
#include <iostream>


template <typename T>
class LinearSystemReader {
	private:
	LinearSystemSize readSize() const;
	std::pair<Matrix<T>, std::vector<T>> readCoefficientsAndConstants(LinearSystemSize size) const;
	std::vector<std::string> readVariables(LinearSystemSize size) const;

	public:
	LinearSystem<T> read() const;
};

#include "./LinearSystemReader.tpp"

#endif

#ifndef LINEAR_SYSTEM_PRINTER_H_INCLUDED
#define LINEAR_SYSTEM_PRINTER_H_INCLUDED

#include <LinearSystem/LinearSystem.hpp>


template <typename T>
class LinearSystemPrinter {
	private:
	void printSize(const LinearSystem<T>& linearSystem) const;
	void printCoefficientsAndConstants(const LinearSystem<T>& linearSystem) const;
	public:
	const std::string separator;
	void print(const LinearSystem<T>& linearSystem) const;
	void print(const std::vector<T>& solutions) const;
	LinearSystemPrinter(std::string separator);
};

#include "./LinearSystemPrinter.tpp"

#endif

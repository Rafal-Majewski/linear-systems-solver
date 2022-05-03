#include <LinearSystem/LinearSystem.h>
#include <LinearSystem/LinearSystemSize/LinearSystemSize.h>
#include <iostream>


template <typename T>
class LinearSystemReader {
	private:
	LinearSystemSize readSize() const;
	public:
	LinearSystem<T> read() const;
};

template <typename T>
LinearSystemSize LinearSystemReader<T>::readSize() const {
	int equationsCount;
	int variablesCount;
	std::cin >> equationsCount >> variablesCount;
	return LinearSystemSize(equationsCount, variablesCount);
}

template <typename T>
LinearSystem<T> LinearSystemReader<T>::read() const {
	LinearSystemSize size = readSize();
	std::cout << size << std::endl;
}

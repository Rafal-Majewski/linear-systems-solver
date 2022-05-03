#include <LinearSystem/LinearSystem.h>
#include <LinearSystem/Size/Size.h>
#include <iostream>


template <typename T>
class LinearSystemReader {
	private:
	Size readSize() const;
	public:
	LinearSystem<T> read() const;
};

template <typename T>
Size LinearSystemReader<T>::readSize() const {
	int equationsCount;
	int variablesCount;
	std::cin >> equationsCount >> variablesCount;
	return Size(equationsCount, variablesCount);
}

template <typename T>
LinearSystem<T> LinearSystemReader<T>::read() const {
	Size size = readSize();
}

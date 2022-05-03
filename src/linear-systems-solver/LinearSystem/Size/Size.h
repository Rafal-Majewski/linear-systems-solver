#ifndef SIZE_H_INCLUDED
#define SIZE_H_INCLUDED

#include <string>

struct Size {
	const int equationsCount;
	const int variablesCount;
	Size(int a_equationsCount, int a_variablesCount);
	bool operator!=(const Size &other) const;
	bool operator==(const Size &other) const;
	operator std::string() const;
};

#endif

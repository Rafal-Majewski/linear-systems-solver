#ifndef SIZE_H_INCLUDED
#define SIZE_H_INCLUDED

#include <string>

struct Size {
	const int rowsCount;
	const int columnsCount;
	Size(int a_rowsCount, int a_columnsCount);
	bool operator!=(const Size &other) const;
	bool operator==(const Size &other) const;
	operator std::string() const;
};

#endif

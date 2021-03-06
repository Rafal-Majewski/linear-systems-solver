#ifndef LINEAR_SYSTEM_SIZE_H_INCLUDED
#define LINEAR_SYSTEM_SIZE_H_INCLUDED

#include <string>


struct LinearSystemSize {
	const int equationsCount;
	const int variablesCount;
	LinearSystemSize(int a_equationsCount, int a_variablesCount);
	bool operator!=(const LinearSystemSize &other) const;
	bool operator==(const LinearSystemSize &other) const;
};

std::ostream &operator<<(std::ostream &os, const LinearSystemSize &size);

#endif

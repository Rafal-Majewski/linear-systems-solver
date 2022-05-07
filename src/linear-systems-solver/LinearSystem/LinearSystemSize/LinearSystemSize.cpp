#include "./LinearSystemSize.hpp"


LinearSystemSize::LinearSystemSize(int a_equationsCount, int a_variablesCount) : equationsCount(a_equationsCount), variablesCount(a_variablesCount) {
}

bool LinearSystemSize::operator==(const LinearSystemSize &other) const {
	return equationsCount == other.equationsCount && variablesCount == other.variablesCount;
}

bool LinearSystemSize::operator!=(const LinearSystemSize &other) const {
	return equationsCount != other.equationsCount || variablesCount != other.variablesCount;
}

std::ostream &operator<<(std::ostream &os, const LinearSystemSize &size) {
	os << size;
	return os;
}

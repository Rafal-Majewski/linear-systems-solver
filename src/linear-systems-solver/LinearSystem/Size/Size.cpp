#include "Size.h"


Size::Size(int a_equationsCount, int a_variablesCount) : equationsCount(a_equationsCount), variablesCount(a_variablesCount) {
}

bool Size::operator==(const Size &other) const {
	return equationsCount == other.equationsCount && variablesCount == other.variablesCount;
}

bool Size::operator!=(const Size &other) const {
	return equationsCount != other.equationsCount || variablesCount != other.variablesCount;
}

Size::operator std::string() const {
	return "Size(" + std::to_string(equationsCount) + ", " + std::to_string(variablesCount) + ")";
}

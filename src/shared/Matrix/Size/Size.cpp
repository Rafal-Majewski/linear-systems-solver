#include "Size.h"


Size::Size(int a_rowsCount, int a_columnsCount) : rowsCount(a_rowsCount), columnsCount(a_columnsCount) {
}

bool Size::operator==(const Size &other) const {
	return rowsCount == other.rowsCount && columnsCount == other.columnsCount;
}

bool Size::operator!=(const Size &other) const {
	return rowsCount != other.rowsCount || columnsCount != other.columnsCount;
}

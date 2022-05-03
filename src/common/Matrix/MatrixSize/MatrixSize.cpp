#include "MatrixSize.h"


MatrixSize::MatrixSize(int a_rowsCount, int a_columnsCount) : rowsCount(a_rowsCount), columnsCount(a_columnsCount) {
}

bool MatrixSize::operator==(const MatrixSize &other) const {
	return rowsCount == other.rowsCount && columnsCount == other.columnsCount;
}

bool MatrixSize::operator!=(const MatrixSize &other) const {
	return rowsCount != other.rowsCount || columnsCount != other.columnsCount;
}

MatrixSize::operator std::string() const {
	return "MatrixSize(" + std::to_string(rowsCount) + ", " + std::to_string(columnsCount) + ")";
}

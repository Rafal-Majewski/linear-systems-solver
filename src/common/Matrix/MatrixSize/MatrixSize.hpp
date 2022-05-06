#ifndef MATRIX_SIZE_H_INCLUDED
#define MATRIX_SIZE_H_INCLUDED

#include <string>

struct MatrixSize {
	const int rowsCount;
	const int columnsCount;
	MatrixSize(int a_rowsCount, int a_columnsCount);
	bool operator!=(const MatrixSize &other) const;
	bool operator==(const MatrixSize &other) const;
	MatrixSize transposed() const;
	MatrixSize multipliedBy(MatrixSize other) const;
};

#endif

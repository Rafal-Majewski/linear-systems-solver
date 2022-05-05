#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include "./MatrixSize/MatrixSize.h"
#include "./InvalidMatrixSizeException/InvalidMatrixSizeException.h"
#include <stdexcept>
#include <vector>


template <typename T>
class Matrix {
	std::vector<std::vector<T>> values;
	static void assertEqualMatrixSizes(const Matrix<T> &first, const Matrix<T> &second);
	static bool areMatrixSizesEqual(const Matrix<T> &first, const Matrix<T> &second);
	void assertInBounds(int y, int x) const;
	public:
	operator std::string() const;
	friend std::ostream &operator<<(std::ostream &os, const Matrix<T> &matrix) {
		os << std::string(matrix);
		return os;
	};
	const MatrixSize size;
	Matrix(MatrixSize a_size);
	// ~Matrix();
	static Matrix<T> unit(MatrixSize a_size);
	static Matrix<T> fromValues(MatrixSize a_size, std::vector<std::vector<T>> values);
	T get(int y, int x) const;
	void set(int y, int x, T value);
	Matrix<T> transpose() const;
	Matrix<T> copy() const;

	// Because of the compiler errors
	// operators have to be defined here.
	// Please submit a comment or a pull request
	// if you know how to fix it.

	friend Matrix<T> operator+(const Matrix<T> &lhs, const Matrix<T> &rhs) {
		if (lhs.size != rhs.size) {
			throw InvalidMatrixSizeException("Matrixes have different sizes");
		}
		Matrix<T> matrix = lhs.copy();
		for (int y = 0; y < lhs.size.rowsCount; ++y) {
			for (int x = 0; x < lhs.size.columnsCount; ++x) {
				matrix.values[y][x] += rhs.values[y][x];
			}
		}
		return matrix;
	}
	friend Matrix<T> operator-(const Matrix<T> &lhs, const Matrix<T> &rhs) {
		if (lhs.size != rhs.size) {
			throw InvalidMatrixSizeException("Matrixes have different sizes");
		}
		Matrix<T> matrix = lhs.copy();
		for (int y = 0; y < lhs.size.rowsCount; ++y) {
			for (int x = 0; x < lhs.size.columnsCount; ++x) {
				matrix.values[y][x] -= rhs.values[y][x];
			}
		}
		return matrix;
	}
	friend Matrix<T> operator*(const Matrix<T> &lhs, const Matrix<T> &rhs) {
		if (lhs.size.columnsCount != rhs.size.rowsCount) {
			throw InvalidMatrixSizeException("Matrixes cannot be multiplied");
		}
		Matrix<T> matrix = Matrix<T>(MatrixSize(lhs.size.rowsCount, rhs.size.columnsCount));
		for (int y = 0; y < matrix.size.rowsCount; ++y) {
			for (int x = 0; x < matrix.size.columnsCount; ++x) {
				matrix.values[y][x] = 0;
				for (int i = 0; i < lhs.size.columnsCount; ++i) {
					matrix.values[y][x] += lhs.values[y][i] * rhs.values[i][x];
				}
			}
		}
		return matrix;
	}
	friend Matrix<T> operator*(const Matrix<T> &lhs, T rhs) {
		Matrix<T> matrix = lhs.copy();
		for (int y = 0; y < lhs.size.rowsCount; ++y) {
			for (int x = 0; x < lhs.size.columnsCount; ++x) {
				matrix.values[y][x] *= rhs;
			}
		}
		return matrix;
	}
	friend Matrix<T> operator*(T lhs, const Matrix<T> &rhs) {
		Matrix<T> matrix = rhs.copy();
		for (int y = 0; y < rhs.size.rowsCount; ++y) {
			for (int x = 0; x < rhs.size.columnsCount; ++x) {
				matrix.values[y][x] *= lhs;
			}
		}
		return matrix;
	}
	friend bool operator==(const Matrix<T> &lhs, const Matrix<T> &rhs) {
		if (!Matrix<T>::areMatrixSizesEqual(lhs, rhs)) {
			return false;
		}
		for (int y = 0; y < lhs.size.rowsCount; ++y) {
			for (int x = 0; x < lhs.size.columnsCount; ++x) {
				if (lhs.values[y][x] != rhs.values[y][x]) {
					return false;
				}
			}
		}
		return true;
	}
	friend bool operator!=(const Matrix<T> &lhs, const Matrix<T> &rhs) {
		if (!Matrix<T>::areMatrixSizesEqual(lhs, rhs)) {
			return true;
		}
		for (int y = 0; y < lhs.size.rowsCount; ++y) {
			for (int x = 0; x < lhs.size.columnsCount; ++x) {
				if (lhs.values[y][x] != rhs.values[y][x]) {
					return true;
				}
			}
		}
		return false;
	}
};

template <typename T>
Matrix<T>::operator std::string() const {
	std::string result = "Matrix("
		+ std::string(size)
		+ ")[";
	for (int y = 0; y < size.rowsCount; ++y) {
		result += "[";
		for (int x = 0; x < size.columnsCount; ++x) {
			result += std::to_string(values[y][x]);
			if (x != size.columnsCount - 1) {
				result += ", ";
			}
		}
		result += "]";
		if (y != size.rowsCount - 1) {
			result += ", ";
		}
	}
	result += "]";
	return result;
}

template <typename T>
bool Matrix<T>::areMatrixSizesEqual(const Matrix<T> &first, const Matrix<T> &second) {
	return first.size == second.size;
}

template <typename T>
void Matrix<T>::assertEqualMatrixSizes(const Matrix<T> &first, const Matrix<T> &second) {
	if (!Matrix<T>::areMatrixSizesEqual(first, second)) {
		throw InvalidMatrixSizeException("Matrixes have different sizes");
	}
}

template <typename T>
void Matrix<T>::assertInBounds(int y, int x) const {
	if (y < 0 || y >= size.rowsCount || x < 0 || x >= size.columnsCount) {
		throw std::out_of_range("Out of bounds operation.");
	}
}

template <typename T>
Matrix<T> Matrix<T>::copy() const {
	Matrix<T> result(size);
	for (int y = 0; y < size.rowsCount; y++) {
		for (int x = 0; x < size.columnsCount; x++) {
			result.values[y][x] = values[y][x];
		}
	}
	return result;
}

template <typename T>
Matrix<T>::Matrix(MatrixSize a_size) : size(a_size) {
	values = std::vector<std::vector<T>>(size.rowsCount, std::vector<T>(size.columnsCount));
	// values = new T*[size.rowsCount];
	// for (int y = 0; y < size.rowsCount; ++y) {
	// 	values[y] = new T[size.columnsCount];
	// }
}




template <typename T>
Matrix<T> Matrix<T>::unit(MatrixSize a_size) {
	if (a_size.rowsCount != a_size.columnsCount) {
		throw InvalidMatrixSizeException("Matrix must be square");
	}
	Matrix<T> matrix = Matrix<T>(a_size);
	for (int y = 0; y < a_size.rowsCount; ++y) {
		for (int x = 0; x < a_size.columnsCount; ++x) {
			matrix.values[y][x] = (y == x) ? 1 : 0;
		}
	}
	return matrix;
}

template <typename T>
Matrix<T> Matrix<T>::fromValues(MatrixSize a_size, std::vector<std::vector<T>> a_values) {
	Matrix<T> matrix = Matrix<T>(a_size);
	for (int y = 0; y < a_size.rowsCount; ++y) {
		for (int x = 0; x < a_size.columnsCount; ++x) {
			matrix.values[y][x] = a_values[y][x];
		}
	}
	return matrix;
}

// template <typename T>
// Matrix<T> Matrix<T>::fromValues(MatrixSize a_size, T *a_values) {
// 	Matrix<T> matrix = Matrix<T>(a_size);
// 	for (int y = 0, i = 0; y < a_size.rowsCount; ++y) {
// 		for (int x = 0; x < a_size.columnsCount; ++x, ++i) {
// 			matrix.values[y][x] = a_values[i];
// 		}
// 	}
// 	return matrix;
// }

template <typename T>
T Matrix<T>::get(int y, int x) const {
	assertInBounds(y, x);
	return values[y][x];
}

template <typename T>
void Matrix<T>::set(int y, int x, T value) {
	assertInBounds(y, x);
	values[y][x] = value;
}

template <typename T>
Matrix<T> Matrix<T>::transpose() const {
	Matrix<T> matrix = Matrix<T>(MatrixSize(size.columnsCount, size.rowsCount));
	for (int y = 0; y < size.rowsCount; ++y) {
		for (int x = 0; x < size.columnsCount; ++x) {
			matrix.values[x][y] = values[y][x];
		}
	}
	return matrix;
}

#endif

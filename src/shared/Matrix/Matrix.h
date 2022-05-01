#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include "./Size/Size.h"
#include "./WrongMatrixSizeException/WrongMatrixSizeException.h"
#include <stdexcept>


template <typename T>
class Matrix {
	T **values;
	static void throwIfDifferentSizes(const Matrix<T> &first, const Matrix<T> &second);
	static bool areSizesEqual(const Matrix<T> &first, const Matrix<T> &second);
	void throwIfOutOfBounds(int y, int x) const;
	public:
	const Size size;
	Matrix(Size a_size);
	~Matrix();
	static Matrix<T> unit(Size a_size);
	static Matrix<T> fromValues(Size a_size, T **a_values);
	static Matrix<T> fromValues(Size a_size, T *a_values);
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
			throw WrongMatrixSizeException("Matrixes have different sizes");
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
			throw WrongMatrixSizeException("Matrixes have different sizes");
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
			throw WrongMatrixSizeException("Matrixes cannot be multiplied");
		}
		Matrix<T> matrix = Matrix<T>(Size(lhs.size.rowsCount, rhs.size.columnsCount));
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
		if (!Matrix<T>::areSizesEqual(lhs, rhs)) {
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
		if (!Matrix<T>::areSizesEqual(lhs, rhs)) {
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
bool Matrix<T>::areSizesEqual(const Matrix<T> &first, const Matrix<T> &second) {
	return first.size == second.size;
}

template <typename T>
void Matrix<T>::throwIfDifferentSizes(const Matrix<T> &first, const Matrix<T> &second) {
	if (!Matrix<T>::areSizesEqual(first, second)) {
		throw WrongMatrixSizeException("Matrixes have different sizes");
	}
}

template <typename T>
void Matrix<T>::throwIfOutOfBounds(int y, int x) const {
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
Matrix<T>::Matrix(Size a_size) : size(a_size) {
	values = new T*[size.rowsCount];
	for (int y = 0; y < size.rowsCount; ++y) {
		values[y] = new T[size.columnsCount];
	}
}


template <typename T>
Matrix<T>::~Matrix() {
	for (int y = 0; y < size.rowsCount; ++y) {
		delete[] values[y];
	}
	delete[] values;
}

template <typename T>
Matrix<T> Matrix<T>::unit(Size a_size) {
	if (a_size.rowsCount != a_size.columnsCount) {
		throw WrongMatrixSizeException("Matrix must be square");
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
Matrix<T> Matrix<T>::fromValues(Size a_size, T **a_values) {
	Matrix<T> matrix = Matrix<T>(a_size);
	for (int y = 0; y < a_size.rowsCount; ++y) {
		for (int x = 0; x < a_size.columnsCount; ++x) {
			matrix.values[y][x] = a_values[y][x];
		}
	}
	return matrix;
}

template <typename T>
Matrix<T> Matrix<T>::fromValues(Size a_size, T *a_values) {
	Matrix<T> matrix = Matrix<T>(a_size);
	for (int y = 0, i = 0; y < a_size.rowsCount; ++y) {
		for (int x = 0; x < a_size.columnsCount; ++x, ++i) {
			matrix.values[y][x] = a_values[i];
		}
	}
	return matrix;
}

template <typename T>
T Matrix<T>::get(int y, int x) const {
	throwIfOutOfBounds(y, x);
	return values[y][x];
}

template <typename T>
void Matrix<T>::set(int y, int x, T value) {
	throwIfOutOfBounds(y, x);
	values[y][x] = value;
}

template <typename T>
Matrix<T> Matrix<T>::transpose() const {
	Matrix<T> matrix = Matrix<T>(Size(size.columnsCount, size.rowsCount));
	for (int y = 0; y < size.rowsCount; ++y) {
		for (int x = 0; x < size.columnsCount; ++x) {
			matrix.values[x][y] = values[y][x];
		}
	}
	return matrix;
}

#endif

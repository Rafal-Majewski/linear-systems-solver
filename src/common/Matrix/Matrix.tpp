#include "./Matrix.hpp"


template <typename T>
void Matrix<T>::assertValuesSizeMatchesMatrixSize() const {
	if (values.size() != size.rowsCount) {
		throw std::invalid_argument("Values size does not match matrix size");
	}
	for (int y = 0; y < size.rowsCount; ++y) {
		if (values[y].size() != size.columnsCount) {
			throw std::invalid_argument("Values size does not match matrix size");
		}
	}
}

template <typename T>
void Matrix<T>::assertEqualMatrixSize(const Matrix<T> &other) const {
	if (size != other.size) {
		throw InvalidMatrixSizeException("Matrixes have different sizes");
	}
}

template <typename T>
void Matrix<T>::assertMatrixSizeValidForMultiplication(const Matrix<T> &other) const {
	if (size.columnsCount != other.size.rowsCount) {
		throw InvalidMatrixSizeException("Matrixes size are not valid for multiplication");
	}
}

template <typename T>
Matrix<T>::Matrix(MatrixSize a_size) : size(a_size) {
	values.resize(size.rowsCount);
	for (int y = 0; y < size.rowsCount; ++y) {
		values[y].resize(size.columnsCount);
	}
}

template <typename T>
Matrix<T> Matrix<T>::unit(MatrixSize a_size) {
	Matrix<T> result(a_size);
	for (int y = 0; y < a_size.rowsCount; ++y) {
		for (int x = 0; x < a_size.columnsCount; ++x) {
			result.values[y][x] = (y == x) ? 1 : 0;
		}
	}
	return result;
}

template <typename T>
Matrix<T>::Matrix(MatrixSize a_size, std::vector<std::vector<T>> a_values) : size(a_size), values(a_values) {
	assertValuesSizeMatchesMatrixSize();
}

template <typename T>
Matrix<T>::Matrix(std::vector<std::vector<T>> a_values) : size(MatrixSize(a_values.size(), a_values.size() == 0 ? 0 : a_values[0].size())), values(a_values) {
	assertValuesSizeMatchesMatrixSize();
}

template <typename T>
void Matrix<T>::assertInBounds(int y, int x) const {
	if (y < 0 || y >= size.rowsCount) {
		throw std::out_of_range("Matrix row index out of bounds");
	}
	if (x < 0 || x >= size.columnsCount) {
		throw std::out_of_range("Matrix column index out of bounds");
	}
}

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
Matrix<T> Matrix<T>::transposed() const {
	Matrix<T> result(size.transposed());
	for (int y = 0; y < size.rowsCount; ++y) {
		for (int x = 0; x < size.columnsCount; ++x) {
			result.values[x][y] = values[y][x];
		}
	}
	return result;
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T> &other) : size(other.size), values(other.values) {
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &other) const {
	assertEqualMatrixSize(other);
	Matrix<T> result(*this);
	result += other;
	return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &other) const {
	assertEqualMatrixSize(other);
	Matrix<T> result(*this);
	result -= other;
	return result;
}

template <typename T>
std::vector<std::vector<T>> Matrix<T>::getValues() const {
	return values;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &other) const {
	assertMatrixSizeValidForMultiplication(other);
	Matrix<T> result(size.multipliedBy(other.size));
	for (int y = 0; y < result.size.rowsCount; ++y) {
		for (int x = 0; x < result.size.columnsCount; ++x) {
			T sum = 0;
			for (int i = 0; i < size.columnsCount; ++i) {
				sum += values[y][i] * other.values[i][x];
			}
			result.values[y][x] = sum;
		}
	}
	return result;
}

template <typename T>
bool Matrix<T>::operator==(const Matrix<T> &other) const {
	if (size != other.size) {
		return false;
	}
	for (int y = 0; y < size.rowsCount; ++y) {
		for (int x = 0; x < size.columnsCount; ++x) {
			if (values[y][x] != other.values[y][x]) {
				return false;
			}
		}
	}
	return true;
}

template <typename T>
bool Matrix<T>::operator!=(const Matrix<T> &other) const {
	if (size != other.size) {
		return true;
	}
	for (int y = 0; y < size.rowsCount; ++y) {
		for (int x = 0; x < size.columnsCount; ++x) {
			if (values[y][x] != other.values[y][x]) {
				return true;
			}
		}
	}
	return false;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(T scalar) const {
	Matrix<T> result(size);
	for (int y = 0; y < size.rowsCount; ++y) {
		for (int x = 0; x < size.columnsCount; ++x) {
			result.values[y][x] = values[y][x] * scalar;
		}
	}
	return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator/(T scalar) const {
	Matrix<T> result(size);
	for (int y = 0; y < size.rowsCount; ++y) {
		for (int x = 0; x < size.columnsCount; ++x) {
			result.values[y][x] = values[y][x] / scalar;
		}
	}
	return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-() const {
	Matrix<T> result(*this);
	for (int y = 0; y < size.rowsCount; ++y) {
		for (int x = 0; x < size.columnsCount; ++x) {
			result.values[y][x] = -result.values[y][x];
		}
	}
	return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator+() const {
	Matrix<T> result(*this);
	for (int y = 0; y < size.rowsCount; ++y) {
		for (int x = 0; x < size.columnsCount; ++x) {
			result.values[y][x] = +result.values[y][x];
		}
	}
	return result;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(Matrix<T> other) {
	assertEqualMatrixSize(other);
	for (int y = 0; y < size.rowsCount; ++y) {
		for (int x = 0; x < size.columnsCount; ++x) {
			values[y][x] += other.values[y][x];
		}
	}
	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(Matrix<T> other) {
	assertEqualMatrixSize(other);
	for (int y = 0; y < size.rowsCount; ++y) {
		for (int x = 0; x < size.columnsCount; ++x) {
			values[y][x] -= other.values[y][x];
		}
	}
	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(T scalar) {
	for (int y = 0; y < size.rowsCount; ++y) {
		for (int x = 0; x < size.columnsCount; ++x) {
			values[y][x] *= scalar;
		}
	}
	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator/=(T scalar) {
	for (int y = 0; y < size.rowsCount; ++y) {
		for (int x = 0; x < size.columnsCount; ++x) {
			values[y][x] /= scalar;
		}
	}
	return *this;
}

template <typename T>
Matrix<T> operator*(T scalar, const Matrix<T> &matrix) {
	return matrix * scalar;
}

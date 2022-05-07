#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include "./MatrixSize/MatrixSize.hpp"
#include "./InvalidMatrixSizeException/InvalidMatrixSizeException.hpp"
#include <vector>


template <typename T>
class Matrix {
	private:
	void assertValuesSizeMatchesMatrixSize() const;
	void assertEqualMatrixSize(const Matrix<T> &other) const;
	void assertMatrixSizeValidForMultiplication(const Matrix<T> &other) const;
	void assertInBounds(int y, int x) const;
	

	std::vector<std::vector<T>> values;
	public:
	std::vector<std::vector<T>> getValues() const;
	const MatrixSize size;
	Matrix(MatrixSize a_size);
	static Matrix<T> unit(MatrixSize a_size);
	Matrix(MatrixSize a_size, std::vector<std::vector<T>> a_values);
	Matrix(std::vector<std::vector<T>> a_values);
	T get(int y, int x) const;
	void set(int y, int x, T value);
	Matrix<T> transposed() const;
	Matrix(const Matrix<T> &other);

	Matrix<T> operator+(const Matrix<T> &other) const;
	Matrix<T> operator-(const Matrix<T> &other) const;
	Matrix<T> operator*(const Matrix<T> &other) const;
	bool operator==(const Matrix<T> &other) const;
	bool operator!=(const Matrix<T> &other) const;
	Matrix<T> operator-() const;
	Matrix<T> operator+() const;
	Matrix<T> operator*(T scalar) const;
	Matrix<T> operator/(T scalar) const;
	Matrix<T>& operator+=(Matrix<T> other);
	Matrix<T>& operator-=(Matrix<T> other);
	Matrix<T>& operator*=(T scalar);
	Matrix<T>& operator/=(T scalar);
};

template <typename T>
Matrix<T> operator*(T scalar, const Matrix<T> &matrix);

#include "./Matrix.tpp"

#endif

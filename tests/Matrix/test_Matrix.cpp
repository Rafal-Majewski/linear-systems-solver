#include <gtest/gtest.h>
#include <Matrix/MatrixSize/MatrixSize.h>
#include <Matrix/Matrix.h>
#include <vector>


TEST(Matrix, fromValues) {
	Matrix<int> matrix = Matrix<int>::fromValues(
		MatrixSize(2, 2),
		std::vector<std::vector<int>>({
			{1, 2},
			{3, 4}
		})
	);
	EXPECT_EQ(matrix.get(0, 0), 1);
	EXPECT_EQ(matrix.get(0, 1), 2);
	EXPECT_EQ(matrix.get(1, 0), 3);
	EXPECT_EQ(matrix.get(1, 1), 4);
}

TEST(Matrix, scalar_multiplication_left) {
	Matrix<int> matrix = Matrix<int>::fromValues(
		MatrixSize(2, 2),
		// new int[4]{1, 2, 3, 4}
		std::vector<std::vector<int>>({
			{1, 2},
			{3, 4}
		})
	);
	Matrix<int> result = 2 * matrix;
	EXPECT_EQ(result.get(0, 0), 2);
	EXPECT_EQ(result.get(0, 1), 4);
	EXPECT_EQ(result.get(1, 0), 6);
	EXPECT_EQ(result.get(1, 1), 8);
}

TEST(Matrix, scalar_multiplication_right) {
	Matrix<int> matrix = Matrix<int>::fromValues(
		MatrixSize(2, 2),
		// new int[4]{1, 2, 3, 4}
		std::vector<std::vector<int>>({
			{1, 2},
			{3, 4}
		})
	);
	Matrix<int> result = matrix * 2;
	EXPECT_EQ(result.get(0, 0), 2);
	EXPECT_EQ(result.get(0, 1), 4);
	EXPECT_EQ(result.get(1, 0), 6);
	EXPECT_EQ(result.get(1, 1), 8);
}

TEST(Matrix, multiplication_quadratic) {
	Matrix<int> matrix1 = Matrix<int>::fromValues(
		MatrixSize(2, 2),
		std::vector<std::vector<int>>({
			{1, 2},
			{3, 4}
		})
	);
	Matrix<int> matrix2 = Matrix<int>::fromValues(
		MatrixSize(2, 2),
		// new int[4]{5, 6, 7, 8}
		std::vector<std::vector<int>>({
			{5, 6},
			{7, 8}
		})
	);
	Matrix<int> result = matrix1 * matrix2;
	EXPECT_EQ(result.get(0, 0), 19);
	EXPECT_EQ(result.get(0, 1), 22);
	EXPECT_EQ(result.get(1, 0), 43);
	EXPECT_EQ(result.get(1, 1), 50);
}


TEST(Matrix, multiplication_rectangular) {
	Matrix<int> matrix1 = Matrix<int>::fromValues(
		MatrixSize(3, 2),
		// new int[6]{
		// 	1, 2,
		// 	0, 1,
		// 	2, 3
		// }
		std::vector<std::vector<int>>({
			{1, 2},
			{0, 1},
			{2, 3}
		})
	);
	Matrix<int> matrix2 = Matrix<int>::fromValues(
		MatrixSize(2, 3),
		// new int[6]{
		// 	2, 5, 1,
		// 	6, 7, 1
		// }
		std::vector<std::vector<int>>({
			{2, 5, 1},
			{6, 7, 1}
		})
	);
	Matrix<int> result = matrix1 * matrix2;
	EXPECT_EQ(result.get(0, 0), 14);
	EXPECT_EQ(result.get(0, 1), 19);
	EXPECT_EQ(result.get(0, 2), 3);
	EXPECT_EQ(result.get(1, 0), 6);
	EXPECT_EQ(result.get(1, 1), 7);
	EXPECT_EQ(result.get(1, 2), 1);
	EXPECT_EQ(result.get(2, 0), 22);
	EXPECT_EQ(result.get(2, 1), 31);
	EXPECT_EQ(result.get(2, 2), 5);
}

TEST(Matrix, addition) {
	Matrix<int> matrix1 = Matrix<int>::fromValues(
		MatrixSize(2, 2),
		// new int[4]{1, 2, 3, 4}
		std::vector<std::vector<int>>({
			{1, 2},
			{3, 4}
		})
	);
	Matrix<int> matrix2 = Matrix<int>::fromValues(
		MatrixSize(2, 2),
		// new int[4]{5, 6, 7, 8}
		std::vector<std::vector<int>>({
			{5, 6},
			{7, 8}
		})
	);
	Matrix<int> result = matrix1 + matrix2;
	EXPECT_EQ(result.get(0, 0), 6);
	EXPECT_EQ(result.get(0, 1), 8);
	EXPECT_EQ(result.get(1, 0), 10);
	EXPECT_EQ(result.get(1, 1), 12);
}

TEST(Matrix, subtraction) {
	Matrix<int> matrix1 = Matrix<int>::fromValues(
		MatrixSize(2, 2),
		// new int[4]{1, 2, 3, 4}
		std::vector<std::vector<int>>({
			{1, 2},
			{3, 4}
		})
	);
	Matrix<int> matrix2 = Matrix<int>::fromValues(
		MatrixSize(2, 2),
		// new int[4]{52, 3, 22, 1}
		std::vector<std::vector<int>>({
			{52, 3},
			{22, 1}
		})
	);
	Matrix<int> result = matrix1 - matrix2;
	EXPECT_EQ(result.get(0, 0), -51);
	EXPECT_EQ(result.get(0, 1), -1);
	EXPECT_EQ(result.get(1, 0), -19);
	EXPECT_EQ(result.get(1, 1), 3);
}

TEST(Matrix, transpose) {
	Matrix<int> matrix = Matrix<int>::fromValues(
		MatrixSize(3, 2),
		// new int[6]{
		// 	1, 2,
		// 	0, 1,
		// 	2, 3
		// }
		std::vector<std::vector<int>>({
			{1, 2},
			{0, 1},
			{2, 3}
		})
	);
	Matrix<int> result = matrix.transpose();
	EXPECT_EQ(result.get(0, 0), 1);
	EXPECT_EQ(result.get(0, 1), 0);
	EXPECT_EQ(result.get(0, 2), 2);
	EXPECT_EQ(result.get(1, 0), 2);
	EXPECT_EQ(result.get(1, 1), 1);
	EXPECT_EQ(result.get(1, 2), 3);
}

TEST(Matrix, out_of_bounds_get_right) {
	Matrix<int> matrix = Matrix<int>::fromValues(
		MatrixSize(3, 2),
		// new int[6]{
		// 	1, 2,
		// 	0, 1,
		// 	2, 3
		// }
		std::vector<std::vector<int>>({
			{1, 2},
			{0, 1},
			{2, 3}
		})
	);
	EXPECT_THROW(matrix.get(0, 2), std::out_of_range);
}


TEST(Matrix, out_of_bounds_get_left) {
	Matrix<int> matrix = Matrix<int>::fromValues(
		MatrixSize(3, 2),
		// new int[6]{
		// 	1, 2,
		// 	0, 1,
		// 	2, 3
		// }
		std::vector<std::vector<int>>({
			{1, 2},
			{0, 1},
			{2, 3}
		})
	);
	EXPECT_THROW(matrix.get(0, -1), std::out_of_range);
}

TEST(Matrix, out_of_bounds_get_top) {
	Matrix<int> matrix = Matrix<int>::fromValues(
		MatrixSize(3, 2),
		// new int[6]{
		// 	1, 2,
		// 	0, 1,
		// 	2, 3
		// }
		std::vector<std::vector<int>>({
			{1, 2},
			{0, 1},
			{2, 3}
		})
	);
	EXPECT_THROW(matrix.get(-1, 0), std::out_of_range);
}

TEST(Matrix, out_of_bounds_get_bottom) {
	Matrix<int> matrix = Matrix<int>::fromValues(
		MatrixSize(3, 2),
		// new int[6]{
		// 	1, 2,
		// 	0, 1,
		// 	2, 3
		// }
		std::vector<std::vector<int>>({
			{1, 2},
			{0, 1},
			{2, 3}
		})
	);
	EXPECT_THROW(matrix.get(3, 0), std::out_of_range);
}

TEST(Matrix, out_of_bounds_set) {
	Matrix<int> matrix = Matrix<int>::fromValues(
		MatrixSize(3, 2),
		// new int[6]{
		// 	1, 2,
		// 	0, 1,
		// 	2, 3
		// }
		std::vector<std::vector<int>>({
			{1, 2},
			{0, 1},
			{2, 3}
		})
	);
	EXPECT_THROW(matrix.set(0, 2, 0), std::out_of_range);
}

TEST(Matrix, equality_true) {
	Matrix<int> matrix1 = Matrix<int>::fromValues(
		MatrixSize(3, 2),
		// new int[6]{
		// 	1, 2,
		// 	0, 1,
		// 	2, 3
		// }
		std::vector<std::vector<int>>({
			{1, 2},
			{0, 1},
			{2, 3}
		})
	);
	Matrix<int> matrix2 = Matrix<int>::fromValues(
		MatrixSize(3, 2),
		// new int[6]{
		// 	1, 2,
		// 	0, 1,
		// 	2, 3
		// }
		std::vector<std::vector<int>>({
			{1, 2},
			{0, 1},
			{2, 3}
		})
	);
	EXPECT_TRUE(matrix1 == matrix2);
}


TEST(Matrix, inequality_false) {
	Matrix<int> matrix1 = Matrix<int>::fromValues(
		MatrixSize(3, 2),
		// new int[6]{
		// 	1, 2,
		// 	0, 1,
		// 	2, 3
		// }
		std::vector<std::vector<int>>({
			{1, 2},
			{0, 1},
			{2, 3}
		})
	);
	Matrix<int> matrix2 = Matrix<int>::fromValues(
		MatrixSize(3, 2),
		// new int[6]{
		// 	1, 2,
		// 	0, 1,
		// 	2, 3
		// }
		std::vector<std::vector<int>>({
			{1, 2},
			{0, 1},
			{2, 3}
		})
	);
	EXPECT_FALSE(matrix1 != matrix2);
}

TEST(Matrix, equality_false_different_size) {
	Matrix<int> matrix1 = Matrix<int>::fromValues(
		MatrixSize(3, 2),
		// new int[6]{
		// 	1, 2,
		// 	0, 1,
		// 	2, 3
		// }
		std::vector<std::vector<int>>({
			{1, 2},
			{0, 1},
			{2, 3}
		})
	);
	Matrix<int> matrix2 = Matrix<int>::fromValues(
		MatrixSize(2, 2),
		// new int[4]{
		// 	1, 2,
		// 	0, 1
		// }
		std::vector<std::vector<int>>({
			{1, 2},
			{0, 1}
		})
	);
	EXPECT_FALSE(matrix1 == matrix2);
}

TEST(Matrix, inequality_true_different_size) {
	Matrix<int> matrix1 = Matrix<int>::fromValues(
		MatrixSize(3, 2),
		// new int[6]{
		// 	1, 2,
		// 	0, 1,
		// 	2, 3
		// }
		std::vector<std::vector<int>>({
			{1, 2},
			{0, 1},
			{2, 3}
		})
	);
	Matrix<int> matrix2 = Matrix<int>::fromValues(
		MatrixSize(2, 2),
		// new int[4]{
		// 	1, 2,
		// 	0, 1
		// }
		std::vector<std::vector<int>>({
			{1, 2},
			{0, 1}
		})
	);
	EXPECT_TRUE(matrix1 != matrix2);
}

TEST(Matrix, equality_false_different_values) {
	Matrix<int> matrix1 = Matrix<int>::fromValues(
		MatrixSize(3, 2),
		// new int[6]{
		// 	1, 2,
		// 	0, 1,
		// 	2, 3
		// }
		std::vector<std::vector<int>>({
			{1, 2},
			{0, 1},
			{2, 3}
		})
	);
	Matrix<int> matrix2 = Matrix<int>::fromValues(
		MatrixSize(3, 2),
		// new int[6]{
		// 	1, 2,
		// 	0, 1,
		// 	2, 2
		// }
		std::vector<std::vector<int>>({
			{1, 2},
			{0, 1},
			{2, 2}
		})
	);
	EXPECT_FALSE(matrix1 == matrix2);
}

TEST(Matrix, inequality_true_different_values) {
	Matrix<int> matrix1 = Matrix<int>::fromValues(
		MatrixSize(3, 2),
		// new int[6]{
		// 	1, 2,
		// 	0, 1,
		// 	2, 3
		// }
		std::vector<std::vector<int>>({
			{1, 2},
			{0, 1},
			{2, 3}
		})
	);
	Matrix<int> matrix2 = Matrix<int>::fromValues(
		MatrixSize(3, 2),
		// new int[6]{
		// 	1, 2,
		// 	0, 1,
		// 	2, 2
		// }
		std::vector<std::vector<int>>({
			{1, 2},
			{0, 1},
			{2, 2}
		})
	);
	EXPECT_TRUE(matrix1 != matrix2);
}

#include <gtest/gtest.h>
#include <Matrix/MatrixSize/MatrixSize.h>


TEST(MatrixSize, constructor) {
	MatrixSize size(1, 2);
	EXPECT_EQ(1, size.rowsCount);
	EXPECT_EQ(2, size.columnsCount);
}

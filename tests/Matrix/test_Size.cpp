#include <gtest/gtest.h>
#include <Matrix/Size/Size.h>


TEST(Size, constructor) {
	Size size(1, 2);
	EXPECT_EQ(1, size.rowsCount);
	EXPECT_EQ(2, size.columnsCount);
}

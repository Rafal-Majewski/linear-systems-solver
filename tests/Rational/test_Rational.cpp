#include <gtest/gtest.h>
#include <Rational/Rational.hpp>


TEST(Rational, constructor_1_with_2) {
	Rational<int> q(1, 2);
	EXPECT_EQ(q.getNumerator(), 1);
	EXPECT_EQ(q.getDenominator(), 2);
}

TEST(Rational, equality_operator_2_3_with_2_3) {
	Rational<int> q1(2, 3);
	Rational<int> q2(2, 3);
	EXPECT_TRUE(q1 == q2);
}

TEST(Rational, equality_operator_2_8_with_2_10) {
	Rational<int> q1(2, 8);
	Rational<int> q2(2, 10);
	EXPECT_FALSE(q1 == q2);
}



TEST(Rational, constructor_45_with_9) {
	Rational<int> q(45, 9);
	EXPECT_EQ(q.getNumerator(), 5);
	EXPECT_EQ(q.getDenominator(), 1);
}

TEST(Rational, constructor_minus_45_with_9) {
	Rational<int> q(-45, 9);
	EXPECT_EQ(q.getNumerator(), -5);
	EXPECT_EQ(q.getDenominator(), 1);
}

TEST(Rational, constructor_45_with_minus_9) {
	Rational<int> q(45, -9);
	EXPECT_EQ(q.getNumerator(), -5);
	EXPECT_EQ(q.getDenominator(), 1);
}

TEST(Rational, constructor_minus_45_with_minus_9) {
	Rational<int> q(-45, -9);
	EXPECT_EQ(q.getNumerator(), 5);
	EXPECT_EQ(q.getDenominator(), 1);
}

TEST(Rational, constructor_0_with_3) {
	Rational<int> q(0, 3);
	EXPECT_EQ(q.getNumerator(), 0);
	EXPECT_EQ(q.getDenominator(), 1);
}

TEST(Rational, constructor_0_with_minus_3) {
	Rational<int> q(0, -3);
	EXPECT_EQ(q.getNumerator(), 0);
	EXPECT_EQ(q.getDenominator(), 1);
}

TEST(Rational, constructor_0_with_0) {
	EXPECT_THROW(Rational<int>(0, 0), std::invalid_argument);
}

TEST(Rational, constructor_3_with_0) {
	EXPECT_THROW(Rational<int>(3, 0), std::invalid_argument);
}

TEST(Rational, constructor_minus_3_with_0) {
	EXPECT_THROW(Rational<int>(-3, 0), std::invalid_argument);
}


TEST(Rational, addition_5_6_with_11_3) {
	Rational<int> q1(5, 6);
	Rational<int> q2(11, 3);
	EXPECT_EQ(q1 + q2, Rational<int>(9, 2));
}

TEST(Rational, addition_5_6_with_11_3_properties) {
	Rational<int> q1(5, 6);
	Rational<int> q2(11, 3);
	Rational<int> q3 = q1 + q2;
	EXPECT_EQ(q3.getNumerator(), 9);
	EXPECT_EQ(q3.getDenominator(), 2);
}

TEST(Rational, addition_7_10_with_minus_1_30) {
	Rational<int> q1(7, 10);
	Rational<int> q2(-1, 30);
	EXPECT_EQ(q1 + q2, Rational<int>(2, 3));
}

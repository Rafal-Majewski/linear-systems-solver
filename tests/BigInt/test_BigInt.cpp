#include <gtest/gtest.h>
#include <BigInt/BigInt.h>


TEST(BigInt, toString_0) {
	BigInt bigint(0);
	EXPECT_EQ("0", std::string(bigint));
}

TEST(BigInt, toString_123) {
	BigInt bigint(123);
	EXPECT_EQ("123", std::string(bigint));
}

TEST(BigInt, toString_minus_5) {
	BigInt bigint(-5);
	EXPECT_EQ("-5", std::string(bigint));
}

TEST(BigInt, addition_0_with_0) {
	BigInt bigint1(0);
	BigInt bigint2(0);
	EXPECT_EQ(BigInt(0), bigint1 + bigint2);
}

TEST(BigInt, addition_2_with_5) {
	BigInt bigint1(2);
	BigInt bigint2(5);
	EXPECT_EQ(BigInt(7), bigint1 + bigint2);
}

TEST(BigInt, addition_minus_2_with_5) {
	BigInt bigint1(-2);
	BigInt bigint2(5);
	EXPECT_EQ(BigInt(3), bigint1 + bigint2);
}

TEST(BigInt, addition_42343_with_222) {
	BigInt bigint1(42343);
	BigInt bigint2(222);
	EXPECT_EQ(BigInt(42565), bigint1 + bigint2);
}

TEST(BigInt, addition_233_with_minus_333125) {
	BigInt bigint1(233);
	BigInt bigint2(-333125);
	EXPECT_EQ(BigInt(-332892), bigint1 + bigint2);
}

TEST(BigInt, addition_0_with_minus_99) {
	BigInt bigint1(0);
	BigInt bigint2(-99);
	EXPECT_EQ(BigInt(-99), bigint1 + bigint2);
}

TEST(BigInt, addition_0_with_65) {
	BigInt bigint1(0);
	BigInt bigint2(65);
	EXPECT_EQ(BigInt(65), bigint1 + bigint2);
}

TEST(BigInt, multiplication_3_with_2) {
	BigInt bigint1(3);
	BigInt bigint2(2);
	EXPECT_EQ(BigInt(6), bigint1 * bigint2);
}

TEST(BigInt, multiplication_minus_23432_with_888) {
	BigInt bigint1(-23432);
	BigInt bigint2(888);
	EXPECT_EQ(BigInt(-20807616), bigint1 * bigint2);
}

TEST(BigInt, division_100_with_103) {
	BigInt bigint1(100);
	BigInt bigint2(103);
	EXPECT_EQ(BigInt(0), bigint1 / bigint2);
}

TEST(BigInt, division_73_with_3) {
	BigInt bigint1(73);
	BigInt bigint2(3);
	EXPECT_EQ(BigInt(24), bigint1 / bigint2);
}

TEST(BigInt, division_6_with_3) {
	BigInt bigint1(6);
	BigInt bigint2(3);
	EXPECT_EQ(BigInt(2), bigint1 / bigint2);
}


TEST(BigInt, division_5_with_3) {
	BigInt bigint1(5);
	BigInt bigint2(3);
	EXPECT_EQ(BigInt(1), bigint1 / bigint2);
}


TEST(BigInt, division_4_with_3) {
	BigInt bigint1(4);
	BigInt bigint2(3);
	EXPECT_EQ(BigInt(1), bigint1 / bigint2);
}

TEST(BigInt, division_3_with_3) {
	BigInt bigint1(3);
	BigInt bigint2(3);
	EXPECT_EQ(BigInt(1), bigint1 / bigint2);
}

TEST(BigInt, division_2_with_3) {
	BigInt bigint1(2);
	BigInt bigint2(3);
	EXPECT_EQ(BigInt(0), bigint1 / bigint2);
}

TEST(BigInt, division_5_with_1) {
	BigInt bigint1(5);
	BigInt bigint2(1);
	EXPECT_EQ(BigInt(5), bigint1 / bigint2);
}

TEST(BigInt, division_100_with_20) {
	BigInt bigint1(100);
	BigInt bigint2(20);
	EXPECT_EQ(BigInt(5), bigint1 / bigint2);
}

TEST(BigInt, division_52_with_0) {
	BigInt bigint1(52);
	BigInt bigint2(0);
	EXPECT_THROW(bigint1 / bigint2, std::invalid_argument);
}

TEST(BigInt, division_0_with_0) {
	BigInt bigint1(0);
	BigInt bigint2(0);
	EXPECT_THROW(bigint1 / bigint2, std::invalid_argument);
}

TEST(BigInt, division_0_with_52) {
	BigInt bigint1(0);
	BigInt bigint2(52);
	EXPECT_EQ(BigInt(0), bigint1 / bigint2);
}


TEST(BigInt, division_12_with_4) {
	BigInt bigint1(12);
	BigInt bigint2(4);
	EXPECT_EQ(BigInt(3), bigint1 / bigint2);
}

TEST(BigInt, division_15_with_15) {
	BigInt bigint1(15);
	BigInt bigint2(15);
	EXPECT_EQ(BigInt(1), bigint1 / bigint2);
}

TEST(BigInt, division_15_with_minus_3) {
	BigInt bigint1(15);
	BigInt bigint2(-3);
	EXPECT_EQ(BigInt(-5), bigint1 / bigint2);
}

TEST(BigInt, division_minus_42_with_minus_21) {
	BigInt bigint1(-42);
	BigInt bigint2(-21);
	EXPECT_EQ(BigInt(2), bigint1 / bigint2);
}


TEST(BigInt, division_minus_42_with_21) {
	BigInt bigint1(-42);
	BigInt bigint2(21);
	EXPECT_EQ(BigInt(-2), bigint1 / bigint2);
}

TEST(BigInt, division_minus_42_with_53) {
	BigInt bigint1(-42);
	BigInt bigint2(53);
	EXPECT_EQ(BigInt(0), bigint1 / bigint2);
}

TEST(BigInt, division_modulo_42_with_5) {
	BigInt bigint1(42);
	BigInt bigint2(5);
	EXPECT_EQ(BigInt(2), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_minus_42_with_5) {
	BigInt bigint1(-42);
	BigInt bigint2(5);
	EXPECT_EQ(BigInt(3), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_minus_4_with_3) {
	BigInt bigint1(-4);
	BigInt bigint2(3);
	EXPECT_EQ(BigInt(2), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_minus_3_with_3) {
	BigInt bigint1(-3);
	BigInt bigint2(3);
	EXPECT_EQ(BigInt(0), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_minus_2_with_3) {
	BigInt bigint1(-2);
	BigInt bigint2(3);
	EXPECT_EQ(BigInt(1), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_minus_1_with_3) {
	BigInt bigint1(-1);
	BigInt bigint2(3);
	EXPECT_EQ(BigInt(2), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_minus_0_with_3) {
	BigInt bigint1(0);
	BigInt bigint2(3);
	EXPECT_EQ(BigInt(0), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_1_with_3) {
	BigInt bigint1(1);
	BigInt bigint2(3);
	EXPECT_EQ(BigInt(1), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_2_with_3) {
	BigInt bigint1(2);
	BigInt bigint2(3);
	EXPECT_EQ(BigInt(2), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_3_with_3) {
	BigInt bigint1(3);
	BigInt bigint2(3);
	EXPECT_EQ(BigInt(0), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_4_with_3) {
	BigInt bigint1(4);
	BigInt bigint2(3);
	EXPECT_EQ(BigInt(1), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_3_with_1) {
	BigInt bigint1(3);
	BigInt bigint2(1);
	EXPECT_EQ(BigInt(0), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_1_with_1) {
	BigInt bigint1(1);
	BigInt bigint2(1);
	EXPECT_EQ(BigInt(0), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_0_with_1) {
	BigInt bigint1(0);
	BigInt bigint2(1);
	EXPECT_EQ(BigInt(0), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_5_with_1) {
	BigInt bigint1(5);
	BigInt bigint2(1);
	EXPECT_EQ(BigInt(0), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_minus_5_with_1) {
	BigInt bigint1(-5);
	BigInt bigint2(1);
	EXPECT_EQ(BigInt(0), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_minus_5_with_0) {
	BigInt bigint1(-5);
	BigInt bigint2(0);
	EXPECT_THROW(bigint1 % bigint2, std::invalid_argument);
}

TEST(BigInt, division_modulo_0_with_0) {
	BigInt bigint1(0);
	BigInt bigint2(0);
	EXPECT_THROW(bigint1 % bigint2, std::invalid_argument);
}

TEST(BigInt, division_modulo_3_with_0) {
	BigInt bigint1(3);
	BigInt bigint2(0);
	EXPECT_THROW(bigint1 % bigint2, std::invalid_argument);
}

TEST(BigInt, division_modulo_minus_3_with_2) {
	BigInt bigint1(-3);
	BigInt bigint2(2);
	EXPECT_EQ(BigInt(1), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_minus_2_with_2) {
	BigInt bigint1(-2);
	BigInt bigint2(2);
	EXPECT_EQ(BigInt(0), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_minus_1_with_2) {
	BigInt bigint1(-1);
	BigInt bigint2(2);
	EXPECT_EQ(BigInt(1), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_0_with_2) {
	BigInt bigint1(0);
	BigInt bigint2(2);
	EXPECT_EQ(BigInt(0), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_1_with_2) {
	BigInt bigint1(1);
	BigInt bigint2(2);
	EXPECT_EQ(BigInt(1), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_2_with_2) {
	BigInt bigint1(2);
	BigInt bigint2(2);
	EXPECT_EQ(BigInt(0), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_minus_7_with_minus_22) {
	BigInt bigint1(-6);
	BigInt bigint2(-22);
	EXPECT_EQ(BigInt(-6), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_minus_23_with_minus_22) {
	BigInt bigint1(-23);
	BigInt bigint2(-22);
	EXPECT_EQ(BigInt(-1), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_minus_22_with_minus_22) {
	BigInt bigint1(-22);
	BigInt bigint2(-22);
	EXPECT_EQ(BigInt(0), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_minus_1_with_minus_22) {
	BigInt bigint1(-1);
	BigInt bigint2(-22);
	EXPECT_EQ(BigInt(-1), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_minus_5_with_minus_1) {
	BigInt bigint1(-5);
	BigInt bigint2(-1);
	EXPECT_EQ(BigInt(0), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_minus_5_with_minus_2) {
	BigInt bigint1(-5);
	BigInt bigint2(-2);
	EXPECT_EQ(BigInt(-1), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_minus_2_with_minus_2) {
	BigInt bigint1(-2);
	BigInt bigint2(-2);
	EXPECT_EQ(BigInt(0), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_minus_3_with_minus_2) {
	BigInt bigint1(-3);
	BigInt bigint2(-2);
	EXPECT_EQ(BigInt(-1), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_minus_1_with_minus_2) {
	BigInt bigint1(-1);
	BigInt bigint2(-2);
	EXPECT_EQ(BigInt(-1), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_minus_13_with_minus_3) {
	BigInt bigint1(-13);
	BigInt bigint2(-3);
	EXPECT_EQ(BigInt(-1), bigint1 % bigint2);
}

TEST(BigInt, really_big_number) {
	BigInt bigint1(353243223);
	BigInt bigint2(234322423);
	EXPECT_EQ(std::string(bigint1 * bigint2), "82772807921689329");
}

TEST(BigInt, division_modulo_1_with_minus_3) {
	BigInt bigint1(1);
	BigInt bigint2(-3);
	EXPECT_EQ(BigInt(-2), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_2_with_minus_3) {
	BigInt bigint1(2);
	BigInt bigint2(-3);
	EXPECT_EQ(BigInt(-1), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_3_with_minus_3) {
	BigInt bigint1(3);
	BigInt bigint2(3);
	EXPECT_EQ(BigInt(0), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_4_with_minus_3) {
	BigInt bigint1(4);
	BigInt bigint2(-3);
	EXPECT_EQ(BigInt(-2), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_3_with_minus_1) {
	BigInt bigint1(3);
	BigInt bigint2(1);
	EXPECT_EQ(BigInt(0), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_1_with_minus_1) {
	BigInt bigint1(1);
	BigInt bigint2(-1);
	EXPECT_EQ(BigInt(0), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_0_with_minus_1) {
	BigInt bigint1(0);
	BigInt bigint2(-1);
	EXPECT_EQ(BigInt(0), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_5_with_minus_1) {
	BigInt bigint1(5);
	BigInt bigint2(-1);
	EXPECT_EQ(BigInt(0), bigint1 % bigint2);
}


TEST(BigInt, division_modulo_3_with_minus_2) {
	BigInt bigint1(3);
	BigInt bigint2(-2);
	EXPECT_EQ(BigInt(-1), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_2_with_minus_2) {
	BigInt bigint1(2);
	BigInt bigint2(-2);
	EXPECT_EQ(BigInt(0), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_1_with_minus_2) {
	BigInt bigint1(1);
	BigInt bigint2(-2);
	EXPECT_EQ(BigInt(-1), bigint1 % bigint2);
}

TEST(BigInt, division_modulo_0_with_minus_2) {
	BigInt bigint1(0);
	BigInt bigint2(-2);
	EXPECT_EQ(BigInt(0), bigint1 % bigint2);
}
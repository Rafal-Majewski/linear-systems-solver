#ifndef BIG_INT_DIGITS_H_INCLUDED
#define BIG_INT_DIGITS_H_INCLUDED

#include <vector>
#include <iostream>


class BigIntDigits {
	private:
	static std::vector<char> addDecimalDigits(
		std::vector<char> digits1,
		std::vector<char> digits2
	);
	static std::vector<char> stringToDecimalDigits(std::string str);
	std::vector<char> digits;
	void addOnPosition(const BigIntDigits& other, int pos);
	void preventPositiveOverflow(int pos);
	void preventNegativeOverflow(int pos);
	BigIntDigits(std::vector<char> digits);

	public:
	static BigIntDigits fromString(std::string str);
	BigIntDigits();
	BigIntDigits(unsigned int num);
	char get(int pos) const;
	void set(int pos, char digit);
	void incrementDigit(int pos);
	void decrementDigit(int pos);
	int size() const;
	BigIntDigits operator+(const BigIntDigits& other) const;
	BigIntDigits operator-(const BigIntDigits& other) const;
	BigIntDigits operator*(const BigIntDigits& other) const;
	BigIntDigits operator/(const BigIntDigits& other) const;
	BigIntDigits operator%(const BigIntDigits& other) const;
	BigIntDigits& operator+=(BigIntDigits other);
	BigIntDigits& operator-=(BigIntDigits other);
	BigIntDigits& operator*=(BigIntDigits other);
	BigIntDigits& operator/=(BigIntDigits other);
	BigIntDigits& operator%=(BigIntDigits other);
	bool operator==(const BigIntDigits& other) const;
	bool operator!=(const BigIntDigits& other) const;
	bool operator<(const BigIntDigits& other) const;
	bool operator>(const BigIntDigits& other) const;
	bool operator<=(const BigIntDigits& other) const;
	bool operator>=(const BigIntDigits& other) const;
	BigIntDigits& operator++();
	BigIntDigits operator++(int);
	BigIntDigits& operator--();
	BigIntDigits operator--(int);
	BigIntDigits operator>>(int shift) const;
	BigIntDigits operator<<(int shift) const;
	BigIntDigits& operator>>=(int shift);
	BigIntDigits& operator<<=(int shift);
	char compare(const BigIntDigits& other) const;
	std::pair<BigIntDigits, BigIntDigits> divideWithRemainder(const BigIntDigits& divisor) const;
	explicit operator std::string() const;
	explicit operator double() const;
};

std::ostream& operator<<(std::ostream& os, const BigIntDigits& bigintdigits);

#endif

#ifndef BIG_INT_DIGITS_H_INCLUDED
#define BIG_INT_DIGITS_H_INCLUDED

#include <vector>
#include <sstream>


class BigIntDigits {
	private:
	std::vector<char> addDecimalDigits(
		std::vector<char> digits1,
		std::vector<char> digits2
	) const;
	std::vector<char> digits;
	void addOnPosition(const BigIntDigits& other, int pos);
	public:
	char get(int pos) const;
	void set(int pos, char digit);
	void incrementDigit(int pos);
	void decrementDigit(int pos);
	int size() const;
	void pushMostImportant(char digit);
// 	BigIntDigits();
// 	BigIntDigits(const BigIntDigits&);
	friend BigIntDigits operator+(const BigIntDigits& lhs, const BigIntDigits& rhs);
// 	friend BigIntDigits operator-(const BigIntDigits& lhs, const BigIntDigits& rhs);
	friend BigIntDigits operator*(const BigIntDigits& lhs, const BigIntDigits& rhs);
	friend BigIntDigits operator/(const BigIntDigits& lhs, const BigIntDigits& rhs);
	friend BigIntDigits operator%(const BigIntDigits& lhs, const BigIntDigits& rhs);
// 	friend BigIntDigits operator<<(const BigIntDigits& lhs, int rhs);
// 	friend BigIntDigits operator>>(const BigIntDigits& lhs, int rhs);
	friend bool operator==(const BigIntDigits& lhs, const BigIntDigits& rhs);
	friend bool operator!=(const BigIntDigits& lhs, const BigIntDigits& rhs);
// 	friend bool operator<(const BigIntDigits& lhs, const BigIntDigits& rhs);
// 	friend bool operator>(const BigIntDigits& lhs, const BigIntDigits& rhs);
	friend bool operator<=(const BigIntDigits& lhs, const BigIntDigits& rhs);
	friend bool operator>=(const BigIntDigits& lhs, const BigIntDigits& rhs);
	BigIntDigits& operator+=(const BigIntDigits);
	BigIntDigits& operator-=(const BigIntDigits);
	BigIntDigits& operator*=(const BigIntDigits);
	BigIntDigits& operator/=(const BigIntDigits);
	BigIntDigits& operator%=(const BigIntDigits);
	BigIntDigits& operator<<=(int pos);
	BigIntDigits& operator>>=(int pos);
	char compare(const BigIntDigits&) const;
	void zero();
	// char operator[](int pos) const;
	std::pair<BigIntDigits, BigIntDigits> divideWithRemainder(const BigIntDigits& divisor) const;
	operator std::string() const;
	friend std::ostream& operator<<(std::ostream& os, const BigIntDigits& bigintdigits);
};

#endif

#ifndef BIG_INT_H_INCLUDED
#define BIG_INT_H_INCLUDED

#include <vector>
#include "./BigIntDigits/BigIntDigits.h"
#include <sstream>


struct BigInt {
	private:
	char sign;
		// -1 for negative
		// 1 for positive
		// 0 for no sign (zero)
	BigIntDigits digits;
	public:
	BigInt(int number);
	BigInt(const BigInt& other);
	operator std::string() const;
	friend std::ostream& operator<<(std::ostream& os, const BigInt& bigint);
	friend BigInt operator+(const BigInt& bigint1, const BigInt& bigint2);
	friend BigInt operator-(const BigInt& bigint1, const BigInt& bigint2);
	friend BigInt operator*(const BigInt& bigint1, const BigInt& bigint2);
	friend BigInt operator/(const BigInt& bigint1, const BigInt& bigint2);
	BigInt& operator+=(const BigInt bigint);
	BigInt& operator-=(const BigInt bigint);
	BigInt& operator*=(const BigInt bigint);
	BigInt& operator/=(const BigInt bigint);
	BigInt& operator%=(const BigInt bigint);
	friend bool operator==(const BigInt& bigint1, const BigInt& bigint2);
	friend bool operator!=(const BigInt& bigint1, const BigInt& bigint2);
	friend BigInt operator%(const BigInt& bigint1, const BigInt& bigint2);
	// friend bool operator<(const BigInt& bigint1, const BigInt& bigint2);
	// friend bool operator>(const BigInt& bigint1, const BigInt& bigint2);
	// friend bool operator<=(const BigInt& bigint1, const BigInt& bigint2);
	friend bool operator>=(const BigInt& bigint1, const BigInt& bigint2);
	// BigInt& operator++();
	// BigInt& operator--();
	// BigInt operator++(int count);
	// BigInt operator--(int count);
};

#endif

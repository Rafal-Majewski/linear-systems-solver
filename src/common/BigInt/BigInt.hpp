#ifndef BIG_INT_H_INCLUDED
#define BIG_INT_H_INCLUDED

#include <vector>
#include "./BigIntDigits/BigIntDigits.hpp"
#include <sstream>


struct BigInt {
	private:
	char sign;
		// -1 for negative
		// 1 for positive
		// 0 for no sign (zero)
	BigIntDigits digits;
	public:
	BigInt& operator>>=(int shift);
	BigInt& operator<<=(int shift);
	BigInt operator>>(int shift) const;
	BigInt operator<<(int shift) const;
	BigInt();
	BigInt(int number);
	BigInt(const BigInt& other);
	BigInt(std::string str);
	operator std::string() const;
	BigInt operator+(const BigInt& other) const;
	BigInt operator-(const BigInt& other) const;
	BigInt operator*(const BigInt& other) const;
	BigInt operator/(const BigInt& other) const;
	BigInt operator%(const BigInt& other) const;
	bool operator==(const BigInt& other) const;
	bool operator!=(const BigInt& other) const;
	bool operator<(const BigInt& other) const;
	bool operator>(const BigInt& other) const;
	bool operator<=(const BigInt& other) const;
	bool operator>=(const BigInt& other) const;
	BigInt& operator+=(const BigInt bigint);
	BigInt& operator-=(const BigInt bigint);
	BigInt& operator*=(const BigInt bigint);
	BigInt& operator/=(const BigInt bigint);
	BigInt& operator%=(const BigInt bigint);
	BigInt& operator++();
	BigInt operator++(int);
	BigInt& operator--();
	BigInt operator--(int);
	BigInt operator-() const;
	BigInt operator+() const;
	char compare(const BigInt& other) const;
	BigInt gcd(const BigInt& bigint) const;
};

std::ostream& operator<<(std::ostream& os, const BigInt& bigint);

#endif

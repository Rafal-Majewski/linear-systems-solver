#include "./BigInt.hpp"


BigInt::BigInt() {
	sign = 0;
}

BigInt::BigInt(int a_number) {
	if (a_number == 0) {
		sign = 0;
		return;
	}
	int number = a_number;
	if (number < 0) {
		sign = -1;
		number = -number;
	} else {
		sign = 1;
	}
	digits = BigIntDigits(number);
}

BigInt::BigInt(const BigInt& other) {
	sign = other.sign;
	digits = other.digits;
}

BigInt::operator std::string() const {
	return (sign == -1 ? "-" : "") + std::string(digits);
}

// BigInt::BigInt(std::string a_str) {
// 	if (a_str == "0" || a_str == "-0") {
// 		sign = 0;
// 		return;
// 	}
// 	std::string str = a_str;
// 	if (str[0] == '-') {
// 		sign = -1;
// 		str = str.substr(1);
// 	} else {
// 		sign = 1;
// 	}
// 	digits = BigIntDigits(str);
// }

BigInt BigInt::operator+(const BigInt& other) const {
	BigInt result(*this);
	result += other;
	return result;
}

bool BigInt::operator>=(const BigInt& other) const {
	return compare(other) >= 0;
}

bool BigInt::operator<=(const BigInt& other) const {
	return compare(other) <= 0;
}

bool BigInt::operator>(const BigInt& other) const {
	return compare(other) > 0;
}

bool BigInt::operator<(const BigInt& other) const {
	return compare(other) < 0;
}

bool BigInt::operator==(const BigInt& other) const {
	return compare(other) == 0;
}

bool BigInt::operator!=(const BigInt& other) const {
	return compare(other) != 0;
}



BigInt& BigInt::operator+=(const BigInt other) {
	if (sign == 0) {
		sign = other.sign;
		digits = other.digits;
		return *this;
	}
	if (other.sign == 0) {
		return *this;
	}
	if (sign == other.sign) {
		digits += other.digits;
		return *this;
	}
	char digitsComparisonResult = digits.compare(other.digits);
	if (digitsComparisonResult == 0) {
		sign = 0;
		digits = 0;
		return *this;
	}
	sign *= digitsComparisonResult;
	digits -= other.digits;
	return *this;

}

BigInt& BigInt::operator>>=(int shift) {
	digits >>= shift;
	if (digits.size() == 0) {
		sign = 0;
	}
	return *this;
}

BigInt& BigInt::operator<<=(int shift) {
	digits <<= shift;
	return *this;
}

BigInt BigInt::operator>>(int shift) const {
	BigInt result(*this);
	result >>= shift;
	return result;
}

BigInt BigInt::operator<<(int shift) const {
	BigInt result(*this);
	result <<= shift;
	return result;
}

BigInt& BigInt::operator-=(const BigInt other) {
	if (other.sign == 0) {
		return *this;
	}
	if (sign == 0) {
		sign = -other.sign;
		digits = other.digits;
		return *this;
	}
	if (sign != other.sign) {
		digits += other.digits;
		return *this;
	}
	char digitsComparisonResult = digits.compare(other.digits);
	if (digitsComparisonResult == 0) {
		sign = 0;
		digits = 0;
		return *this;
	}
	sign *= digitsComparisonResult;
	digits -= other.digits;
	return *this;
}

BigInt& BigInt::operator*=(const BigInt other) {
	if (sign == 0 || other.sign == 0) {
		sign = 0;
		digits = 0;
		return *this;
	}
	sign *= other.sign;
	digits *= other.digits;
	return *this;
}

BigInt& BigInt::operator/=(const BigInt other) {
	digits /= other.digits;
	sign *= bool(digits.size()) * other.sign;
	return *this;
}

BigInt& BigInt::operator%=(const BigInt other) {
	digits %= other.digits;

	if (digits.size() == 0) {
		sign = 0;
		return *this;
	}
	if (sign == -other.sign) {
		digits -= other.digits;
		sign = other.sign;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const BigInt& bigint) {
	os << std::string(bigint);
	return os;
}

BigInt BigInt::operator-(const BigInt& other) const {
	BigInt result(*this);
	result -= other;
	return result;
}

BigInt BigInt::operator*(const BigInt& other) const {
	BigInt result(*this);
	result *= other;
	return result;
}

BigInt BigInt::operator/(const BigInt& other) const {
	BigInt result(*this);
	result /= other;
	return result;
}

BigInt BigInt::operator%(const BigInt& other) const {
	BigInt result(*this);
	result %= other;
	return result;
}


BigInt BigInt::operator-() const {
	BigInt result(*this);
	result.sign *= -1;
	return result;
}

BigInt::BigInt(std::string str) {
	if (str[0] == '-') {
		sign = -1;
	} else {
		sign = 1;
	}
	digits = BigIntDigits(
		str.substr(str[0] == '-' ? 1 : 0)
	);
	if (digits.size() == 0) {
		sign = 0;
	}
}


BigInt BigInt::gcd(const BigInt& other) const {
	BigInt a(*this);
	BigInt b(other);
	while (b.sign != 0) {
		BigInt temp(b);
		b = a % b;
		a = temp;
	}
	return a;
}

char BigInt::compare(const BigInt& other) const {
	if (sign == 0) return -other.sign;
	if (sign != other.sign) return sign;
	char digitsComparisonResult = digits.compare(other.digits);
	return sign * digitsComparisonResult;
}

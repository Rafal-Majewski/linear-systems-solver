#include "./BigInt.h"
#include <algorithm>
#include "./utils/digitsOperations.h"


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
	while (number > 0) {
		digits.push_back(number & 1);
		number >>= 1;
	}
}

BigInt::BigInt(const BigInt& other) {
	sign = other.sign;
	digits = other.digits;
}

BigInt::operator std::string() const {
	std::vector<char> digitsDecimal;
	std::vector<char> digitsMultiplier = { 1 };
	for (int i = 0; i < digits.size(); ++i) {
		if (digits[i] == 1) {
			digitsDecimal = addDigits(digitsDecimal, digitsMultiplier, 10);
		}
		digitsMultiplier = addDigits(digitsMultiplier, digitsMultiplier, 10);
	}
	if (digitsDecimal.size() == 0) {
		digitsDecimal.push_back(0);
	}
	for (int i = 0; i < digitsDecimal.size(); ++i) {
		digitsDecimal[i] += '0';
	}
	if (sign == -1) {
		digitsDecimal.push_back('-');
	}
	std::reverse(digitsDecimal.begin(), digitsDecimal.end());
	std::string result(digitsDecimal.begin(), digitsDecimal.end());
	return result;
}

BigInt operator+(const BigInt& bigint1, const BigInt& bigint2) {
	BigInt result(bigint1);
	result += bigint2;
	return result;
}


BigInt& BigInt::operator+=(const BigInt& rhs) {
	if (sign == 0) {
		sign = rhs.sign;
		digits = rhs.digits;
		return *this;
	}
	if (rhs.sign == 0) {
		return *this;
	}
	if (sign == rhs.sign) {
		digits = addDigits(digits, rhs.digits, 2);
		return *this;
	}
	char digitsComparisonResult = compareDigits(digits, rhs.digits);
	if (digitsComparisonResult == 0) {
		sign = 0;
		digits.clear();
		return *this;
	}
	if (sign == 1 && digitsComparisonResult == 1) {
		sign = 1;
		digits = substractDigits(digits, rhs.digits, 2);
		return *this;
	}
	if (sign == -1 && digitsComparisonResult == -1) {
		sign = 1;
		digits = substractDigits(rhs.digits, digits, 2);
		return *this;
	}
	if (sign == 1 && digitsComparisonResult == -1) {
		sign = -1;
		digits = substractDigits(rhs.digits, digits, 2);
		return *this;
	}
	// if (sign == -1 && digitsComparisonResult == 1) {
		sign = -1;
		digits = substractDigits(digits, rhs.digits, 2);
		return *this;
	// }
}

BigInt& BigInt::operator-=(const BigInt& rhs) {
	if (sign == 0) {
		sign = -rhs.sign;
		digits = rhs.digits;
		return *this;
	}
	if (rhs.sign == 0) {
		return *this;
	}
	if (sign == rhs.sign) {
		if (compareDigits(digits, rhs.digits) == 1) {
			sign = 1;
			digits = substractDigits(digits, rhs.digits, 2);
			return *this;
		}
		sign = -1;
		digits = substractDigits(rhs.digits, digits, 2);
		return *this;
	}
	if (sign == 1 && compareDigits(digits, rhs.digits) == 1) {
		sign = -1;
		digits = substractDigits(rhs.digits, digits, 2);
		return *this;
	}
	if (sign == -1 && compareDigits(digits, rhs.digits) == -1) {
		sign = 1;
		digits = substractDigits(digits, rhs.digits, 2);
		return *this;
	}
	if (sign == 1 && compareDigits(digits, rhs.digits) == -1) {
		sign = -1;
		digits = substractDigits(digits, rhs.digits, 2);
		return *this;
	}
	// if (sign == -1 && compareDigits(digits, rhs.digits) == 1) {
		sign = 1;
		digits = substractDigits(rhs.digits, digits, 2);
		return *this;
	// }
}

BigInt& BigInt::operator*=(const BigInt& rhs) {
	if (sign == 0 || rhs.sign == 0) {
		sign = 0;
		digits.clear();
		return *this;
	}
	if (sign == rhs.sign) {
		sign = 1;
	} else {
		sign = -1;
	}
	digits = multiplyDigits(digits, rhs.digits, 2);
	return *this;
}

BigInt& BigInt::operator/=(const BigInt& rhs) {
	digits = divideDigitsBinary(digits, rhs.digits).first;
	if (digits.size() == 0) {
		sign = 0;
	} else {
		sign *= rhs.sign;
	}
	return *this;
}

BigInt& BigInt::operator%=(const BigInt& rhs) {
	digits = divideDigitsBinary(digits, rhs.digits).second;
	if (digits.size() == 0) {
		sign = 0;
		return *this;
	}
	if (sign == -rhs.sign) {
		digits = substractDigits(rhs.digits, digits, 2);
		sign = rhs.sign;
	}
	return *this;
}

bool operator==(const BigInt& bigint1, const BigInt& bigint2) {
	if (bigint1.sign != bigint2.sign) {
		return false;
	}
	if (bigint1.digits.size() != bigint2.digits.size()) {
		return false;
	}
	for (int i = 0; i < bigint1.digits.size(); ++i) {
		if (bigint1.digits[i] != bigint2.digits[i]) {
			return false;
		}
	}
	return true;
}

bool operator!=(const BigInt& bigint1, const BigInt& bigint2) {
	if (bigint1.sign != bigint2.sign) {
		return true;
	}
	if (bigint1.digits.size() != bigint2.digits.size()) {
		return true;
	}
	for (int i = 0; i < bigint1.digits.size(); ++i) {
		if (bigint1.digits[i] != bigint2.digits[i]) {
			return true;
		}
	}
	return false;
}

// std::ostream& operator<<(std::ostream& os, const BigInt& bigint) {
// 	os << bigint.toString();
// 	return os;
// }

BigInt operator-(const BigInt& bigint1, const BigInt& bigint2) {
	BigInt result(bigint1);
	result -= bigint2;
	return result;
}

BigInt operator*(const BigInt& bigint1, const BigInt& bigint2) {
	BigInt result(bigint1);
	result *= bigint2;
	return result;
}

BigInt operator/(const BigInt& bigint1, const BigInt& bigint2) {
	BigInt result(bigint1);
	result /= bigint2;
	return result;
}

BigInt operator%(const BigInt& bigint1, const BigInt& bigint2) {
	BigInt result(bigint1);
	result %= bigint2;
	return result;
}

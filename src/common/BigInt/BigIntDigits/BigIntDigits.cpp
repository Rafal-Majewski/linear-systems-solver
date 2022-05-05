#include "./BigIntDigits.h"
#include <stdexcept>
#include <algorithm>

int BigIntDigits::size() const {
	return digits.size();
}

std::ostream& operator<<(std::ostream& os, const BigIntDigits& bigintdigits) {
	os << std::string(bigintdigits);
	return os;
}

// char BigIntDigits::getDigit(int pos) const {
// 	if (pos >= digits.size()) {
// 		return 0;
// 	}
// 	return digits[pos];
// }

void BigIntDigits::incrementDigit(int pos) {
	while (pos >= digits.size()) {
		digits.push_back(0);
	}
	++digits[pos];
	int i = pos;
	while(digits[i] == 2) {
		digits[i] = 0;
		if (i + 1 == digits.size()) {
			digits.push_back(0);
		}
		++digits[i + 1];
		++i;
	}
	// for (int i = pos; digits[i] == 2; --i) {
	// 	digits[i] = 0;
	// 	if (i + 1 == digits.size()) {
	// 		digits.push_back(0);
	// 	}
	// 	++digits[i + 1];
	// }
}

void BigIntDigits::decrementDigit(int pos) {
	--digits[pos];
	int i = pos;
	while (digits[i] == -1) {
		digits[i] = 1;
		--digits[i + 1];
		++i;
		// --digits[++i];
	}
	if (digits.back() == 0) {
		digits.pop_back();
	}
}


void BigIntDigits::pushMostImportant(char digit) {
	digits.push_back(digit);
}

// BigIntDigits::BigIntDigits(const BigIntDigits& other) {
// 	digits = other.digits;
// }

BigIntDigits operator+(const BigIntDigits& lhs, const BigIntDigits& rhs) {
	BigIntDigits result(lhs);
	result += rhs;
	return result;
}

// BigIntDigits operator-(const BigIntDigits& lhs, const BigIntDigits& rhs) {
// 	BigIntDigits result(lhs);
// 	result -= rhs;
// 	return result;
// }

BigIntDigits operator*(const BigIntDigits& lhs, const BigIntDigits& rhs) {
	BigIntDigits result(lhs);
	result *= rhs;
	return result;
}

BigIntDigits operator/(const BigIntDigits& lhs, const BigIntDigits& rhs) {
	BigIntDigits result(lhs);
	result /= rhs;
	return result;
}

BigIntDigits operator%(const BigIntDigits& lhs, const BigIntDigits& rhs) {
	BigIntDigits result(lhs);
	result %= rhs;
	return result;
}

BigIntDigits operator<<(const BigIntDigits& lhs, int rhs) {
	BigIntDigits result(lhs);
	result <<= rhs;
	return result;
}

BigIntDigits operator>>(const BigIntDigits& lhs, int rhs) {
	BigIntDigits result(lhs);
	result >>= rhs;
	return result;
}

bool operator==(const BigIntDigits& lhs, const BigIntDigits& rhs) {
	for (int i = 0; i < lhs.digits.size(); ++i) {
		if (lhs.digits[i] != rhs.digits[i]) {
			return false;
		}
	}
	return true;
}

bool operator!=(const BigIntDigits& lhs, const BigIntDigits& rhs) {
	for (int i = 0; i < lhs.digits.size(); ++i) {
		if (lhs.digits[i] != rhs.digits[i]) {
			return true;
		}
	}
	return false;
}

// bool operator<(const BigIntDigits& lhs, const BigIntDigits& rhs) {
// 	if (lhs.digits.size() < rhs.digits.size()) {
// 		return true;
// 	}
// 	if (lhs.digits.size() > rhs.digits.size()) {
// 		return false;
// 	}
// 	for (int i = lhs.digits.size() - 1; i >= 0; --i) {
// 		if (lhs.digits[i] < rhs.digits[i]) {
// 			return true;
// 		}
// 		if (lhs.digits[i] > rhs.digits[i]) {
// 			return false;
// 		}
// 	}
// 	return false;
// }

// bool operator>(const BigIntDigits& lhs, const BigIntDigits& rhs) {
// 	if (lhs.digits.size() > rhs.digits.size()) {
// 		return true;
// 	}
// 	if (lhs.digits.size() < rhs.digits.size()) {
// 		return false;
// 	}
// 	for (int i = lhs.digits.size() - 1; i >= 0; --i) {
// 		if (lhs.digits[i] > rhs.digits[i]) {
// 			return true;
// 		}
// 		if (lhs.digits[i] < rhs.digits[i]) {
// 			return false;
// 		}
// 	}
// 	return false;
// }

// bool operator<=(const BigIntDigits& lhs, const BigIntDigits& rhs) {
// 	if (lhs.digits.size() < rhs.digits.size()) {
// 		return true;
// 	}
// 	if (lhs.digits.size() > rhs.digits.size()) {
// 		return false;
// 	}
// 	for (int i = lhs.digits.size() - 1; i >= 0; --i) {
// 		if (lhs.digits[i] < rhs.digits[i]) {
// 			return true;
// 		}
// 		if (lhs.digits[i] > rhs.digits[i]) {
// 			return false;
// 		}
// 	}
// 	return true;
// }

bool operator>=(const BigIntDigits& lhs, const BigIntDigits& rhs) {
	if (lhs.digits.size() > rhs.digits.size()) {
		return true;
	}
	if (lhs.digits.size() < rhs.digits.size()) {
		return false;
	}
	for (int i = lhs.digits.size() - 1; i >= 0; --i) {
		if (lhs.digits[i] > rhs.digits[i]) {
			return true;
		}
		if (lhs.digits[i] < rhs.digits[i]) {
			return false;
		}
	}
	return true;
}

bool operator>(const BigIntDigits& lhs, const BigIntDigits& rhs) {
	if (lhs.digits.size() > rhs.digits.size()) {
		return true;
	}
	if (lhs.digits.size() < rhs.digits.size()) {
		return false;
	}
	for (int i = lhs.digits.size() - 1; i >= 0; --i) {
		if (lhs.digits[i] > rhs.digits[i]) {
			return true;
		}
		if (lhs.digits[i] < rhs.digits[i]) {
			return false;
		}
	}
	return false;
}

bool operator<(const BigIntDigits& lhs, const BigIntDigits& rhs) {
	if (lhs.digits.size() < rhs.digits.size()) {
		return true;
	}
	if (lhs.digits.size() > rhs.digits.size()) {
		return false;
	}
	for (int i = lhs.digits.size() - 1; i >= 0; --i) {
		if (lhs.digits[i] < rhs.digits[i]) {
			return true;
		}
		if (lhs.digits[i] > rhs.digits[i]) {
			return false;
		}
	}
	return false;
}

bool operator<=(const BigIntDigits& lhs, const BigIntDigits& rhs) {
	if (lhs.digits.size() < rhs.digits.size()) {
		return true;
	}
	if (lhs.digits.size() > rhs.digits.size()) {
		return false;
	}
	for (int i = lhs.digits.size() - 1; i >= 0; --i) {
		if (lhs.digits[i] > rhs.digits[i]) {
			return false;
		}
		if (lhs.digits[i] < rhs.digits[i]) {
			return true;
		}
	}
	return true;
}


BigIntDigits& BigIntDigits::operator+=(const BigIntDigits rhs) {
	for (int i = 0; i < rhs.digits.size(); ++i) {
		if (rhs.digits[i] == 0) {
			continue;
		}
		incrementDigit(i);
	}
	return *this;
}

BigIntDigits& BigIntDigits::operator-=(const BigIntDigits rhs) {
	auto [bigger, smaller] = rhs.digits.size() > digits.size() ?
		std::make_pair(rhs.digits, digits)
		: std::make_pair(digits, rhs.digits);
	digits = bigger;
	for (int i = 0; i < smaller.size(); ++i) {
		if (smaller[i] == 0) {
			continue;
		}
		decrementDigit(i);
	}
	while (digits.size() > 0 && digits.back() == 0) {
		digits.pop_back();
	}
	return *this;
}

BigIntDigits& BigIntDigits::operator<<=(int rhs) {
	if (digits.size() > 0) for (int i = 0; i < rhs; ++i) {
		digits.insert(digits.begin(), 0);
	}
	return *this;
}

BigIntDigits& BigIntDigits::operator>>=(int rhs) {
	for (int i = 0; i < rhs; ++i) {
		digits.erase(digits.begin());
	}
	return *this;
}

// BigIntDigits& operator*=(const BigIntDigits&);

// std::vector<char> multiplyDigits(
// 	const std::vector<char>& digits1,
// 	const std::vector<char>& digits2,
// 	char base
// ) {
// 	std::vector<char> result;
// 	for (int i = 0; i < digits1.size(); ++i) {
// 		std::vector<char> temp;
// 		for (int j = 0; j < i; ++j) {
// 			temp.push_back(0);
// 		}
// 		for (int j = 0; j < digits2.size(); ++j) {
// 			changeValueInDigits(temp, base, i + j, digits1[i] * digits2[j]);
// 		}
// 		result = addDigits(result, temp, base);
// 	}
// 	return result;
// }


void BigIntDigits::addOnPosition(const BigIntDigits& other, int pos) {
	for (int i = 0; i < other.digits.size(); ++i) {
		if (other.digits[i] == 0) {
			continue;
		}
		incrementDigit(pos + i);
	}
}

BigIntDigits& BigIntDigits::operator*=(const BigIntDigits rhs) {
	BigIntDigits result;
	for (int i = 0; i < digits.size(); ++i) {
		if (digits[i] == 0) {
			continue;
		}
		result.addOnPosition(rhs, i);
	}
	digits = result.digits;
	return *this;
}

BigIntDigits& BigIntDigits::operator/=(const BigIntDigits rhs) {
	digits = divideWithRemainder(rhs).first.digits;
	return *this;
}

void BigIntDigits::set(int pos, char digit) {
	if (digit == 0 && pos >= digits.size()) {
		return;
	}
	while(digits.size() <= pos) {
		digits.push_back(0);
	}
	digits[pos] = digit;
}

char BigIntDigits::get(int pos) const {
	return digits[pos];
}
// BigIntDigits& operator%=(const BigIntDigits&);
// char compare(const BigIntDigits&) const;
// void zero();
// char BigIntDigits::operator[](int pos) const {
// 	return digits[pos];
// }
std::pair<BigIntDigits, BigIntDigits> BigIntDigits::divideWithRemainder(const BigIntDigits& divisor) const {
	if (divisor.size() == 0) {
		throw std::invalid_argument("Division by zero");
	}
	BigIntDigits Q;
	BigIntDigits R;
	for (int i = size() - 1; i >= 0; --i) {
		R <<= 1;
		R.set(0, get(i));
		if (R >= divisor) {
			R -= divisor;
			Q.set(i, 1);
		}
	}
	return std::make_pair(Q, R);
}


void BigIntDigits::zero() {
	digits.clear();
}

BigIntDigits& BigIntDigits::operator%=(const BigIntDigits rhs) {
	digits = divideWithRemainder(rhs).second.digits;
	return *this;
}



char BigIntDigits::compare(const BigIntDigits &rhs) const {
	if (digits.size() > rhs.digits.size()) {
		return 1;
	}
	if (digits.size() < rhs.digits.size()) {
		return -1;
	}
	for (int i = digits.size() - 1; i >= 0; --i) {
		if (digits[i] > rhs.digits[i]) {
			return 1;
		}
		if (digits[i] < rhs.digits[i]) {
			return -1;
		}
	}
	return 0;
}


std::vector<char> BigIntDigits::addDecimalDigits(
	std::vector<char> digits1,
	std::vector<char> digits2
) const {
	std::vector<char> result;
	for (int i = 0; i < std::max(digits1.size(), digits2.size()); ++i) {
		char toAdd = 0;
		if (i < digits1.size()) {
			toAdd += digits1[i];
		}
		if (i < digits2.size()) {
			toAdd += digits2[i];
		}
		if (i == result.size()) {
			result.push_back(0);
		}
		result[i] += toAdd;
		for (int j = i; result[j] >= 10; ++j) {
			result.push_back(result[j] / 10);
			result[j] %= 10;
		}
	}
	return result;
}


BigIntDigits::operator std::string() const {
	std::vector<char> digitsDecimal;
	std::vector<char> digitMultiplier = {1};
	for (int i = 0; i < digits.size(); ++i) {
		if (digits[i] == 1) {
			digitsDecimal = addDecimalDigits(digitsDecimal, digitMultiplier);
		}
		digitMultiplier = addDecimalDigits(digitMultiplier, digitMultiplier);
	}
	if (digitsDecimal.size() == 0) {
		digitsDecimal.push_back(0);
	}
	for (int i = 0; i < digitsDecimal.size(); ++i) {
		digitsDecimal[i] += '0';
	}
	std::reverse(digitsDecimal.begin(), digitsDecimal.end());
	std::string result(digitsDecimal.begin(), digitsDecimal.end());
	return result;
}

// void BigIntDigits::cleanupDigits(int pos) {
// 	for (int i = pos; i < digits.size(); i++) {
// 		if (digits[i] < 2) continue;
	
// 		if (i == digits.size() - 1) {
// 			digits.push_back(0);
// 		}
// 		++digits[i + 1];
// 		digits[i] %= 2;
// 	}
// }


// void cleanupDigits(
// 	std::vector<char>& digits,
// 	unsigned char base,
// 	unsigned int pos
// ) {
// 	for (unsigned int i = pos; i < digits.size(); ++i) {
// 		if (digits[i] >= base) {
// 			if (i == digits.size() - 1) {
// 				digits.push_back(0);
// 			}
// 			digits[i + 1] += digits[i] / base;
// 			digits[i] %= base;
// 		}
// 		while (digits[i] < 0) {
// 			digits[i] += base;
// 			digits[i + 1] -= 1;
// 		}
// 	}
// 	while (digits.size() > 0 && digits.back() == 0) {
// 		digits.pop_back();
// 	}
// }

// void changeValueInDigits(
// 	std::vector<char>& digits,
// 	char base,
// 	unsigned int pos,
// 	char value
// ) {
// 	while (pos >= digits.size()) {
// 		digits.push_back(0);
// 	}
	
// 	digits[pos] += value;
// 	cleanupDigits(digits, base, pos);
// }

// std::vector<char> addDigits(
// 	const std::vector<char>& digits1,
// 	const std::vector<char>& digits2,
// 	char base
// ) {
// 	std::vector<char> result;
// 	for (int i = 0; i < std::max(digits1.size(), digits2.size()); ++i) {
// 		if (i < digits1.size()) {
// 			changeValueInDigits(result, base, i, digits1[i]);
// 		}
// 		if (i < digits2.size()) {
// 			changeValueInDigits(result, base, i, digits2[i]);
// 		}
// 	}
// 	return result;
// }

// std::vector<char> substractDigits(
// 	const std::vector<char>& digits1,
// 	const std::vector<char>& digits2,
// 	char base
// ) {
// 	// assume digits1 >= digits2
// 	std::vector<char> result = digits1;
// 	for (int i = 0; i < digits2.size(); ++i) {
// 		changeValueInDigits(result, base, i, -digits2[i]);
// 	}
// 	return result;
// }


// char compareDigits(
// 	const std::vector<char>& digits1,
// 	const std::vector<char>& digits2
// ) {
// 	if (digits1.size() > digits2.size()) {
// 		return 1;
// 	} else if (digits1.size() < digits2.size()) {
// 		return -1;
// 	} else {
// 		for (int i = digits1.size() - 2; i >= 0; --i) {
// 			// -2 because we don't need to compare the last digit
// 			// it's always 1
// 			if (digits1[i] > digits2[i]) {
// 				return 1;
// 			} else if (digits1[i] < digits2[i]) {
// 				return -1;
// 			}
// 		}
// 		return 0;
// 	}
// }

// std::vector<char> rightShiftDigits(
// 	const std::vector<char>& digits,
// 	unsigned int shift
// ) {
// 	std::vector<char> result = digits;
// 	if (result.size() > 0) for (int i = 0; i < shift; ++i) {
// 		result.insert(result.begin(), 0);
// 	}
// 	return result;
// }

// std::vector<char> leftShiftDigits(
// 	const std::vector<char>& digits,
// 	unsigned int shift
// ) {
// 	std::vector<char> result = digits;
// 	result.erase(result.begin(), result.begin() + shift);
// 	return result;
// }

// std::pair<std::vector<char>, std::vector<char>> divideDigitsBinary(
// 	const std::vector<char>& digits1,
// 	const std::vector<char>& digits2
// ) {

// }


BigIntDigits::BigIntDigits(std::string str) {
	// todo	
}


BigIntDigits::BigIntDigits() {
	// todo
}

#include "./BigIntDigits.hpp"
#include <algorithm>

int BigIntDigits::size() const {
	return digits.size();
}

void BigIntDigits::preventPositiveOverflow(int pos) {
	for (int i = pos; digits[i] == 2; ++i) {
		digits[i] = 0;
		if (i + 1 == digits.size()) {
			digits.push_back(0);
		}
		++digits[i + 1];
	}
}

void BigIntDigits::preventNegativeOverflow(int pos) {
	for (int i = pos; digits[i] == -1; ++i) {
		digits[i] = 1;
		--digits[i + 1];
	}
	while (digits.size() > 0 && digits.back() == 0) {
		digits.pop_back();
	}
}

void BigIntDigits::incrementDigit(int pos) {
	while (pos >= digits.size()) {
		digits.push_back(0);
	}
	++digits[pos];
	preventPositiveOverflow(pos);
}

void BigIntDigits::decrementDigit(int pos) {
	--digits[pos];
	preventNegativeOverflow(pos);
}

BigIntDigits& BigIntDigits::operator+=(BigIntDigits rhs) {
	for (int i = 0; i < rhs.digits.size(); ++i) {
		if (rhs.digits[i] == 0) {
			continue;
		}
		incrementDigit(i);
	}
	return *this;
}

BigIntDigits& BigIntDigits::operator-=(BigIntDigits rhs) {
	auto [bigger, smaller] = rhs >= *this ?
		std::make_pair(rhs.digits, digits)
		: std::make_pair(digits, rhs.digits);
	digits = bigger;
	for (int i = 0; i < smaller.size(); ++i) {
		if (smaller[i] == 0) {
			continue;
		}
		decrementDigit(i);
	}
	return *this;
}

BigIntDigits& BigIntDigits::operator<<=(int shift) {
	if (digits.size() == 0) {
		return *this;
	}
	digits.insert(digits.begin(), shift, 0);
	return *this;
}

BigIntDigits& BigIntDigits::operator>>=(int shift) {
	for (int i = 0; digits.size() > 0 && i < shift; ++i) {
		digits.erase(digits.begin());
	}
	return *this;
}

void BigIntDigits::addOnPosition(const BigIntDigits& other, int pos) {
	for (int i = 0; i < other.digits.size(); ++i) {
		if (other.digits[i] == 0) {
			continue;
		}
		incrementDigit(pos + i);
	}
}

BigIntDigits& BigIntDigits::operator*=(const BigIntDigits other) {
	BigIntDigits result = 0;
	for (int i = 0; i < digits.size(); ++i) {
		if (digits[i] == 0) {
			continue;
		}
		result.addOnPosition(other, i);
	}
	digits = result.digits;
	return *this;
}

BigIntDigits& BigIntDigits::operator/=(const BigIntDigits other) {
	digits = divideWithRemainder(other).first.digits;
	return *this;
}

void BigIntDigits::set(int pos, char digit) {
	if (pos >= digits.size()) {
		if (digit == 0) return;
		while (pos > digits.size()) {
			digits.push_back(0);
		}
		digits.push_back(1);
		return;
	}
	digits[pos] = digit;
	if (digit == 0) while (digits.size() > 0 && digits.back() == 0) {
		digits.pop_back();
	}
}

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

BigIntDigits::operator std::string() const {
	std::vector<char> digitsDecimal;
	std::vector<char> digitMultiplier = {1};
	for (int i = 0; i < digits.size(); ++i) {
		if (digits[i] == 1) {
			digitsDecimal = BigIntDigits::addDecimalDigits(digitsDecimal, digitMultiplier);
		}
		digitMultiplier = BigIntDigits::addDecimalDigits(digitMultiplier, digitMultiplier);
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

std::vector<char> BigIntDigits::stringToDecimalDigits(std::string str) {
	std::vector<char> result;
	for (int i = str.size() - 1; i >= 0; --i) {
		result.push_back(str[i] - '0');
	}
	return result;
}

BigIntDigits::BigIntDigits(std::string str) {
	std::vector<char> decimalDigits = BigIntDigits::stringToDecimalDigits(str);
	BigIntDigits multiplier(1);
	for (int i = 0; i < decimalDigits.size(); ++i) {
		*this += multiplier * decimalDigits[i];
		multiplier *= 10;
	}
}

BigIntDigits::BigIntDigits() {
}

BigIntDigits::BigIntDigits(unsigned int number) {
	while (number > 0) {
		digits.push_back(number & 1);
		number >>= 1;
	}
}

std::vector<char> BigIntDigits::addDecimalDigits(
	std::vector<char> digits1,
	std::vector<char> digits2
) {
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

char BigIntDigits::get(int pos) const {
	if (pos >= digits.size()) {
		return 0;
	}
	return digits[pos];
}

BigIntDigits BigIntDigits::operator+(const BigIntDigits& other) const {
	BigIntDigits result(*this);
	result += other;
	return result;
}

BigIntDigits BigIntDigits::operator-(const BigIntDigits& other) const {
	BigIntDigits result(*this);
	result -= other;
	return result;
}

BigIntDigits BigIntDigits::operator*(const BigIntDigits& other) const {
	BigIntDigits result(*this);
	result *= other;
	return result;
}
BigIntDigits BigIntDigits::operator/(const BigIntDigits& other) const {
	BigIntDigits result(*this);
	result /= other;
	return result;
}
BigIntDigits BigIntDigits::operator%(const BigIntDigits& other) const {
	BigIntDigits result(*this);
	result %= other;
	return result;
}

bool BigIntDigits::operator==(const BigIntDigits& other) const {
	if (digits.size() != other.digits.size()) {
		return false;
	}
	for (int i = 0; i < digits.size(); ++i) {
		if (digits[i] != other.digits[i]) {
			return false;
		}
	}
	return true;
}

bool BigIntDigits::operator!=(const BigIntDigits& other) const {
	if (digits.size() != other.digits.size()) {
		return true;
	}
	for (int i = 0; i < digits.size(); ++i) {
		if (digits[i] != other.digits[i]) {
			return true;
		}
	}
	return false;
}

bool BigIntDigits::operator<(const BigIntDigits& other) const {
	if (digits.size() < other.digits.size()) {
		return true;
	}
	if (digits.size() > other.digits.size()) {
		return false;
	}
	for (int i = digits.size() - 1; i >= 0; --i) {
		if (digits[i] < other.digits[i]) {
			return true;
		}
		if (digits[i] > other.digits[i]) {
			return false;
		}
	}
	return false;
}

bool BigIntDigits::operator<=(const BigIntDigits& other) const {
	if (digits.size() < other.digits.size()) {
		return true;
	}
	if (digits.size() > other.digits.size()) {
		return false;
	}
	for (int i = digits.size() - 1; i >= 0; --i) {
		if (digits[i] < other.digits[i]) {
			return true;
		}
		if (digits[i] > other.digits[i]) {
			return false;
		}
	}
	return true;
}

bool BigIntDigits::operator>=(const BigIntDigits& other) const {
	if (digits.size() > other.digits.size()) {
		return true;
	}
	if (digits.size() < other.digits.size()) {
		return false;
	}
	for (int i = digits.size() - 1; i >= 0; --i) {
		if (digits[i] > other.digits[i]) {
			return true;
		}
		if (digits[i] < other.digits[i]) {
			return false;
		}
	}
	return true;
}

bool BigIntDigits::operator>(const BigIntDigits& other) const {
	if (digits.size() > other.digits.size()) {
		return true;
	}
	if (digits.size() < other.digits.size()) {
		return false;
	}
	for (int i = digits.size() - 1; i >= 0; --i) {
		if (digits[i] > other.digits[i]) {
			return true;
		}
		if (digits[i] < other.digits[i]) {
			return false;
		}
	}
	return false;
}

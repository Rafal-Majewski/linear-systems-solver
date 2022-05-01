#include "./digitsOperations.h"
#include <stdexcept>


void cleanupDigits(
	std::vector<char>& digits,
	unsigned char base,
	unsigned int pos
) {
	for (unsigned int i = pos; i < digits.size(); ++i) {
		if (digits[i] >= base) {
			if (i == digits.size() - 1) {
				digits.push_back(0);
			}
			digits[i + 1] += digits[i] / base;
			digits[i] %= base;
		}
		while (digits[i] < 0) {
			digits[i] += base;
			digits[i + 1] -= 1;
		}
	}
	while (digits.size() > 0 && digits.back() == 0) {
		digits.pop_back();
	}
}

void changeValueInDigits(
	std::vector<char>& digits,
	char base,
	unsigned int pos,
	char value
) {
	while (pos >= digits.size()) {
		digits.push_back(0);
	}
	
	digits[pos] += value;
	cleanupDigits(digits, base, pos);
}

std::vector<char> addDigits(
	const std::vector<char>& digits1,
	const std::vector<char>& digits2,
	char base
) {
	std::vector<char> result;
	for (int i = 0; i < std::max(digits1.size(), digits2.size()); ++i) {
		if (i < digits1.size()) {
			changeValueInDigits(result, base, i, digits1[i]);
		}
		if (i < digits2.size()) {
			changeValueInDigits(result, base, i, digits2[i]);
		}
	}
	return result;
}

std::vector<char> substractDigits(
	const std::vector<char>& digits1,
	const std::vector<char>& digits2,
	char base
) {
	// assume digits1 >= digits2
	std::vector<char> result = digits1;
	for (int i = 0; i < digits2.size(); ++i) {
		changeValueInDigits(result, base, i, -digits2[i]);
	}
	return result;
}


char compareDigits(
	const std::vector<char>& digits1,
	const std::vector<char>& digits2
) {
	if (digits1.size() > digits2.size()) {
		return 1;
	} else if (digits1.size() < digits2.size()) {
		return -1;
	} else {
		for (int i = digits1.size() - 2; i >= 0; --i) {
			// -2 because we don't need to compare the last digit
			// it's always 1
			if (digits1[i] > digits2[i]) {
				return 1;
			} else if (digits1[i] < digits2[i]) {
				return -1;
			}
		}
		return 0;
	}
}

std::vector<char> multiplyDigits(
	const std::vector<char>& digits1,
	const std::vector<char>& digits2,
	char base
) {
	std::vector<char> result;
	for (int i = 0; i < digits1.size(); ++i) {
		std::vector<char> temp;
		for (int j = 0; j < i; ++j) {
			temp.push_back(0);
		}
		for (int j = 0; j < digits2.size(); ++j) {
			changeValueInDigits(temp, base, i + j, digits1[i] * digits2[j]);
		}
		result = addDigits(result, temp, base);
	}
	return result;
}

std::vector<char> rightShiftDigits(
	const std::vector<char>& digits,
	unsigned int shift
) {
	std::vector<char> result = digits;
	if (result.size() > 0) for (int i = 0; i < shift; ++i) {
		result.insert(result.begin(), 0);
	}
	return result;
}

std::vector<char> leftShiftDigits(
	const std::vector<char>& digits,
	unsigned int shift
) {
	std::vector<char> result = digits;
	result.erase(result.begin(), result.begin() + shift);
	return result;
}

std::pair<std::vector<char>, std::vector<char>> divideDigitsBinary(
	const std::vector<char>& digits1,
	const std::vector<char>& digits2
) {
	if (digits2.size() == 0) {
		throw std::invalid_argument("Division by zero");
	}
	std::vector<char> Q;
	std::vector<char> R;
	for (int i = digits1.size() - 1; i >= 0; --i) {
		R = rightShiftDigits(R, 1);
		if (R.size() == 0) {
			if (digits1[i] == 1) R.push_back(1);
		} else {
			R[0] = digits1[i];
		}
		if (compareDigits(R, digits2) >= 0) {
			R = substractDigits(R, digits2, 2);
			while (Q.size() <= i) {
				Q.push_back(0);
			}
			Q[i] = 1;
		}
	}
	return std::make_pair(Q, R);
}

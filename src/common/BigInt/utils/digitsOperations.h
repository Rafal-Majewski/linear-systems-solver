#ifndef DIGITS_OPERATIONS_H_INCLUDED
#define DIGITS_OPERATIONS_H_INCLUDED

#include <vector>


std::vector<char> addDigits(
	const std::vector<char>& digits1,
	const std::vector<char>& digits2,
	char base
);

std::vector<char> substractDigits(
	const std::vector<char>& digits1,
	const std::vector<char>& digits2,
	char base
);

std::vector<char> multiplyDigits(
	const std::vector<char>& digits1,
	const std::vector<char>& digits2,
	char base
);

// std::vector<char> divideDigits(
// 	const std::vector<char>& digits1,
// 	const std::vector<char>& digits2,
// 	char base
// );

std::pair<std::vector<char>, std::vector<char>> divideDigitsBinary(
	const std::vector<char>& digits1,
	const std::vector<char>& digits2
);

char compareDigits(
	const std::vector<char>& digits1,
	const std::vector<char>& digits2
);

#endif

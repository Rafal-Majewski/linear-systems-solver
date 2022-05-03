#ifndef INVALID_LINEAR_SYSTEM_SIZE_EXCEPTION_H_INCLUDED
#define INVALID_LINEAR_SYSTEM_SIZE_EXCEPTION_H_INCLUDED

#include <stdexcept>


class InvalidLinearSystemSizeException : public std::invalid_argument {
	public:
	InvalidLinearSystemSizeException(const char *a_message);
};

#endif

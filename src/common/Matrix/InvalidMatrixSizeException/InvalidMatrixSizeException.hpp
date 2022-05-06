#ifndef INVALID_MATRIX_SIZE_EXCEPTION_H_INCLUDED
#define INVALID_MATRIX_SIZE_EXCEPTION_H_INCLUDED

#include <stdexcept>


class InvalidMatrixSizeException : public std::invalid_argument {
	public:
	InvalidMatrixSizeException(const char *a_message);
};


#endif

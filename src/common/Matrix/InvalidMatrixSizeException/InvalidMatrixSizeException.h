#ifndef INVALID_MATRIX_SIZE_EXCEPTION_H_INCLUDED
#define INVALID_MATRIX_SIZE_EXCEPTION_H_INCLUDED

#include <stdexcept>


class InvalidMatrixSizeException : public std::logic_error {
	public:
	InvalidMatrixSizeException(const char *a_message);
};


#endif

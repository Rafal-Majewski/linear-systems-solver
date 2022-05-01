#ifndef WRONG_MATRIX_SIZE_EXCEPTION_H_INCLUDED
#define WRONG_MATRIX_SIZE_EXCEPTION_H_INCLUDED

#include <stdexcept>


class InvalidArgumentException : public std::logic_error {
	public:
	InvalidArgumentException(const char *a_message);
};


#endif

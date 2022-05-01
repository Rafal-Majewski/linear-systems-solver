#ifndef WRONG_MATRIX_SIZE_EXCEPTION_H_INCLUDED
#define WRONG_MATRIX_SIZE_EXCEPTION_H_INCLUDED

#include <stdexcept>


class WrongMatrixSizeException : public std::logic_error {
	public:
	WrongMatrixSizeException(const char *a_message);
};


#endif

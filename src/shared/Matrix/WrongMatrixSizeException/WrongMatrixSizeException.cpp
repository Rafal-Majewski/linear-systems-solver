#include "WrongMatrixSizeException.h"


WrongMatrixSizeException::WrongMatrixSizeException(const char *a_message) : logic_error(a_message) {
}

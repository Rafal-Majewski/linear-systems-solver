#include "./InvalidArgumentException.h"

InvalidArgumentException::InvalidArgumentException(const char *a_message) : logic_error(a_message) {
}

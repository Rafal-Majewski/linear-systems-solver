#ifndef ARGUMENTS_MANAGER_H_INCLUDED
#define ARGUMENTS_MANAGER_H_INCLUDED

// #include <optional>
// #include <string>
#include <AbstractArgumentsManager/AbstractArgumentsManager.h>
#include "./Arguments/Arguments.h"
#include "./ArgumentsBuilder/ArgumentsBuilder.h"




class ArgumentsManager : public AbstractArgumentsManager<Arguments, ArgumentsBuilder> {
	public:
	ArgumentsManager();
};

#endif

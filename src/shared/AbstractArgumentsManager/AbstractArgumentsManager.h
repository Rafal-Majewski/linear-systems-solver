#ifndef ABSTRACT_ARGUMENTS_MANAGER_H_INCLUDED
#define ABSTRACT_ARGUMENTS_MANAGER_H_INCLUDED

#include <optional>
#include <vector>
#include <string>
#include <iostream>
#include "./Parameter/Parameter.h"
#include "./InvalidArgumentException/InvalidArgumentException.h"
#include <map>


template <typename A, typename AB>
class AbstractArgumentsManager {
	private:
	std::map<std::string, Parameter<AB>> parameters;
	// protected:
	std::pair<std::string, std::optional<std::string>> formatArg(char *arg) const {
		std::string argString(arg);
		std::string argName;
		std::optional<std::string> argValue;
		std::size_t equalSignPosition = argString.find('=');
		if (equalSignPosition != std::string::npos) {
			argName = argString.substr(0, equalSignPosition);
			argValue = argString.substr(equalSignPosition + 1);
		} else {
			argName = arg;
		}
		return std::make_pair(argName, argValue);
	}
	std::vector<std::pair<std::string, std::optional<std::string>>> formatArgs(int argc, char *argv[]) const {
		std::vector<std::pair<std::string, std::optional<std::string>>> formattedArgs;
		for (int i = 1; i < argc; i++) {
			formattedArgs.push_back(formatArg(argv[i]));
		}
		return formattedArgs;
	}
	void parse(
		std::pair<std::string, std::optional<std::string>> formattedArgument,
		AB &argumentsBuilder
	) const {
		std::cout << "Parsing argument: " << formattedArgument.first << std::endl;
		try {
			Parameter<AB> parameter = parameters.at(formattedArgument.first);
			if (formattedArgument.second.has_value()) {
				parameter.parse(argumentsBuilder, formattedArgument.second.value());
			} else {
				parameter.parse(argumentsBuilder);
			}
		} catch (std::out_of_range &e) {
			throw InvalidArgumentException("Invalid argument");
		}

	}
	void parse(
		std::vector<std::pair<std::string, std::optional<std::string>>> formattedArguments,
		AB &argumentsBuilder
	) const {
		for (auto formattedArgument : formattedArguments) {
			parse(formattedArgument, argumentsBuilder);
		}
	}
	A parse(
		std::vector<std::pair<std::string, std::optional<std::string>>> formattedArguments
	) const {
		AB argumentsBuilder = AB();
		parse(formattedArguments, argumentsBuilder);
		return argumentsBuilder.build();
	}
	public:
	A parse(int argc, char *argv[]) const {
		return parse(formatArgs(argc, argv));
	}
	void displayHelp() const {
		std::cout << "Test" << '\n';
	}
	AbstractArgumentsManager(std::vector<Parameter<AB>> a_parameters) {
		for (Parameter<AB> parameter : a_parameters) {
			parameters.insert({parameter.name, parameter});
		}
	}
};

#endif

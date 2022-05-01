#ifndef PARAMETER_H_INCLUDED
#define PARAMETER_H_INCLUDED

#include <optional>
#include <string>

template <typename AB>
class Parameter {
	public:
	virtual void parse(
		AB &argumentsBuilder,
		std::string const &value
	) const;
	virtual void parse(
		AB &argumentsBuilder
	) const;
	const std::string name;
	const bool isRequired;
	const bool takesValue;
	const std::string description;
	Parameter(
		std::string a_name,
		bool a_isRequired,
		std::string a_description,
		bool a_takesValue
	) : name(a_name), isRequired(a_isRequired), takesValue(a_takesValue), description(a_description) {}
};

#endif

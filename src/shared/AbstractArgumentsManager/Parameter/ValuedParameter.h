#ifndef VALUED_PARAMETER_H_INCLUDED
#define VALUED_PARAMETER_H_INCLUDED

#include "./Parameter.h"
#include "../InvalidArgumentException/InvalidArgumentException.h"

template <typename AB>
class ValuedParameter : public Parameter<AB> {
	public:
	ValuedParameter(
		std::string a_name,
		bool a_isRequired,
		std::string a_description
	) : Parameter<AB>(a_name, a_isRequired, a_description, true) {}
	void parse(
		AB &abstractArgumentsBuilder
	) const {
		throw InvalidArgumentException("Parameter " + this->name + " requires a value");
	}
};

#endif

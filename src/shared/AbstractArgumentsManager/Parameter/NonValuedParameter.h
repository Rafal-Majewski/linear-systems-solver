#ifndef NON_VALUED_PARAMETER_H_INCLUDED
#define NON_VALUED_PARAMETER_H_INCLUDED

#include "./Parameter.h"
#include "../InvalidArgumentException/InvalidArgumentException.h"


template <typename AB>
class NonValuedParameter : public Parameter<AB> {
	public:
	NonValuedParameter(
		std::string name,
		bool isRequired,
		std::string description
	) : Parameter<AB>(name, isRequired, description, false) {}
	void parse(
		AB &argumentsBuilder,
		std::string const &value
	) const override {
		throw InvalidArgumentException("Parameter does not take a value");
	}
};

#endif

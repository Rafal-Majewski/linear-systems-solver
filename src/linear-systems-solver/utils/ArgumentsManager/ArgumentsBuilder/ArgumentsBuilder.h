#ifndef ARGUMENTS_BUILDER_H
#define ARGUMENTS_BUILDER_H

#include "../Arguments/Arguments.h"
#include <optional>
#include <AbstractArgumentsManager/AbstractArgumentsBuilder/AbstractArgumentsBuilder.h>


class ArgumentsBuilder : public AbstractArgumentsBuilder<Arguments> {
	std::optional<bool> doDisplayHelp;
	public:
	void setDoDisplayHelp(bool a_doDisplayHelp);
	Arguments build() const override;
};

#endif

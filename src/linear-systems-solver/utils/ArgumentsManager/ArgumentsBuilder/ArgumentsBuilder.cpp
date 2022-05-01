#include "./ArgumentsBuilder.h"


Arguments ArgumentsBuilder::build() const {
	return Arguments(
		doDisplayHelp.value_or(false)
	);
}

void ArgumentsBuilder::setDoDisplayHelp(bool a_doDisplayHelp) {
	doDisplayHelp = a_doDisplayHelp;
}

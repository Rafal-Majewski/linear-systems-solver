#ifndef PARAMES_H_INCLUDED
#define PARAMES_H_INCLUDED

#include <AbstractArgumentsManager/Parameter/Parameter.h>
#include <AbstractArgumentsManager/Parameter/NonValuedParameter.h>
#include "../ArgumentsBuilder/ArgumentsBuilder.h"

namespace Parameters {
	class DoDisplayHelpParameter : public NonValuedParameter<ArgumentsBuilder> {
		public:
		DoDisplayHelpParameter() : NonValuedParameter(
			std::string("-h"),
			false,
			std::string("Display help")
		) {}
		void parse(
			ArgumentsBuilder &argumentsBuilder
		) const {
			// argumentsBuilder.setDoDisplayHelp(true);
		}
	};

}


#endif

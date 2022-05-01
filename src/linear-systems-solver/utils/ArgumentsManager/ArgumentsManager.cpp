#include "./ArgumentsManager.h"
#include "./Parameters/Parameters.h"


ArgumentsManager::ArgumentsManager() : AbstractArgumentsManager<Arguments, ArgumentsBuilder>(std::vector<Parameter<ArgumentsBuilder>> {
	// Parameters::DoDisplayHelp(),
}
) {}
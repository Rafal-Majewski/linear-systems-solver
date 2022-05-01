#include <iostream>
#include "./utils/ArgumentsManager/ArgumentsBuilder/ArgumentsBuilder.h"
#include "./utils/ArgumentsManager/Parameters/Parameters.h"
#include "./utils/ArgumentsManager/ArgumentsManager.h"


int main(int argc, char *argv[]) {
	ArgumentsManager argumentsManager = ArgumentsManager();
	Arguments arguments = argumentsManager.parse(argc, argv);
	if (arguments.doDisplayHelp) {
		argumentsManager.displayHelp();
		return 0;
	}
	return 0;
}

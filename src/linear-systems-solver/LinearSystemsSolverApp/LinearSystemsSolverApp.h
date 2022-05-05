#ifndef LINEAR_SYSTEMS_SOLVER_APP_H_INCLUDED
#define LINEAR_SYSTEMS_SOLVER_APP_H_INCLUDED


#include <CLI/CLI.hpp>

class LinearSystemsSolverApp {
	private:
	const CLI::App cliApp = CLI::App("Linear Systems Solver");
	public:
	int main(int argc, char **argv);
};

#endif // LINEAR_SYSTEMS_SOLVER_APP_H_INCLUDED

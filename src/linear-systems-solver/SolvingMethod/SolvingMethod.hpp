#ifndef SOLVING_METHOD_H_INCLUDED
#define SOLVING_METHOD_H_INCLUDED

#include <map>
#include <string>


enum SolvingMethod {
	G,
	PG,
	FG,
};

std::map<std::string, SolvingMethod> solvingMethodByString = {
	{"g", SolvingMethod::G},
	{"pg", SolvingMethod::PG},
	{"fg", SolvingMethod::FG},
};

std::map<SolvingMethod, std::string> stringBySolvingMethod = {
	{SolvingMethod::G, "g"},
	{SolvingMethod::PG, "pg"},
	{SolvingMethod::FG, "fg"},
};

#endif // SOLVING_METHOD_H_INCLUDED

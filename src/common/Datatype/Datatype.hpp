#ifndef DATATYPE_H_INCLUDED
#define DATATYPE_H_INCLUDED

#include <map>
#include <string>

enum Datatype {
	FLOAT,
	DOUBLE,
	RATIONAL,
};

std::map<std::string, Datatype> datatypeByString = {
	{"float", Datatype::FLOAT},
	{"double", Datatype::DOUBLE},
	{"rational", Datatype::RATIONAL},
};

std::map<Datatype, std::string> stringByDatatype = {
	{Datatype::FLOAT, "float"},
	{Datatype::DOUBLE, "double"},
	{Datatype::RATIONAL, "rational"},
};

#endif

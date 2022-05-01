#ifndef ABSTRACT_ARGUMENTS_BUILDER_H_INCLUDED
#define ABSTRACT_ARGUMENTS_BUILDER_H_INCLUDED


template <typename A>
class AbstractArgumentsBuilder {
	public:
	virtual A build() const = 0;
};

#endif

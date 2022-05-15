#ifndef TOKENS_READER_H_INCLUDED
#define TOKENS_READER_H_INCLUDED

#include <iostream>
#include <vector>


template <typename T>
class TokensReader {
	private:
	int readSize() const;
	std::vector<std::string> readTokens(int size) const;

	public:
	std::vector<std::string> read() const;
};

#include "./TokensReader.tpp"

#endif

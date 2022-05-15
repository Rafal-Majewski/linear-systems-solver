#include "./TokensReader.hpp"


template <typename T>
int TokensReader<T>::readSize() const {
	int tokensCount;
	std::cin >> tokensCount;
	return tokensCount;
}

template <typename T>
std::vector<std::string> TokensReader<T>::readTokens(int size) const {
	std::vector<std::string> tokens;
	for (int i = 0; i < size; i++) {
		std::string token;
		std::cin >> token;
		tokens.push_back(token);
	}
	return tokens;
}
template <typename T>
std::vector<std::string> TokensReader<T>::read() const {
	int size = readSize();
	return readTokens(size);
}

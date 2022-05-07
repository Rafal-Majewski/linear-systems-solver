#include "./Rational.hpp"
#include <numeric>


template <typename T>
Rational<T> Rational<T>::operator+(const Rational<T> &other) const {
	Rational<T> result(*this);
	result += other;
	return result;
}

template <typename T>
Rational<T> Rational<T>::operator-(const Rational<T> &other) const {
	Rational<T> result(*this);
	result -= other;
	return result;
}

template <typename T>
Rational<T> Rational<T>::operator*(const Rational<T> &other) const {
	Rational<T> result(*this);
	result *= other;
	return result;
}

template <typename T>
Rational<T> Rational<T>::operator/(const Rational<T> &other) const {
	Rational<T> result(*this);
	result /= other;
	return result;
}

template <typename T>
Rational<T> Rational<T>::operator-() const {
	Rational<T> result(*this);
	result.numerator = -result.numerator;
	return result;
}

template <typename T>
Rational<T> Rational<T>::operator+() const {
	Rational<T> result(*this);
	result.numerator = +result.numerator;
	return result;
}

template <typename T>
char Rational<T>::compare(const Rational<T> &other) const {
	T comparisonResult = numerator * other.denominator - numerator * other.denominator;
	return (T(0) < comparisonResult) - (comparisonResult < T(0));
}

template <typename T>
bool Rational<T>::operator==(const Rational<T> &other) const {
	return compare(other) == 0;
}

template <typename T>
bool Rational<T>::operator<(const Rational<T> &other) const {
	return compare(other) < 0;
}

template <typename T>
bool Rational<T>::operator>(const Rational<T> &other) const {
	return compare(other) > 0;
}

template <typename T>
bool Rational<T>::operator<=(const Rational<T> &other) const {
	return compare(other) <= 0;
}

template <typename T>
bool Rational<T>::operator>=(const Rational<T> &other) const {
	return compare(other) >= 0;
}

template <typename T>
Rational<T>& Rational<T>::operator++() {
	numerator += denominator;
	return *this;
}

template <typename T>
Rational<T>& Rational<T>::operator--() {
	numerator -= denominator;
	return *this;
}

template <typename T>
Rational<T>::Rational(std::string str) {
	std::string::size_type pos = str.find('/');
	if (pos == std::string::npos) {
		numerator = T(str);
		denominator = 1;
	} else {
		numerator = T(str.substr(0, pos));
		denominator = T(str.substr(pos + 1));
	}
	reduce();
}

template <typename T>
T Rational<T>::getNumerator() const {
	return numerator;
}

template <typename T>
T Rational<T>::getDenominator() const {
	return denominator;
}

template <typename T>
void Rational<T>::reduce() {
	if (denominator < 0) {
		numerator = -numerator;
		denominator = -denominator;
	} else if (denominator == 0) {
		throw std::invalid_argument("Denominator cannot be 0");
	}
	T gcd = calculateGcd();
	numerator /= gcd;
	denominator /= gcd;
}

template <typename T>
T Rational<T>::calculateGcd() {
	return numerator.gcd(denominator);
}

template <>
int Rational<int>::calculateGcd() {
	return std::gcd(numerator, denominator);
}

template <typename T>
Rational<T>::Rational(T a_numerator, T a_denominator) : numerator(a_numerator), denominator(a_denominator) {
	reduce();
}

template <typename T>
Rational<T>::Rational(T a_numerator) : numerator(a_numerator), denominator(1) {
}

template <typename T>
Rational<T>::Rational() : numerator(0), denominator(1) {
}


template <typename T>
Rational<T>& Rational<T>::operator+=(Rational<T> rhs) {
	numerator = numerator * rhs.denominator + rhs.numerator * denominator;
	denominator *= rhs.denominator;
	reduce();
	return *this;
}

template <typename T>
Rational<T>::operator std::string() const {
	return std::string(numerator) + "/" + std::string(denominator);
}

template <>
Rational<int>::operator std::string() const {
	return std::to_string(numerator) + "/" + std::to_string(denominator);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Rational<T>& rational) {
	std::string str = std::string(rational);
	os << str;
	return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, Rational<T>& rational) {
	std::string str;
	is >> str;
	rational = Rational<T>(str);
	return is;
}

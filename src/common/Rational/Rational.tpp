#include "./Rational.hpp"
#include <numeric>


template <typename T>
char Rational<T>::compare(const Rational<T> &other) const {
	T comparisonResult = this->numerator * other.denominator - this->denominator * other.numerator;
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
T Rational<T>::stringToNumber(const std::string &str) {
	return T::fromString(str);
}

template <typename T>
Rational<T> Rational<T>::fromString(std::string str) {
	std::string::size_type pos = str.find('/');
	T numerator;
	T denominator;
	if (pos == std::string::npos) {
		numerator = Rational<T>::stringToNumber(str);
		denominator = 1;
	} else {
		numerator = Rational<T>::stringToNumber(str.substr(0, pos));
		denominator = Rational<T>::stringToNumber(str.substr(pos + 1));
	}
	return Rational<T>(numerator, denominator);
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
	T gcd = numerator.gcd(denominator);
	numerator /= gcd;
	denominator /= gcd;
}

template <typename T>
Rational<T>::Rational(T a_numerator, T a_denominator) : numerator(a_numerator), denominator(a_denominator) {
	reduce();
}

template <typename T>
Rational<T>::Rational(T a_numerator) : numerator(a_numerator), denominator(T(1)) {
}

template <typename T>
Rational<T>::Rational() : numerator(T(0)), denominator(T(1)) {
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
	rational = Rational<T>::fromString(str);
	return is;
}

template <typename T>
Rational<T>& Rational<T>::operator-=(Rational<T> other) {
	numerator = numerator * other.denominator - other.numerator * denominator;
	denominator *= other.denominator;
	reduce();
	return *this;
}

template <typename T>
Rational<T>& Rational<T>::operator*=(Rational<T> other) {
	numerator *= other.numerator;
	denominator *= other.denominator;
	reduce();
	return *this;
}

template <typename T>
Rational<T>& Rational<T>::operator/=(Rational<T> other) {
	numerator *= other.denominator;
	denominator *= other.numerator;
	reduce();
	return *this;
}


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
Rational<T>::operator double() const {
	return (double)numerator / (double)denominator;
}

template <typename T>
Rational<T> abs(const Rational<T> &rational) {
	return Rational<T>(abs(rational.numerator), rational.denominator);
}

template <typename T>
Rational<T>::Rational(int a_numerator, int a_denominator) : numerator(T(a_numerator)), denominator(T(a_denominator)) {
	reduce();
}

template <typename T>
Rational<T>::Rational(int a_numerator) : numerator(T(a_numerator)), denominator(T(1)) {
}

template <typename T>
Rational<T>::Rational(long a_numerator, long a_denominator) : numerator(T(a_numerator)), denominator(T(a_denominator)) {
	reduce();
}

template <typename T>
Rational<T>::Rational(long a_numerator) : numerator(T(a_numerator)), denominator(T(1)) {
}

template <typename T>
Rational<T>::Rational(double a_num) {
	numerator = 0;
	denominator = 1;
	if (a_num == 0) return;
	double sign = a_num < 0 ? -1 : 1;
	double num = std::abs(a_num);
	Rational<T> mult = T(1);
	long long floored = (long long)(num);
	*this += mult * T(floored);
	for (int i = 0; num != 0; ++i) {
		num -= floored;
		num *= 2;
		mult /= T(2);
		floored = (long long)(num);
		*this += mult * T(floored);
	}
	numerator *= sign;
}

template <typename T>
Rational<T>::Rational(float a_num) {
	numerator = 0;
	denominator = 1;
	if (a_num == 0) return;
	double sign = a_num < 0 ? -1 : 1;
	double num = std::abs(a_num);
	Rational<T> mult = T(1);
	long long floored = (long long)(num);
	*this += mult * T(floored);
	for (int i = 0; num != 0; ++i) {
		num -= floored;
		num *= 2;
		mult /= T(2);
		floored = (long long)(num);
		*this += mult * T(floored);
	}
	numerator *= sign;
}

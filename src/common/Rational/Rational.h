#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

#include <numeric>
#include <string>
#include <stdexcept>


template <typename T>
struct Rational {
	private:
	T numerator;
	T denominator;
	void reduce();
	public:
	T getNumerator() const;
	T getDenominator() const;
	Rational(T anumerator, T adenominator);


	// Because of the compiler errors
	// operators have to be defined here.
	// Please submit a comment or a pull request
	// if you know how to fix it.

	friend Rational<T> operator+(const Rational<T> &lhs, const Rational<T> &rhs) {
		Rational<T> result(lhs);
		result += rhs;
		return result;
	}
	friend Rational<T> operator-(const Rational<T> &lhs, const Rational<T> &rhs) {
		Rational<T> result(lhs);
		result -= rhs;
		return result;
	}
	friend Rational<T> operator*(const Rational<T> &lhs, const Rational<T> &rhs) {
		Rational<T> result(lhs);
		result *= rhs;
		return result;
	}
	friend Rational<T> operator/(const Rational<T> &lhs, const Rational<T> &rhs) {
		Rational<T> result(lhs);
		result /= rhs;
		return result;
	}
	friend bool operator==(const Rational<T> &lhs, const Rational<T> &rhs) {
		return lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator;
	}
	friend bool operator!=(const Rational<T> &lhs, const Rational<T> &rhs) {
		return lhs.numerator != rhs.numerator || lhs.denominator != rhs.denominator;
	}
	friend bool operator<(const Rational<T> &lhs, const Rational<T> &rhs) {
		return lhs.numerator * rhs.denominator < rhs.numerator * lhs.denominator;
	}
	friend bool operator>(const Rational<T> &lhs, const Rational<T> &rhs) {
		return lhs.numerator * rhs.denominator > rhs.numerator * lhs.denominator;
	}
	friend bool operator<=(const Rational<T> &lhs, const Rational<T> &rhs) {
		return lhs.numerator * rhs.denominator <= rhs.numerator * lhs.denominator;
	}
	friend bool operator>=(const Rational<T> &lhs, const Rational<T> &rhs) {
		return lhs.numerator * rhs.denominator >= rhs.numerator * lhs.denominator;
	}
	Rational<T> &operator+=(const Rational<T> &rhs);
	Rational<T> &operator-=(const Rational<T> &rhs);
	Rational<T> &operator*=(const Rational<T> &rhs);
	Rational<T> &operator/=(const Rational<T> &rhs);
	operator std::string() const;
	Rational<T>& operator++();
	Rational<T>& operator--();
	Rational<T> operator++(int count);
	Rational<T> operator--(int count);
	friend std::ostream& operator<<(std::ostream& os, const Rational& rational) {
		os << std::string(rational);
		return os;
	};
};

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
	T gcd = std::gcd(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
}

template <typename T>
Rational<T>::Rational(T anumerator, T adenominator) : numerator(anumerator), denominator(adenominator) {
	reduce();
}

template <typename T>
Rational<T>& Rational<T>::operator+=(const Rational<T> &rhs) {
	numerator = numerator * rhs.denominator + rhs.numerator * denominator;
	denominator *= rhs.denominator;
	reduce();
	return *this;
}

template <typename T>
Rational<T>::operator std::string() const {
	return std::to_string(numerator) + "/" + std::to_string(denominator);
}

#endif

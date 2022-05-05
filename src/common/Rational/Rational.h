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
	inline T calculateGcd();
	public:
	T getNumerator() const;
	T getDenominator() const;
	// Rational();
	// Rational(T a_numerator);
	Rational(T a_numerator = 0, T a_denominator = 1);
	Rational(std::string str);


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
	friend std::ostream& operator<<(std::ostream& os, const Rational<T>& rational) {
		os << std::string(rational);
		return os;
	};
	friend std::istream& operator>>(std::istream& is, Rational<T>& rational) {
		std::string str;
		is >> str;
		rational = Rational<T>(str);
		return is;
	};
};

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

// template <>
// void Rational<int>::reduce() {
// 	if (denominator < 0) {
// 		numerator = -numerator;
// 		denominator = -denominator;
// 	} else if (denominator == 0) {
// 		throw std::invalid_argument("Denominator cannot be 0");
// 	}
// 	int gcd = std::gcd(numerator, denominator);
// 	numerator /= gcd;
// 	denominator /= gcd;
// }

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
	return std::string(numerator) + "/" + std::string(denominator);
}

template <>
Rational<int>::operator std::string() const {
	return std::to_string(numerator) + "/" + std::to_string(denominator);
}

#endif

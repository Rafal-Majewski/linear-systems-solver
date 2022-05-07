#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

#include <iostream>


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
	Rational(T a_numerator, T a_denominator);
	Rational(T a_numerator);
	Rational();
	Rational(std::string str);
	Rational<T> operator+(const Rational<T> &other) const;
	Rational<T> operator-(const Rational<T> &other) const;
	Rational<T> operator*(const Rational<T> &other) const;
	Rational<T> operator/(const Rational<T> &other) const;
	Rational<T> operator-() const;
	Rational<T> operator+() const;
	Rational<T>& operator+=(Rational<T> other);
	Rational<T>& operator-=(Rational<T> other);
	Rational<T>& operator*=(Rational<T> other);
	Rational<T>& operator/=(Rational<T> other);
	bool operator==(const Rational<T> &other) const;
	bool operator!=(const Rational<T> &other) const;
	bool operator<(const Rational<T> &other) const;
	bool operator>(const Rational<T> &other) const;
	bool operator<=(const Rational<T> &other) const;
	bool operator>=(const Rational<T> &other) const;
	char compare(const Rational<T> &other) const;
	Rational<T>& operator++();
	Rational<T>& operator--();
	Rational<T> operator++(int);
	Rational<T> operator--(int);
	operator std::string() const;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Rational<T>& rational);

template <typename T>
std::istream& operator>>(std::istream& is, Rational<T>& rational);

#include "./Rational.tpp"

#endif

#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

#include <iostream>

template <typename T>
struct Rational;

template <typename T>
Rational<T> abs(const Rational<T> &rational);


template <typename T>
struct Rational {
	private:
	T numerator;
	T denominator;
	void reduce();
	inline T calculateGcd();
	static inline T stringToNumber(const std::string &str);

	public:
	T getNumerator() const;
	T getDenominator() const;
	Rational(T numerator, T denominator);
	Rational(T numerator);
	Rational(int numerator, int denominator);
	Rational(int numerator);
	Rational(long numerator, long denominator);
	Rational(long numerator);
	Rational(float num);
	Rational(double num);
	Rational();
	static Rational<T> fromString(std::string str);
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

	operator double() const;
	friend Rational<T> abs<T>(const Rational<T> &rational);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Rational<T>& rational);

template <typename T>
std::istream& operator>>(std::istream& is, Rational<T>& rational);

#include "./Rational.tpp"

#endif

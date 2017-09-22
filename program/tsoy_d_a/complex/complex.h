#pragma once
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iosfwd>


struct Complex {
	Complex() {}
	explicit Complex(const double real);
	Complex(const double real, const double imaginary);
	bool operator==(const Complex& rhs) const;
	bool operator!=(const Complex& rhs) const;
	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs);
	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs);
	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double rhs);
	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double rhs);
	//Complex& operator-(const Complex& rhs);
	Complex& operator=(const Complex& rhs);
	Complex& operator=(const double rhs);
    static Complex pov(const Complex& rhs, const int n);
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };

};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);


std::ostream& operator << (std::ostream& ostrm, const Complex& rhs);

std::istream& operator >> (std::istream& istrm, Complex& rhs);


#endif // !COMPLEX_H
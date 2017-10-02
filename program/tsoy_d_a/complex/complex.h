#ifndef COMPLEX_H
#define COMPLEX_H

#include <iosfwd>
#include <string>


struct Complex {
	Complex() {}
	~Complex() = default;
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
	Complex& operator=(const Complex& rhs);
	Complex& operator=(const double rhs);
	Complex operator-() const; // унарный минс
	static Complex pov(const Complex& rhs, const int n); // возведение в степень
	static Complex sopr(const Complex& rhs); // сопряженное
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
Complex operator/(const Complex& lhs, const Complex& rhs);

Complex operator+(const Complex& lhs, const double rhs);
Complex operator-(const Complex& lhs, const double rhs);
Complex operator*(const Complex& lhs, const double rhs);
Complex operator/(const Complex& lhs, const double rhs);

Complex operator+(const double lhs, const Complex& rhs);
Complex operator-(const double lhs, const Complex& rhs);
Complex operator*(const double lhs, const Complex& rhs);
Complex operator/(const double lhs, const Complex& rhs);



std::ostream& operator << (std::ostream& ostrm, const Complex& rhs);
std::istream& operator >> (std::istream& istrm, Complex& rhs);



#endif 
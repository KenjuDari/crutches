#ifndef RATION_H
#define RATION_H

#include <iosfwd>

class Rational {
public:
	Rational() = default;
	~Rational() = default;
	explicit Rational(const int n);
	Rational(const int integer, const int natural);
	Rational(Rational& rhs) = default;
	bool operator==(const Rational& rhs) const;
	bool operator!=(const Rational& rhs) const;
	bool operator>(const Rational& rhs) const;
	bool operator<(const Rational& rhs) const;
	bool operator>=(const Rational& rhs) const;
	bool operator<=(const Rational& rhs) const;
	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const int rhs);
	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const int rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const int rhs);
	Rational& operator/=(const Rational& rhs);
	Rational& operator/=(const int rhs);
	Rational operator-() const;
	static Rational pov(const Rational& rhs, const int n); // возведение в степень
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

private:
	int ch{ 0 };
	int zn{ 1 };
	static const char slash{ '/' };
	static void normaliz(Rational& rhs);

};

std::ostream& operator << (std::ostream& ostrm, const Rational& rhs);
std::istream& operator >> (std::istream& istrm, Rational& rhs);

Rational operator+(const Rational& r1, const Rational& r2);
Rational operator-(const Rational& r1, const Rational& r2);
Rational operator*(const Rational& r1, const Rational& r2);
Rational operator/(const Rational& r1, const Rational& r2);

Rational operator+(const Rational& r1, const int r2);
Rational operator-(const Rational& r1, const int r2);
Rational operator*(const Rational& r1, const int r2);
Rational operator/(const Rational& r1, const int r2);

Rational operator+(const int r1, const Rational& r2);
Rational operator-(const int r1, const Rational& r2);
Rational operator*(const int r1, const Rational& r2);
Rational operator/(const int r1, const Rational& r2);

#endif 


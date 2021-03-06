#include "complex.h"

using namespace std;


Complex::Complex(const double real)
	: Complex(real, 0.0)
{
}


Complex::Complex(const double real, const double imaginary)
	: re(real)
	, im(imaginary)
{
}


bool Complex::operator==(const Complex& rhs) const
{
	if ((re - rhs.re) < 1e-10 && (im - rhs.im) < 1e-10)
		return true;
	else
		return false;
}


bool Complex::operator!=(const Complex& rhs) const
{
	return !operator==(rhs);
}


Complex& Complex::operator+=(const double rhs)
{
	return operator+=(Complex(rhs));
}


Complex& Complex::operator+=(const Complex& rhs)
{
	re += rhs.re;
	im += rhs.im;
	return *this;
}


Complex& Complex::operator-=(const double rhs)
{
	return operator-=(Complex(rhs));
}


Complex& Complex::operator-=(const Complex& rhs)
{
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}


Complex& Complex::operator*=(const double rhs)
{
	re = re * rhs;
	im = im * rhs;
	return *this;
}


Complex& Complex::operator*=(const Complex& rhs)
{
	double a, b;
	a = re * rhs.re - im * rhs.im;
	b = re * rhs.im + im * rhs.re;
	re = a;
	im = b;
	return *this;
}


Complex& Complex::operator/=(const double rhs)
{
	re /= rhs;
	im /= rhs;
	return *this;
}


Complex& Complex::operator/=(const Complex& rhs)
{
	double a, b;
	a = (re * rhs.re + im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	b = (im * rhs.re - re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	re = a;
	im = b;
	return *this;
}


Complex& Complex::operator=(const Complex& rhs)
{
	re = rhs.re;
	im = rhs.im;
	return *this;
}


Complex& Complex::operator=(const double rhs)
{
	re = rhs;
	im = 0;
	return *this;
}


Complex Complex::operator-() const
{
	Complex rhs = *this;
	rhs *= -1;
	return rhs;
}

Complex Complex::pov(const Complex& rhs, const int n)
{
	Complex r = rhs;
	for (int i(1); i < n; i++)
		r *= rhs;
	return r;
}


Complex Complex::sopr(const Complex& rhs)
{
	Complex r = rhs;
	if (0 != r.im)
		r.im *= -1;
	return r;
}


ostream& Complex::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}


istream& Complex::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaganary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
			&& (Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaganary;

		}
		else {
			istrm.setstate(std::ios_base::failbit);

		}

	}
	return istrm;
}


Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex sum(lhs);
	sum += rhs;
	return sum;
}


Complex operator-(const Complex& lhs, const Complex& rhs)
{
	return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}


Complex operator*(const Complex& lhs, const Complex& rhs)
{
	Complex pr(lhs);
	pr *= rhs;
	return pr;
}


Complex operator/(const Complex& lhs, const Complex& rhs)
{
	Complex pr(lhs);
	pr /= rhs;
	return pr;
}


Complex operator+(const Complex& lhs, const double rhs)
{
	Complex sum(lhs);
	sum += rhs;
	return sum;
}


Complex operator-(const Complex& lhs, const double rhs)
{
	Complex sum(lhs);
	sum -= rhs;
	return sum;
}


Complex operator*(const Complex& lhs, const double rhs)
{
	Complex pr(lhs);
	pr *= rhs;
	return pr;
}


Complex operator/(const Complex& lhs, const double rhs)
{
	Complex pr(lhs);
	pr /= rhs;
	return pr;
}


Complex operator+(const double lhs, const Complex& rhs)
{
	Complex sum(lhs);
	sum += rhs;
	return sum;
}


Complex operator-(const double lhs, const Complex& rhs)
{
	Complex sum(lhs);
	sum -= rhs;
	return sum;
}


Complex operator*(const double lhs, const Complex& rhs)
{
	Complex pr(lhs);
	pr *= rhs;
	return pr;
}


Complex operator/(const double lhs, const Complex& rhs)
{
	Complex pr(lhs);
	pr /= rhs;
	return pr;
}


ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
	return rhs.writeTo(ostrm);
}


istream& operator >> (std::istream& istrm, Complex& rhs)
{
	return rhs.readFrom(istrm);
}
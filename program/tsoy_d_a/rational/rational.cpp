#include "rational.h"
#include <iostream>
#include <stdexcept>


using namespace std;


int nod(int a, int b)
{
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}


int nok(int a, int b)
{
	return a*b / nod(a, b);
}


void Rational::normaliz(Rational& rhs)
{
	if (rhs.zn < 0)
	{
		rhs.ch *= -1;
		rhs.zn *= -1;
	}
	const int a = nod(rhs.ch, rhs.zn);
	rhs.ch /= a;
	rhs.zn /= a;
}


Rational::Rational(const int n)
	: ch(n), zn(1) {}

Rational::Rational(const int integer, const int natural)
	: ch(integer), zn(natural)
{
	if (0 == natural) throw invalid_argument("Error: Can't divide into 0");
	Rational::normaliz(*this);
}

Rational& Rational::operator=(const Rational& rhs)
{
	ch = rhs.ch;
	zn = rhs.zn;
	return *this;
}



bool Rational::operator==(const Rational& rhs) const
{
	return (ch == rhs.ch) && (zn == rhs.zn);
}


bool Rational::operator!=(const Rational& rhs) const
{
	return !operator==(rhs);
}


bool Rational::operator>(const Rational& rhs) const
{
	int k = nok(zn, rhs.zn);
	int ch1 = ch;
	int ch2 = rhs.ch;
	if (zn != k)
	{
		ch1 *= k / zn;
	}
	if (rhs.zn != k)
	{
		ch2 *= (k / rhs.zn);
	}
	return ch1 > ch2;
}


bool Rational::operator<(const Rational& rhs) const
{
	int k = nok(zn, rhs.zn);
	int ch1 = ch;
	int ch2 = rhs.ch;
	if (zn != k)
	{
		ch1 *= k / zn;
	}
	if (rhs.zn != k)
	{
		ch2 *= (k / rhs.zn);
	}
	return ch1 < ch2;
}


bool Rational::operator>=(const Rational& rhs) const
{
	return operator>(rhs) || operator==(rhs);
}


bool Rational::operator<=(const Rational& rhs) const
{
	return operator<(rhs) || operator==(rhs);
}


Rational& Rational::operator+=(const Rational& rhs)
{
	int a(rhs.ch);
	int b(rhs.zn);
	int k = nok(zn, rhs.zn);
	if (zn != k)
	{
		ch *= k / zn;
		zn = k;
	}
	if (b != k)
	{
		a *= (k / b);
	}
	ch += a;
	Rational::normaliz(*this);
	return *this;
}


Rational& Rational::operator+=(const int rhs)
{
	return operator+=(Rational(rhs));
}


Rational& Rational::operator-=(const Rational& rhs)
{
	int a(rhs.ch);
	int b(rhs.zn);
	int k = nok(rhs.ch, rhs.zn);
	if (zn != k)
	{
		ch *= (zn / k);
		zn = k;
	}
	if (b != k)
	{
		a *= (b / k);
	}
	ch -= a;
	Rational::normaliz(*this);
	return *this;
}


Rational& Rational::operator-=(const int rhs)
{
	return operator+=(Rational(rhs));
}


Rational& Rational::operator*=(const int rhs)
{
	ch *= rhs;
	Rational::normaliz(*this);
	return *this;
}


Rational& Rational::operator*=(const Rational& rhs)
{
	ch *= rhs.ch;
	zn *= rhs.zn;
	Rational::normaliz(*this);
	return *this;
}


Rational& Rational::operator/=(const int rhs)
{
	zn *= rhs;
	Rational::normaliz(*this);
	return *this;
}


Rational& Rational::operator/=(const Rational& rhs)
{
	zn *= rhs.ch;
	ch *= rhs.zn;
	Rational::normaliz(*this);
	return *this;
}


Rational Rational::operator-() const
{
	Rational rhs(*this);
	rhs *= -1;
	return rhs;
}


Rational Rational::pov(const Rational& rhs, const int n)
{
	Rational r(rhs);
	for (int i(1); i < n; i++)
		r *= rhs;
	return r;
}


ostream& Rational::writeTo(std::ostream& ostrm) const
{
	if ((ch == 0) || (zn == 1))
	{
		if (ch == 0)
			ostrm << "0";
		else
			ostrm << ch;
	}
	else
	ostrm << ch << slash << zn;
	return ostrm;
}


istream& Rational::readFrom(std::istream& istrm)
{
	int integer(0);
	char slash(0);
	int natural(1);
	istrm >> integer >> slash >> natural;
	if (istrm.good())
		if (Rational::slash == slash)
		{
			ch = integer;
			zn = natural;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
		return istrm;
}


std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
	return rhs.writeTo(ostrm);
}


std::istream& operator >> (std::istream& istrm, Rational& rhs)
{
	return rhs.readFrom(istrm);
}


Rational operator+(const Rational& r1, const Rational& r2)
{
	Rational sum(r1);
	sum += r2;
	return sum;
}


Rational operator-(const Rational& r1, const Rational& r2)
{
	Rational raz(r1);
	raz -= r2;
	return raz;
}


Rational operator*(const Rational& r1, const Rational& r2)
{
	Rational pr(r1);
	pr *= r2;
	return pr;
}


Rational operator/(const Rational& r1, const Rational& r2)
{
	Rational raz(r1);
	raz /= r2;
	return raz;
}


Rational operator+(const Rational& r1, const int r2)
{
	Rational sum(r1);
	sum += r2;
	return sum;
}


Rational operator-(const Rational& r1, const int r2)
{
	Rational raz(r1);
	raz -= r2;
	return raz;
}


Rational operator*(const Rational& r1, const int r2)
{
	Rational pr(r1);
	pr *= r2;
	return pr;
}


Rational operator/(const Rational& r1, const int r2)
{
	Rational raz(r1);
	raz /= r2;
	return raz;
}


Rational operator+(const int r1, const Rational& r2)
{
	Rational sum(r1);
	sum += r2;
	return sum;
}


Rational operator-(const int r1, const Rational& r2)
{
	Rational raz(r1);
	raz -= r2;
	return raz;
}


Rational operator*(const int r1, const Rational& r2)
{
	Rational pr(r1);
	pr *= r2;
	return pr;
}


Rational operator/(const int r1, const Rational& r2)
{
	Rational raz(r1);
	raz /= r2;
	return raz;
}

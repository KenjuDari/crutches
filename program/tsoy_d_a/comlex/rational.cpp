#include "rational.h"
#include <iostream>
#include <sstream>

using namespace std;


int nod(int a, int b)
{
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
	//if (0 == natural) throw
	//{

	//}
}


bool Rational::operator==(const Rational& rhs) const
{
	return (ch == rhs.ch) && (zn == rhs.zn);
}


bool Rational::operator!=(const Rational& rhs) const
{
	return !operator==(rhs);
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


Rational Rational::pov(const Rational& rhs, const int n)
{
	Rational r = rhs;
	for (int i(1); i < n; i++)
		r *= rhs;
	return r;
}


ostream& Rational::writeTo(std::ostream& ostrm) const
{
	ostrm << ch << slash << zn;
	return ostrm;
}


istream& Rational::readFrom(std::istream& istrm)
{
	int integer(0);
	char slash(0);
	int natural(0);
	istrm >> integer >> slash >> natural;
	if (istrm.good() || istrm.eof())
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


//const Rational operator-(const Rational& rhs)
//{
//	return (rhs * Rational(-1));
//}


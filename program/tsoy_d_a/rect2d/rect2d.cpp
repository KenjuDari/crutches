#include"rect2d.h"

#include<iostream>
#include<sstream>

using namespace std;

void Rect2d::normaliz(Rect2d& rhs)
{
	if (rhs.x1 > rhs.x2)
	{
		double t(rhs.x1);
		rhs.x1 = rhs.x2;
		rhs.x2 = t;
	}
	if (rhs.y1 > rhs.y2)
	{
		double t(rhs.y1);
		rhs.y1 = rhs.y2;
		rhs.y2 = t;
	}
}

Rect2d::Rect2d(const double a1, const double b1, const double a2, const double b2): x1(a1), y1(b1), x2(a2), y2(b2) 
{
	if ((a1 == a2) || (b1 == b2))
	{
		// исключение
	}
	Rect2d::normaliz(*this);
}

Rect2d::Rect2d(const double a2, const double b2) : x1(0), y1(0), x2(a2), y2(b2) 
{
	Rect2d::normaliz(*this);
}


Rect2d& Rect2d::operator=(const Rect2d& rhs)
{
	x1 = rhs.x1;
	y1 = rhs.y1;
	x2 = rhs.x2;
	y2 = rhs.y2;
	return *this;
}


bool Rect2d::operator==(const Rect2d& rhs) const
{
	return ((x1 == rhs.x1) && (y1 == rhs.y1) && (x2 == rhs.x2) && (y2 == rhs.y2));
}

bool Rect2d::operator!=(const Rect2d& rhs) const
{
	return !(operator==(rhs));
}


double Rect2d::square()
{
	return ((x2 - x1) * (y2 - y1));
}


void Rect2d::peresech(const Rect2d& rhs)
{
	double a1(0.0);
	double b1(0.0);
	double a2(0.0);
	double b2(0.0);
	if ((rhs.x1 >= x1) && (rhs.x1 <= x2))
	{
		a1 = rhs.x1;
		if (rhs.x2 <= x2)
			a2 = rhs.x2;
		else
			a2 = x2;
	}
	else
	{
		if ((rhs.x2 >= x1) && (rhs.x2 <= x2))
		{
			a1 = x1;
			a2 = rhs.x2;
		}
	}

	if ((rhs.y1 >= y1) && (rhs.y1 <=y2))
	{
		b1 = rhs.y1;
		if (rhs.y2 <= y2)
			b2 = rhs.y2;
		else
			b2 = y2;
	}
	else
	{
		if ((rhs.y2 >= y1) && (rhs.y2 <= y2))
		{
			b1 = y1;
			b2 = rhs.y2;
		}
	}
	x1 = a1;
	y1 = b1;
	x2 = a2;
	y2 = b2;
}



ostream& Rect2d::writeTo(std::ostream& ostrm) const
{
	ostrm << sc << scob << x1 << separ << ' ' << y1 << scob2 << ' ' << scob << x2 << separ << ' ' << y2 << scob2 << s2;
	return ostrm;
}

istream& Rect2d::readFrom(std::istream& istrm)
{
	char sc('(');
	char sc2(')');
	char sep(',');
	double a1(0.0);
	double b1(0.0);
	double a2(0.0);
	double b2(0.0);
	istrm >> sc >> a1 >> sep >> b1 >> sc2 >> sc >> a2 >> sep >> b2 >> sc2;
	if (istrm.good())
	{
		if ((sc == Rect2d::scob) && (sc2 == Rect2d::scob2) && (sep == Rect2d::separ) )
		{
			if ((a1 == a2) || (b1 == b2))
				cout << "Error: Rectangle is degenerate \n";
			else
			{
				x1 = a1;
				y1 = b1;
				x2 = a2;
				y2 = b2;
			}
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);
		}
	}
	Rect2d::normaliz(*this);
	return istrm;
}



ostream& operator<<(std::ostream& ostrm, const Rect2d& rhs)
{
	return rhs.writeTo(ostrm);
}

istream& operator >> (std::istream& istrm, Rect2d& rhs)
{
	return rhs.readFrom(istrm);
}

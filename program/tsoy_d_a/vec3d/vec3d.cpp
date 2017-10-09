#include "vec3d.h"

using namespace std;

Vec3d& Vec3d::operator=(const Vec3d& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return *this;
}


bool Vec3d::operator==(const Vec3d& rhs)
{
	if ((x - rhs.x) < 1e-10 && (y - rhs.y) < 1e-10 && (z - rhs.z) < 1e-10)
		return true;
	else
		return false;
}


bool Vec3d::operator!=(const Vec3d& rhs)
{
	return !(operator==(rhs));
}


Vec3d& Vec3d::operator+=(const Vec3d& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}


Vec3d& Vec3d::operator-=(const Vec3d& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

Vec3d& Vec3d::operator*=(const double n)
{
	x *= n;
	y *= n;
	z *= n;
	return *this;
}


Vec3d& Vec3d::operator/=(const double n)
{
	x /= n;
	y /= n;
	z /= n;
	return *this;
}


Vec3d Vec3d::operator-() const // унарный минс
{
	Vec3d v = *this;
	v *= -1;
	return v;
}


double Vec3d::scal(const Vec3d& rhs)
{
	double s = x * rhs.x + y * rhs.y + z * rhs.z;
	return s;
}


Vec3d Vec3d::vec(const Vec3d& rhs)
{
	Vec3d v = Vec3d((y * rhs.z - z * rhs.y), (z * rhs.x - x * rhs.z), (x * rhs.y - y * rhs.x));
	return v;
}


double Vec3d::lenth()
{
	return sqrt(x * x + y * y + z * z);
}


ostream& Vec3d::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << probel << x << separator << probel << y << separator << probel << z << probel << rightBrace;
	return ostrm;
}


istream& Vec3d::readFrom(std::istream& istrm)
{
	char l(0);
	char s(0);
	char r(0);
	char p(0);
	double a(0.0);
	double b(0.0);
	double c(0.0);
	istrm >> l >> a >> s >> b >> s >> c >> r;
	if (istrm.good())
	{
		if ((l == leftBrace) && (s == separator) && (r == rightBrace))
		{
			x = a;
			y = b;
			z = c;
		}
		else
			istrm.setstate(std::ios_base::failbit);
	}
	return istrm;
}


Vec3d operator+(const Vec3d& lhs, const Vec3d& rhs)
{
	Vec3d v = lhs;
	v += rhs;
	return v;

}

Vec3d operator-(const Vec3d& lhs, const Vec3d& rhs)
{
	Vec3d v = lhs;
	v -= rhs;
	return v;

}

Vec3d operator*(const Vec3d& lhs, const double n)
{
	Vec3d v = lhs;
	v *= n;
	return v;
}

Vec3d operator/(const Vec3d& lhs, const double n)
{
	Vec3d v = lhs;
	v /= n;
	return v;
}


std::ostream& operator << (std::ostream& ostrm, const Vec3d& rhs)
{
	return rhs.writeTo(ostrm);
}

std::istream& operator >> (std::istream& istrm, Vec3d& rhs)
{
	return rhs.readFrom(istrm);
}
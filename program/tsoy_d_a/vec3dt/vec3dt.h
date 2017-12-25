#ifndef VEC3DT_H
#define VEC3DT_H

#include <iostream>
#include <sstream>

template <typename T>

struct Vec3dT
{
public:
	Vec3dT<T>() = default;
	~Vec3dT<T>() = default;
	Vec3dT<T>(const T a, const T b, const T c) : x(a), y(b), z(c) {}
	Vec3dT<T>(const Vec3dT<T>& rhs) = default;
	Vec3dT<T>& operator=(const Vec3dT<T>& rhs);
	bool operator==(const Vec3dT<T>& rhs);
	bool operator!=(const Vec3dT<T>& rhs);
	Vec3dT<T>& operator+=(const Vec3dT<T>& rhs);
	Vec3dT<T>& operator-=(const Vec3dT<T>& rhs);
	Vec3dT<T>& operator*=(const T n);
	Vec3dT<T>& operator/=(const T n);
	Vec3dT<T> operator-() const; // унарный минс
	bool compareTo(const Vec3dT<T>& rhs);
	double scal(const Vec3dT<T>& rhs);
	Vec3dT<T> vec(const Vec3dT<T>& rhs);
	double lenth();
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);
public:
	T x{ 0 };
	T y{ 0 };
	T z{ 0 };
	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};




	template <typename T>
	Vec3dT<T>& Vec3dT<T>::operator=(const Vec3dT<T>& rhs)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		return *this;
	}


	template <typename T>
	bool Vec3dT<T>::compareTo(const Vec3dT<T>& rhs)
	{
		if ((x == rhs.x) && (y == rhs.y) && (z == rhs.z))
			return true;
		else
			return false;
	}

	//template <>
	bool Vec3dT<double>::compareTo(const Vec3dT<double>& rhs)
	{
			const double e = 1e-10;
			if ((x - rhs.x) < e && (y - rhs.y) < e && (z - rhs.z) < e)
				return true;
			else
				return false;
	}

	//template <>
	bool Vec3dT<float>::compareTo(const Vec3dT<float>& rhs)
	{
		const float e = (float)1e-10;
		if ((x - rhs.x) < e && (y - rhs.y) < e && (z - rhs.z) < e)
			return true;
		else
			return false;
	}


	template <typename T>
	bool Vec3dT<T>::operator==(const Vec3dT<T>& rhs)
	{
		return compareTo(rhs);
	}


	template <typename T>
	bool Vec3dT<T>::operator!=(const Vec3dT<T>& rhs)
	{
		return !(operator==(rhs));
	}


	template <typename T>
	std::ostream& Vec3dT<T>::writeTo(std::ostream& ostrm) const
	{
		ostrm << leftBrace << " " << x << separator << " " << y << separator << " " << z << " " << rightBrace;
		return ostrm;
	}


	template <typename T>
	std::istream& Vec3dT<T>::readFrom(std::istream& istrm)
	{
		char l(0);
		char s(0);
		char r(0);
		double a(0);
		double b(0);
		double c(0);
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


	template <typename T>
	std::ostream& operator << (std::ostream& ostrm, const Vec3dT<T>& rhs)
	{
		return rhs.writeTo(ostrm);
	}


	template <typename T>
	std::istream& operator >> (std::istream& istrm, Vec3dT<T>& rhs)
	{
		return rhs.readFrom(istrm);
	}


	template <typename T>
	Vec3dT<T>& Vec3dT<T>::operator+=(const Vec3dT<T>& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}

	template <typename T>
	Vec3dT<T>& Vec3dT<T>::operator-=(const Vec3dT<T>& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}

	template <typename T>
	Vec3dT<T>& Vec3dT<T>::operator*=(const T n)
	{
		x *= n;
		y *= n;
		z *= n;
		return *this;
	}

	template <typename T>
	Vec3dT<T>& Vec3dT<T>::operator/=(const T n)
	{
		x /= n;
		y /= n;
		z /= n;
		return *this;
	}


	template <typename T>
	Vec3dT<T> Vec3dT<T>::operator-() const // унарный минс
	{
		Vec3dT<T> v = *this;
		v *= -1;
		return v;
	}


	template <typename T>
	double Vec3dT<T>::scal(const Vec3dT<T>& rhs)
	{
		double s = x * rhs.x + y * rhs.y + z * rhs.z;
		return s;
	}

	template <typename T>
	Vec3dT<T> Vec3dT<T>::vec(const Vec3dT<T>& rhs)
	{
		Vec3dT<T> v = Vec3dT<T>((y * rhs.z - z * rhs.y), (z * rhs.x - x * rhs.z), (x * rhs.y - y * rhs.x));
		return v;
	}

	template <typename T>
	double Vec3dT<T>::lenth()
	{
		return sqrt(x * x + y * y + z * z);
	}


	template <typename T>
	Vec3dT<T> operator+(const Vec3dT<T>& lhs, const Vec3dT<T>& rhs)
	{
		Vec3dT<T> v = lhs;
		v += rhs;
		return v;

	}

	template <typename T>
	Vec3dT<T> operator-(const Vec3dT<T>& lhs, const Vec3dT<T>& rhs)
	{
		Vec3d v = lhs;
		v -= rhs;
		return v;

	}

	template <typename T>
	Vec3dT<T> operator*(const Vec3dT<T>& lhs, const T n)
	{
		Vec3dT<T> v = lhs;
		v *= n;
		return v;
	}

	template <typename T>
	Vec3dT<T> operator/(const Vec3dT<T>& lhs, const T n)
	{
		Vec3dT<T> v = lhs;
		v /= n;
		return v;
	}

#endif
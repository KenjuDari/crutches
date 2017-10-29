#ifndef VEC3D_H
#define VEC3D_H

#include <iostream>
#include <sstream>

struct Vec3d
{
public:
	Vec3d() = default;
	~Vec3d() = default;
	Vec3d(const double a, const double b, const double c): x(a), y(b), z(c) {}
	Vec3d(const Vec3d& rhs) = default;
	Vec3d& operator=(const Vec3d& rhs);
	bool operator==(const Vec3d& rhs);
	bool operator!=(const Vec3d& rhs);
	Vec3d& operator+=(const Vec3d& rhs);
	Vec3d& operator-=(const Vec3d& rhs);
	Vec3d& operator*=(const double n);
	Vec3d& operator/=(const double n);
	Vec3d operator-() const; // унарный минс
	double scal(const Vec3d& rhs);
	Vec3d vec(const Vec3d& rhs);
	double lenth();
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);
public:
	double x{ 0.0 };
	double y{ 0.0 };
	double z{ 0.0 };
	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};

Vec3d operator+(const Vec3d& lhs, const Vec3d& rhs);
Vec3d operator-(const Vec3d& lhs, const Vec3d& rhs);
Vec3d operator*(const Vec3d& lhs, const double n);
Vec3d operator/(const Vec3d& lhs, const double n);


std::ostream& operator << (std::ostream& ostrm, const Vec3d& rhs);
std::istream& operator >> (std::istream& istrm, Vec3d& rhs);

#endif
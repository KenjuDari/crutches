#ifndef RECT2D_H
#define RECT2D_H

#include <iosfwd>

class Rect2d
{
public:
	Rect2d() = default;
	~Rect2d() = default;
	Rect2d(const double a1, const double b1, const double a2, const double b2);
	Rect2d(const double a2, const double b2);
	Rect2d(const Rect2d& rhs) = default;
	Rect2d& operator=(const Rect2d& rhs);
	bool operator==(const Rect2d& rhs) const;
	bool operator!=(const Rect2d& rhs) const;
    void peresech(const Rect2d& rhs);
	//static ... obedin(const Rect2d& rhs1, const Rect2d& rhs2);       Что возвращать? array[8,2]?
	//static ... razn(const Rect2d& rhs1, const Rect2d& rhs2);
	double square();
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

private:
	double x1{ 0.0 };
	double y1{ 0.0 };
	double x2{ 1.0 };
	double y2{ 1.0 };
	static const char sc{ '{' };
	static const char s2{ '}' };
	static const char scob{ '(' };
	static const char scob2{ ')' };
	static const char separ{ ',' };
	static void normaliz(Rect2d& rhs);
};

std::ostream& operator<<(std::ostream& ostrm, const Rect2d& rhs);
std::istream& operator >> (std::istream& istrm, Rect2d& rhs);

#endif 

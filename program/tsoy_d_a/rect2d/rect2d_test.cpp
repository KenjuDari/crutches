#include"rect2d.h"

#include<iostream>
#include<sstream>

using namespace std;

int main()
{
	cout << "constructor without paramentrs: r1";
	Rect2d r1;
	cout << r1 << "\n";
	cout << "constructor with 4 paramentrs: r2";
	Rect2d r2(-1, 0, -6, 4);
	cout << r2 << "\n";
	cout << "constructor with 2 paramentrs: r3";
	Rect2d r3(2.2, 7);
	cout << r3 << "\n";
	cout << "copy constructor paramentrs: r4(r1)";
	Rect2d r4(r1);
	cout << r4 << "\n";
	cout << "operator= for r4=r2: ";
	r4 = r2;
	cout << r4 << "\n";
	cout << "\n";
	cout << "square r4 = " << r2.square() << "\n";
	cout << "peresech r1 and r3: " << Rect2d::peresech(r1, r3); // почему выводит в экспоненциальной форме?
	Rect2d test = Rect2d::peresech(r1, r3);
	cout << "\n" << test;

	return 0;
};
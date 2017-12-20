#include"rect2d.h"

#include<iostream>
#include<sstream>

using namespace std;

int main()
{
	cout << "constructor without paramentrs: r1";
	Rect2d r1;
	cout << r1 << endl;
	cout << "constructor with 4 paramentrs: r2";
	Rect2d r2(-1, 0, -6, 4);
	cout << r2 << endl;
	cout << "constructor with 2 paramentrs: r3";
	Rect2d r3(2.2, 7);
	cout << r3 << endl;
	cout << "copy constructor paramentrs: r4(r1)";
	Rect2d r4(r1);
	cout << r4 << endl;
	cout << "operator= for r4=r2: ";
	r4 = r2;
	cout << r4 << endl;
	cout << endl;
	cout << "square r4 = " << r4.square() << endl;
	r1.peresech(r3);
	cout << "peresech r1 and r3: " << r1; // почему выводит в экспоненциальной форме?

	return 0;
};
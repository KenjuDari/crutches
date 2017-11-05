#include "matrixU.h"
#include <iostream>

int main()
{
	MatrixU m;
	cout << "Constructor without params: " << "(Row = " << m.Row() << " and Col = " << m.Col() << ')' << endl;
	cout << m;
	MatrixU m2(3, 4);
	m2.at(0, 0) = 111;
	m2.at(1, 1) = 222;
	m2.at(2, 2) = 333;
	m2.at(2, 3) = 666;
	cout << "Constructor with params and add some elements:" << endl;
	cout << m2;
	const MatrixU mConst(m2);
	cout << "element from const MatrixU = " << mConst.at(2, 2) << endl;
	mConst.~MatrixU();
	cout << mConst << endl;
	MatrixU m3(m2);
	cout << "Copy constructor:" << endl;
	cout << m3;
	MatrixU m4(3,2);
	m4.at(0, 1) = -2;
	m4.at(1, 0) = 33;
	m4.at(2, 1) = -123;
	m3 = m4;
	cout << m3;
	cout << "m3 == m4 is " << (m3 == m4) << endl;
	m3.at(0, 0) = 9;
	cout << "m3 == m4 is " << (m3 == m4) << endl;
	cout << "m4:" << endl;
	cout << m4;
	m4.resize(4, 5);
	cout << "after resize(4, 5):" << endl;
	cout << m4;
	m4.resize(2, 2);
	cout << "after resize(2, 2):" << endl;
	cout << m4;
	return 0;
}
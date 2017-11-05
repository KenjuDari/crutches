#include "matrixR.h"

#include <iostream>

int main() 
{
	MatrixR m(2, 3);
	for (int i(0); i < 2 * 3; i++)
		m.at(i / 3, i % 3) = i;
	cout << m << endl;
	cout << m.lenth() << endl;
	m.~MatrixR();
	cout << m << endl;
	MatrixR m2(3, 3);
	m2.at(0, 0) = 10;
	m2.at(0, 2) = 0;
	m2.at(1, 0) = -2;
	m2.at(1, 1) = 5;
	m2.at(1, 2) = 6;
	MatrixR m3(1,1);
	m3 = m2;
	cout << "operator =  " << endl;
	cout << m3 << endl;
	MatrixR m4(m3);
	cout << m4 << endl;
	cout << "m3 == m4 is " << (m3 == m4) << endl;
	//cout << "m4:" << endl;
	//cout << m4;
	//m4.resize(4, 5);
	//cout << "after resize(4, 5):" << endl;
	//cout << m4;
	//m4.resize(1, 2);
	//cout << "after resize(2, 2):" << endl;
	//cout << m4;
	try
	{
		MatrixR m2(-1, 1);
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	catch (length_error& e)
	{
		cout << e.what() << endl;
	}
	catch (out_of_range& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown; try else:" << endl;
		throw;
	}

	//try
	//{
	//	int n = m.at(0, 1);
	//}
	//catch (invalid_argument& e)
	//{
	//	cout << e.what() << endl;
	//}
	//catch (length_error& e)
	//{
	//	cout << e.what() << endl;
	//}
	//catch (out_of_range& e)
	//{
	//	cout << e.what() << endl;
	//}
	//catch (...)
	//{
	//	cout << "Unknown; try else:" << endl;
	//	throw;
	//}

	return 0;
};
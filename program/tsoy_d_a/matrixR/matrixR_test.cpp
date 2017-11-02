#include "matrixR.h"

#include <iostream>

int main() 
{
	MatrixR m(2, 3);
	m.at(0, 0) = 1;
	m.at(0, 1) = 2;
	m.at(0, 2) = 3;
	m.at(1, 0) = 4;
	m.at(1, 1) = 5;
	m.at(1, 2) = 6;
	cout << m << endl;
	cout << m.lenth() << endl;
	m.~MatrixR();
	cout << m << endl;

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

	try
	{
		int n = m.at(0, 1);
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

	return 0;
};
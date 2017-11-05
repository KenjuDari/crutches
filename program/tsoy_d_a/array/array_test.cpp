#include "array.h"

#include <iostream>

int main()
{
	Array n;
	cout << "Default constructor: " << n << ' ';;
	cout << "Size of default array: " << n.lenth() << endl;
	Array n2(6);
	n2[0] = 6;
	n2[2] = 8;
	n2[3] = -1;
	n2[5] = 100;
	cout << "Array with elements: " << n2 << endl;
	Array copyN2(n2);
	cout << "Copy constructor: " << copyN2 << "Lenth: " << copyN2.lenth() << " Physical size: " << copyN2.physicalLenth() << endl;
	const Array constArray(n2);
	int test = constArray[0];
	cout << "element from const Array = " << test << endl;
	copyN2.~Array();
	cout << copyN2 << endl;
	Array n3;
	n3[0] = 1;
	n3[2] = 2;
	n3[3] = 3;
	cout << "n2: " << n2 << endl;
	cout << "n3: " << n3 << endl;
	n3 = n2;
	cout << "Array with help operator =: " << n3 << endl;
	n2.resize(8);
	cout << "resize 6 -> 8: " << n2 << " Size " << n2.lenth() << " Physical size " << n2.physicalLenth() << endl;
	n2.resize(3);
	cout << "resize 8 -> 3: " << n2 << " Size " << n2.lenth() << " Physical size " << n2.physicalLenth() << endl;
	n2.resize(15);
	cout << "resize 3 -> 15 (> physical size): " << n2 << " Size " << n2.lenth() << " Physical size " << n2.physicalLenth() << endl;
	Array n4(6);
	n4[0] = 1;
	n4[2] = 2;
	n4[3] = 3;
	n4.insert(666, 4);
	cout << "Insert in array[4]" <<  n4 << " Size " << n4.lenth() << " Physical size " << n4.physicalLenth() << endl;
	int razn (n4.physicalLenth() - n4.lenth());
	for (int i(0); i < razn; i++)
		n4.insert(i, 4);
	cout << "After " << razn << " inserts " << n4 << " Size " << n4.lenth() << " Physical size " << n4.physicalLenth() << endl;
	n4.insert(222, 4);
	cout << "Anoher one insert " << n4 << " Size " << n4.lenth() << " Physical size " << n4.physicalLenth() << endl;
	n4.remove(n4.lenth() - 1);
	cout << "Remove last element: " << n4 << " Size " << n4.lenth() << " Physical size " << n4.physicalLenth() << endl;
	n4.remove(3);
	cout << "Remove 4 element: " << n4 << " Size " << n4.lenth() << " Physical size " << n4.physicalLenth() << endl;
	 
	Array n5 = n4;
	cout << "n4 == n5 " << (n4 == n5) << endl;
	cout << "n2 == n5 " << (n2 == n5) << endl;

	//cout << "n2: " << n2 << endl;
	//cout << "n3: " << n3 << endl;
	//n2 = n3;
	//cout << "n2: " << n2 << endl;

	try
	{
		Array error1(-5);
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
		Array error2(0);
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
		Array error3(3);
		error3.resize(-9);
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
		Array error3(3);
		error3.insert(0, 4);
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
		Array error4(3);
		error4.remove(3);
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
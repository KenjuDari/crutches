#include "stackL.h"
#include <iostream>

using namespace std;

int main()
{
	StackL s;
	s.push(5);
	s.push(66);
	s.push(8);
	cout << "Untwisting stack:" << endl;
	cout << s << endl;
	s.pop();
	cout << "Untwisting this stack after pop:" << endl;
	cout << s << endl;
	cout << "IsEmpty: " << s.isEmpty() << endl;
	StackL s2(s);
	s.~StackL();
	cout << "IsEmpty after destructor: " << s.isEmpty() << endl;
	cout << "Copy costructor: " << endl;
	cout << s2 << endl;
	s2.top() = 10101;
	cout << "Change top: " << s2.top() << endl;

	try
	{
		cout << s.top();
	}
	catch (invalid_argument& e)
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
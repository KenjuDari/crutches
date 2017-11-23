#include "priorityQueueL.h"
#include <iostream>

using namespace std;

int main()
{
	PriorityQueueL p;
	cout << p << endl;
	p.push(77);
	p.push(33);
	p.push(-3);
	cout << "Queue p after add 77, 33, -3:" << endl << p << endl;
	p.pop();
	cout << "p after pop:" << endl << p << endl;
	PriorityQueueL p2(p);
	cout << "p2(p):" << endl << p2 << endl;
	p2.push(0);
	p2.push(990);
	cout << "p2:" << endl << p2 << endl;
	p = p2;
	cout << "p = p2:" << endl << p << endl;
	PriorityQueueL p3;
	p3.push(123);
	cout << "p3:" << endl << p3 << endl;
	p2 = p3;
	cout << "p2 = p3:" << endl << p2 << endl;
	p3.push(876);
	p3.push(456);
	p3.push(0);
	p3.push(44);
	cout << "p3:" << endl << p3 << endl;
	p = p3;
	cout << "p = p3:" << endl << p << endl;
	p3.~PriorityQueueL();
	cout << "p3 after destructor: " << endl << p3 << endl;

	try
	{
		p3.bot();
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Unknow error, try else:" << endl;
		throw;
	}
	return 0;
}
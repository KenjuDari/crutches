#include "priorityQueueL.h"
#include <iostream>

using namespace std;

int main()
{
	PriorityQueueL p;
	p.push(77);
	p.push(33);
	PriorityQueueL p2(p);
	cout << p;
	cout << p2;
	return 0;
}
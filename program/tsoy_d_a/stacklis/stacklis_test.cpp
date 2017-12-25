#include "stacklis.h"
#include <iostream>

using namespace std;

int main()
{
	StackLis testData;
	testData.push(2);
	testData.push(-8);
	testData.push(0);
	testData.push(666);


	StackLis stEmpty;
	cout << "Do writePop for stEmpty without push" << endl;
	cout << stEmpty << endl;
	cout << endl;


	cout << "Try to do top for stEmpty" << endl;
	try
	{
		cout << stEmpty.top();
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
	cout << endl;


	StackLis stTest(testData);
	cout << "Do 5 writePop for stTest that had push: 2, 8, 0, 666 " << endl;
	cout << stTest << endl;
	cout << stTest << endl;
	cout << stTest << endl;
	cout << stTest << endl;
	cout << stTest << endl;
	cout << endl;


	cout << "Do writePop for stCopy by copy constructor from testData" << endl;
	StackLis stCopy(testData);
	cout << stCopy << endl;
	cout << stCopy << endl;
	cout << stCopy << endl;
	cout << stCopy << endl;
	cout << stCopy << endl;
	cout << endl;


	cout << "Do writePop for stEmptyCopy by copy constructor from stEmpty" << endl;
	StackLis stEmptyCopy(stEmpty);
	cout << stEmptyCopy << endl;
	cout << endl;


	cout << "Do writePop for stCopyEmpty by operator= from testData " << endl;
	StackLis stCopyEmpty;
	stCopyEmpty = testData;
	cout << stCopyEmpty << endl;
	cout << stCopyEmpty << endl;
	cout << stCopyEmpty << endl;
	cout << stCopyEmpty << endl;
	cout << stCopyEmpty << endl;
	cout << endl;


	cout << "Do writePop for stFullCopy by operator= from stEmpty " << endl;
	StackLis stFullCopy;
	stFullCopy.push(4);
	stFullCopy.push(365);
	stFullCopy.push(-2);
	stFullCopy = stEmpty;
	cout << stFullCopy << endl;
	cout << endl;


	cout << "Do writePop for stCopyEqual by operator= from testData where lenth of stCopyEqual was equal to lenth of testData" << endl;
	StackLis stCopyEqual;
	stCopyEqual.push(111);
	stCopyEqual.push(789);
	stCopyEqual.push(79);
	stCopyEqual.push(89);
	stCopyEqual.push(0);
	stCopyEqual = testData;
	cout << stCopyEqual << endl;
	cout << stCopyEqual << endl;
	cout << stCopyEqual << endl;
	cout << stCopyEqual << endl;
	cout << stCopyEqual << endl;
	cout << endl;


	cout << "Do writePop for stCopyLess by operator= from testData where lenth of stCopyLess was less" << endl;
	StackLis stCopyLess;
	stCopyLess.push(111);
	stCopyLess.push(789);
	stCopyLess = testData;
	cout << stCopyLess << endl;
	cout << stCopyLess << endl;
	cout << stCopyLess << endl;
	cout << stCopyLess << endl;
	cout << stCopyLess << endl;
	cout << endl;


	cout << "Do writePop for stCopyMore by operator= from testData where lenth of stCopyMore was more" << endl;
	StackLis stCopyMore;
	stCopyMore.push(111);
	stCopyMore.push(789);
	stCopyMore.push(79);
	stCopyMore.push(89);
	stCopyMore.push(0);
	stCopyMore.push(4);
	stCopyMore = testData;
	cout << stCopyMore << endl;
	cout << stCopyMore << endl;
	cout << stCopyMore << endl;
	cout << stCopyMore << endl;
	cout << stCopyMore << endl;
	cout << endl;


	return 0;
}
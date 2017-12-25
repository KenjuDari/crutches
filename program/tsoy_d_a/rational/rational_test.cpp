#include "rational.h"
#include <iostream>
#include <sstream>
#include <string>

bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Rational z;
	istrm >> z;
	if (istrm.good()) {
		cout << "Read success: " << str << " -> " << z << endl;

	}
	else {
		cout << "Read error : " << str << " -> " << z << endl;

	}
	return istrm.good();
}

int main()
{
	using namespace std;

	bool test = 0;
	cout << test << endl;
	test = !test;
	cout << test << endl;
	return 0;
}
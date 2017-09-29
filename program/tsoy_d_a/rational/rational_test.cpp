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
	Rational z(9, 15);
	cout << z << " + ";
	Rational z2(3, 3);
	cout << z2 << " = ";
	z += z2;
	cout << z;
	cout << "\n" << z << " * ";
	z2 = Rational(1, 2);
	cout << z2 << " = ";
	z *= z2;
	cout << z << "\n";
	cout << z << " / " << z2 << " = ";
	z /= z2;
	cout << z << "\n";
	//cout << "-" << z << " = " << -z;
	cout << z << "\n";
	if (z == z2)
		cout << z << " = " << z2 << "\n";
	else
		cout << z << " != " << z2 << "\n";
	z2 = z;
	if (z == z2)
		cout << z << " = " << z2 << "\n";
	else
		cout << z << " != " << z2 << "\n";

	testParse("2/");
	testParse("2/5");
	testParse("3/pp5");
	testParse("4 / 6   ");
	testParse("4 / 6   rrr");
	return 0;
}
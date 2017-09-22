#include "complex.h"

#include <iostream>
#include <sstream>

using namespace std;

bool testParse(const std::string& str)
{
	istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good()) {
		cout << "Read success: " << str << " -> " << z << endl;
	} else {
		cout << "Read error : " << str << " -> " << z << endl;
	}
	return istrm.good();
}

int main()
{
	Complex z;
	z += Complex(8.0);
	cout << z;
	z -= 2;
	z.writeTo(cout);
	cout << "\n";
	Complex z2(2);
	cout << z2 << "^" << 3 << " = " << Complex::pov(z2, 3) << "\n";
	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9,9");	testParse("{8.9, fff 5}");	cout << "\n";
	cout << Complex(4) << " * " << Complex(5, 6) << " = ";
	cout << (Complex(4) *= Complex(5, 6));
	return 0;
}
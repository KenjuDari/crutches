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
	}
	else {
		cout << "Read error : " << str << " -> " << z << endl;
	}
	return istrm.good();
}

int main()
{
	Complex z0;
	cout << "Empty constructor: " << z0 << "\n";
    Complex z(-5);
	cout << "Constructor wuth 1 param: " << z << "\n";
	z = Complex(2, 7);
	cout << "Constructor wuth 2 param: " << z << "\n";
	Complex z2 = z;

	cout << z << " == " << z2;
	if (z == z2)
		cout << " true" << "\n";
	else
		cout << " false" << "\n";
	cout << z << " != " << z2;
	if (z != z2)
		cout << " true" << "\n";
	else
		cout << " false" << "\n";
	z2 = Complex(-3, 8);
	cout << z << " += " << z2 << "  result z = ";
	z += z2;
	cout << z << "\n";
	cout << z << " -= " << z2 << "  result z = ";
	z -= z2;
	cout << z << "\n";
	cout << z << " *= " << "5" << "  result z = ";
	z *= 5;
	cout << z << "\n";
	cout << z << " / " << z2 << " = ";
	z = z / z2;
	cout << z << "\n";
	cout << "z2 = " << z2 << "  -z2 = " << -z2 << "\n";
	z = 5;
	cout << "z = " << z << "  z^3 = " << Complex::pov(z, 3) << "\n";
	cout << "z2 = " << z2 << "  sopr for z2 = " << Complex::sopr(z2) << "\n";

	cout << z << " + int 7 = " << (z + 7) << "\n";
	cout << "int 3 / " << z << "  = " << (3 / z) << "\n";

	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9,9");
	testParse("{8.9, fff 5}");
	cout << "\n";
	return 0;
}
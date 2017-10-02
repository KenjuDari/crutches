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

	Rational z = Rational();
	cout << "Empty constructor: " << z << "\n";
	z = Rational(-5);
	cout << "Constructor wuth 1 param (-5): " << z << "\n";
	z = Rational(-2, -10);
	cout << "Constructor wuth 2 param (-2, -10): " << z << "\n";
	Rational z2 = Rational(-6, -30);


	cout << "z(-2, -10)" << " == " << "z2(-6, -30)";
	if (z == z2)
		cout << " true" << "\n";
	else
		cout << " false" << "\n";


	cout << z << " != " << z2;
	if (z != z2)
		cout << " true" << "\n";
	else
		cout << " false" << "\n";	
	
	z2 = Rational(1, 4);
	cout << z << " <= " << z2;
	if (z <= z2)
		cout << " true" << "\n";
	else
		cout << " false" << "\n";
	cout << z << " > " << z2;
	if (z > z2)
		cout << " true" << "\n";
	else
		cout << " false" << "\n";


	cout << z << " += " << z2 << "  result z = ";
	z += z2;
	cout << z << "\n";
	cout << z << " - " << z2 << " = ";
	cout << (z - z2) << "\n";
	cout << z << " *= " << "5" << "  result z = ";
	z *= 5;
	cout << z << "\n";
	cout << z << " / " << z2 << " = ";
	z = z / z2;
	cout << z << "\n";

	z2 = Rational(4, -9);
	cout << "z2 = " << z2 << "  -z2 = " << -z2 << "\n";
	cout << "z = " << z << "  z^3 = " << Rational::pov(z, 3) << "\n";

	cout << z << " + int 7 = " << (z + 7) << "\n";
	cout << "int 3 / "<< z << "  = " << (3 / z) << "\n";

	testParse("2/");
	testParse("2/5");
	testParse("3/pp5");
	testParse("4 / 6   ");
	testParse("4 / 6   rrr");
	return 0;
}
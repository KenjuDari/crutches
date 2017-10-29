#include "vec3d.h"

#include <iostream>
#include <sstream>

using namespace std;

bool testParse(const std::string& str)
{
	istringstream istrm(str);
	Vec3d z;
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
	Vec3d z;
	cout << "Empty constructor: z = " << z << "\n";
	Vec3d z(-5, 0, 1.1);
	cout << "Constructor wuth 3 param: z = " << z << "\n";
	Vec3d z2(z);
	cout << "Constructor copy: z2(z) = " << z << "\n";
	Vec3d z3 = z;
	cout << "\n" << " z3 = z2 \n";
	cout << z3 << "(z3) == " << z2 << "(z2)";
	if (z3 == z2)
		cout << " true" << "\n";
	else
		cout << " false" << "\n";
	cout << z3 << " != " << z2;
	if (z3 != z2)
		cout << " true" << "\n";
	else
		cout << " false" << "\n";
	z2 = Vec3d(-3, 1, 0);
	cout << z << " += " << z2 << "  result z = ";
	z += z2;
	cout << z << "\n";
	cout << z << " -= " << z2 << "  result z = ";
	z -= z2;
	cout << z << "\n";
	cout << z << " *= " << "5" << "  result z = ";
	z *= 5;
	cout << z << "\n";
	cout << z << " / " << "5" << " = ";
	z = z / 5;
	cout << z << "\n";
	cout << "z2 = " << z2 << "  -z2 = " << -z2 << "\n";
	cout << "z2 = " << z2 << "  lenth = " << z2.lenth() << "\n";

	cout << "z = " << z << "  z2 = " << z2 << "  z * z2 = " << z.scal(z2) << "\n";
	cout << "[z, z2] = " << z.vec(z2) << "\n";

	testParse("{1,2,3}");
	testParse("{ 0.0, 2, 3 }");
	testParse("{ 1, 2, 3.3 }");
	testParse("{      1  2  , 3     }");
	testParse("1, 2, 3 }");
	testParse("{ 1, 2, 3");

	return 0;
};
#include "vec3dT.h"

#include <iostream>
#include <sstream>

using namespace std;

//template <typename T>
//bool testParse<T>(const std::string& str)
//{
//	istringstream istrm(str);
//	Vec3dT<T> z;
//	istrm >> z;
//	if (istrm.good()) {
//		cout << "Read success: " << str << " -> " << z << endl;
//	}
//	else {
//		cout << "Read error : " << str << " -> " << z << endl;
//	}
//	return istrm.good();
//}


int main()
{

	Vec3dT<double> z = Vec3dT<double>();
	cout << "Empty constructor: z = " << z << "\n";
	Vec3dT<double> z2(-5, 0, 1.1);
	cout << "Constructor wuth 3 param: z2 = " << z2 << "\n";
	Vec3dT<double> z3(z2);
	cout << "Constructor copy: z3(z2) = " << z3 << "\n";
	z3 = Vec3dT<double>(0, 2, 3.0);


	cout << "\n" << " z3 = " << z3 << "   z2 = " << z2 <<  "  (double) \n";
	cout << "z3 == z2 ";
	if (z3 == z2)
		cout << " true" << "\n";
	else
		cout << " false" << "\n";
	cout << " z3 != z2 ";
	if (z3 != z2)
		cout << " true" << "\n";
	else
		cout << " false" << "\n";
	cout << "\n";


	Vec3dT<float> z20(-5, 0, 1.1);
	Vec3dT<float> z30(-7.1, 1.1, 1.1);
	cout << "\n" << " z30 = " << z30 << "   z20 = " << z20 << "  (float) \n";
	cout << "z30 == z20 ";
	if (z30 == z20)
		cout << " true" << "\n";
	else
		cout << " false" << "\n";
	cout << " z30 != z20 ";
	if (z30 != z20)
		cout << " true" << "\n";
	else
		cout << " false" << "\n";

	cout << "\n";

	cout << z << " += " << z2 << "  result z = ";
	z += z2;
	cout << z << "\n";
	cout << z << " -= " << z2 << "  result z = ";
	z -= z2;
	cout << z << "\n";
	cout << "\n";
	cout << z3 << " *= " << "5" << "  result z = ";
	z3 *= 5;
	cout << z3 << "\n";
	cout << z3 << " / " << "5" << " = ";
	z3 = z3 / 5.0;
	cout << z3 << "\n";
	cout << "\n";
	cout << "z2 = " << z2 << "  -z2 = " << -z2 << "\n";
	cout << "z2 = " << z2 << "  lenth = " << z2.lenth() << "\n";

	cout << "z3 = " << z3 << "  z2 = " << z2 << "  z3 * z2 = " << z3.scal(z2) << "\n";
	cout << "[z3, z2] = " << z3.vec(z2) << "\n";
	cout << "\n" << "\n" << "\n";


	Vec3dT<int> n(12, 0, -1);
	Vec3dT<int> n2(-1, 0, -9);
	cout << "\n" << " n = " << n << "   n2 = " << n2 << "  (int) \n";
	cout << "n == n2 ";
	if (n == n2)
		cout << " true" << "\n";
	else
		cout << " false" << "\n";
	cout << " n != n2 ";
	if (n != n2)
		cout << " true" << "\n";
	else
		cout << " false" << "\n";
	cout << "n == n ";
	if (n == n)
		cout << " true" << "\n";
	else
		cout << " false" << "\n";
	cout << "\n";


	cout << n << " += " << n2 << "  result z = ";
	n += n2;
	cout << n << "\n";
	cout << n << " -= " << n2 << "  result z = ";
	n -= n2;
	cout << n << "\n";
	cout << "\n";
	cout << n << " *= " << "5" << "  result z = ";
	n *= 5;
	cout << n << "\n";
	cout << n << " / " << "5" << " = ";
	n = n / 5;
	cout << n << "\n";
	cout << "\n";
	cout << "n = " << n << "  -n = " << -n << "\n";
	cout << "n = " << n << "  lenth = " << n.lenth() << "\n";

	cout << "n = " << n << "  n2 = " << n2 << "  n * n2 = " << n.scal(n2) << "\n";
	cout << "[n, n2] = " << n.vec(n2) << "\n";
	cout << "\n";

	//testParse<int>("{1,2,3}");
	//testParse<double>("{ 0.0, 2, 3 }");
	//testParse<double>("{ 1, 2, 3.3 }");
	//testParse<double>("{      1  2  , 3     }");
	//testParse<double>("1, 2, 3 }");
	//testParse<double>("{ 1, 2, 3");

	return 0;
}
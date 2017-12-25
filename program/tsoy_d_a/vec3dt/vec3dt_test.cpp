#include "vec3dt.h"

#include <iostream>
#include <sstream>
#include <typeinfo.h>


using namespace std;

int main()
{

	Vec3dT<double> z;
	cout << "Empty constructor<double>: z = " << z << endl;
	Vec3dT<double> z2(-5, 0, 1.1);
	cout << "Constructor wuth 3 param<double>: z2 = " << z2 << endl;
	Vec3dT<double> z3(z2);
	cout << "Constructor copy<double>: z3(z2) = " << z3 << endl;
	z3 = Vec3dT<double>(0, 2, 3.0);


	cout << endl << " z3 = " << z3 << "   z2 = " << z2 <<  "  (double)" << endl;
	cout << "z3 == z2 ";
	if (z3 == z2)
		cout << " true" << endl;
	else
		cout << " false" << endl;
	cout << " z3 != z2 ";
	if (z3 != z2)
		cout << " true" << endl;
	else
		cout << " false" << endl;
	cout << endl;


	Vec3dT<float> z20(-5, 0, 1.1);
	Vec3dT<float> z30(-7.1, 1.1, 1.1);
	cout << endl << " z30 <float> = " << z30 << "   z20 <float> = " << z20  << endl;
	cout << "z30 == z20 ";
	if (z30 == z20)
		cout << " true" << endl;
	else
		cout << " false" << endl;
	cout << " z30 != z20 ";
	if (z30 != z20)
		cout << " true" << endl;
	else
		cout << " false" << endl;

	cout << endl;

	cout << z << " += " << z2 << "  result z = ";
	z += z2;
	cout << z << endl;
	cout << z << " -= " << z2 << "  result z = ";
	z -= z2;
	cout << z << endl;
	cout << endl;
	cout << z3 << " *= " << "5" << "  result z = ";
	z3 *= 5;
	cout << z3 << endl;
	cout << z3 << " / " << "5" << " = ";
	z3 = z3 / 5.0;
	cout << z3 << endl;
	cout << endl;
	cout << "z2 = " << z2 << "  -z2 = " << -z2 << endl;
	cout << "z2 = " << z2 << "  lenth = " << z2.lenth() << endl;

	cout << "z3 = " << z3 << "  z2 = " << z2 << "  z3 * z2 = " << z3.scal(z2) << endl;
	cout << "[z3, z2] = " << z3.vec(z2) << endl;
	cout << endl << endl << endl;


	Vec3dT<int> n(12, 0, -1);
	Vec3dT<int> n2(-1, 0, -9);
	cout << endl << " n<int> = " << n << "   n2<int> = " << n2 << endl;
	cout << "n == n2 ";
	if (n == n2)
		cout << " true" << endl;
	else
		cout << " false" << endl;
	cout << " n != n2 ";
	if (n != n2)
		cout << " true" << endl;
	else
		cout << " false" << endl;
	cout << "n == n ";
	if (n == n)
		cout << " true" << endl;
	else
		cout << " false" << endl;
	cout << endl;


	cout << n << " += " << n2 << "  result z = ";
	n += n2;
	cout << n << endl;
	cout << n << " -= " << n2 << "  result z = ";
	n -= n2;
	cout << n << endl;
	cout << endl;
	cout << n << " *= " << "5" << "  result z = ";
	n *= 5;
	cout << n << endl;
	cout << n << " / " << "5" << " = ";
	n = n / 5;
	cout << n << endl;
	cout << endl;
	cout << "n = " << n << "  -n = " << -n << endl;
	cout << "n = " << n << "  lenth = " << n.lenth() << endl;

	cout << "n = " << n << "  n2 = " << n2 << "  n * n2 = " << n.scal(n2) << endl;
	cout << "[n, n2] = " << n.vec(n2) << endl;
	cout << endl;

	cout << endl;

	return 0;
}
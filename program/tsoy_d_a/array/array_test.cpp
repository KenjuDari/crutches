#include "array.h"

#include <iostream>
#include <stdexcept>

using namespace std;
enum testEnum {r = 23, s = 20};

int main()
{
	testEnum t = testEnum::s;
	testEnum t2 = testEnum::r;
	cout << t2 % t << endl;

	return 0;
};
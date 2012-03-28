/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 5 exercise 4
	Page 168
*/
#include "std_lib_facilities.h"

double ctok(double c)	// converts Celsius to Kelvin
{
	const double min_c = -273.15;
	if (c < min_c) error("The lowest temperature that can be reached is: -273.15 Celsius.\n");
	
	const double kelvin_factor = 273.15;
	double k = c + kelvin_factor;

	return k;
}

int main()
{
	double c = 0;
	cin >> c;
	double k = ctok(c);
	cout << k << endl;

	return 0;
}

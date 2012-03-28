/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 5 exercise 2
	Page 167
*/
#include "std_lib_facilities.h"

double ctok(double c)	// converts Celsius to Kelvin
{
	//Error #0, integer division. Meaningless magic constant.
	//int k = c + 273.15;
	const double kelvin_factor = 273.15;
	double k = c + kelvin_factor;

	//Error #1, we want to return k.
	//return int;
	return k;
}

int main()
{
	double c = 0;
	//Error #2, d was never declared.
	//cin >> d;	 
	cin >> c;

	//Error #3, ctok() accepts an argument of type double not string.
	//double k = ctok("c");
	double k = ctok(c);

	//Error #4, Cout object never declared.
	//Cout << k << endl;
	cout << k << endl;

	return 0;	//Error #5, no return value specified.
}

/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 5 exercise 5
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

double ktoc(double k) // converts Kelvin to Celsius
{
	const double min_k = 0;
	if (k < min_k) error("The lowest temperature that can be reached is: 0 Kelvin.\n");

	const double cels_factor = 273.15;
	double c = k - cels_factor;

	return c;
}

int main()
{
	try {
		cout << "This program can convert Celsius to Kelvin and Kelvin to Celsius.\n";
		cout << "To convert Celsius to Kelvin type in: 45c or vice-versa 45k.\n";
		double temp = 0;
		string temp_type;
		cin >> temp >> temp_type;

		if (temp_type == "c") { 
			double k = ctok(temp);
			cout << k << endl;
		}
		else if (temp_type == "k") {
			double c = ktoc(temp);
			cout << c << endl;
		}
		else {
			cerr << "Invalid input.\n";
			return 1;
		}
	}
	catch(runtime_error e) {
		cerr << e.what();
	}
	return 0;
}

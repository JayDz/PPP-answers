/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 5 exercise 6
	Page 168
*/
#include "std_lib_facilities.h"

double ctof(double celsius)
	// converts celsius to fahrenheit
	// pre-condition: celsius must not be less than absolute zero: -273.15
	// post-condition: return value will contain the fahrenheit equivalent of celsius.
{
	const double min_c = -273.15;
	if (celsius < min_c) error("Lowest possible value for celsius is -273.15.");

	double f = celsius * 1.8 + 32;
	return f;
}

double ftoc(double fahrenheit)
	// converts fahrenheit to celsius
	// pre-condition: fahrenheit must not be less than absolute zero: -459.67
	// post-condition: return value will contain the celsius equivalent of fahrenheit.
{
	const double min_f = -459.67;
	if (fahrenheit < min_f) error("Lowest possible value for fahrenheit is -459.67.");

	double c = (fahrenheit - 32) / 1.8;
	return c;
}

int main()
{
	cout << "This program can convert Celsius to Fahrenheit and vice-versa.\n";
	cout << "To convert fahrenheit to celsius type in: 45f or 45c for celsius to fahrenheit.\n";
	double temp;
	string temp_type;
	cin >> temp >> temp_type;

	if (temp_type == "c") {
		double f = ctof(temp);
		cout << "The fahrenheit equivalent of " << temp << " celsius is: " << f << endl;
	}
	else if (temp_type == "f") {
		double c = ftoc(temp);
		cout << "The celsius equivalent of " << temp << " fahrenheit is: " << c << endl;
	}
	else {
		cerr << "Invalid input.\n";
		return 1;
	}

	return 0;
}

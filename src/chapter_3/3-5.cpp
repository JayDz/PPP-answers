/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 3, exercise 5
	Page 85
*/
#include "std_lib_facilities.h"

int main()
{
	cout << "Enter two floating-point values: ";
	double val1;
	double val2;
	cin >> val1 >> val2;

	double smallest;
	double largest;
	if (val1 > val2){
		largest  = val1;
		smallest = val2;
	}else {
		largest  = val2;
		smallest = val1;
	}

	double sum        = val1 + val2;
	double difference = val1 - val2;
	double product    = val1 * val2;
	double ratio      = val1 / val2; // Ratio will not be truncated.

	cout << "\nThe smallest is: "   << smallest;
	cout << "\nThe largest is: "    << largest;
	cout << "\nThe sum is: "        << sum;
	cout << "\nThe difference is: " << difference;
	cout << "\nThe product is: "    << product;
	cout << "\nThe ratio is: "      << ratio;
	cout << '\n';
	return 0;
}

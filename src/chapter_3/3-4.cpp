/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 3, exercise 4
	Page 85
*/
#include "std_lib_facilities.h"

int main()
{
	cout << "Enter two interger values: ";
	int val1;
	int val2;
	cin >> val1 >> val2;

	int smallest;
	int largest;
	if (val1 > val2){
		largest  = val1;
		smallest = val2;
	}else {
		largest  = val2;
		smallest = val1;
	}

	int sum        = val1 + val2;
	int difference = val1 - val2;
	int product    = val1 * val2;
	int ratio      = val1 / val2;

	cout << "\nThe smallest is: "   << smallest;
	cout << "\nThe largest is: "    << largest;
	cout << "\nThe sum is: "        << sum;
	cout << "\nThe difference is: " << difference;
	cout << "\nThe product is: "    << product;
	cout << "\nThe ratio is: "      << ratio;
	cout << '\n';
	return 0;
}

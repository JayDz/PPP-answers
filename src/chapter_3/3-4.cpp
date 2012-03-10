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

	if (val1 > val2)
		cout << "The largest is: " << val1 << endl
		     << "The smallest is: " << val2 << endl;
	else
		cout << "The largest is: " << val2 << endl
		     << "The smallest is: " << val1 << endl;

	cout << "The sum is: "        << val1 + val2 << endl;
	cout << "The difference is: " << val1 - val2 << endl;
	cout << "The product is: "    << val1 * val2 << endl;
	cout << "The ratio is: "      << val1 / val2 << endl;

	return 0;
}

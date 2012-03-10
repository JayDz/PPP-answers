/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 3, exercise 8
	Page 86
*/
#include "std_lib_facilities.h"

int main()
{
	cout << "Enter an integer: ";
	int value;
	cin >> value;

	if (value % 2 == 0)
		cout << "The value of " << value << " is an even number." << endl;
	else
		cout << "The value of " << value << " is an odd number." << endl;

	return 0;
}

/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 4, exercise 6
	Page 126
*/
#include "std_lib_facilities.h"

int main()
{
	vector<string> values(10);
	values[0] = "zero";
	values[1] = "one";
	values[2] = "two";
	values[3] = "three";
	values[4] = "four";
	values[5] = "five";
	values[6] = "six";
	values[7] = "seven";
	values[8] = "eight";
	values[9] = "nine";

	cout << "Enter a digit (0-9) to convert to its spelled equivalent: ";
	int digit;
	cin >> digit;

	// don't even need to check, std_lib_facilities throws exception for us
	if (digit < 0 || digit > values.size())
		cout << "Invalid digit." << endl;
	else
		cout << "The spelled-out equivalent of " << digit
		     << " is: " << values[digit] << endl;

	return 0;
}

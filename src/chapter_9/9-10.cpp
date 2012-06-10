/*
	chapter 9 exercise 10
	page 335
*/
#include "std_lib_facilities.h"

bool leapyear(int y)
{
	int last_digit = y % 10;
	y /= 10;
	int next_last  = y % 10;

	int value = 10*next_last+last_digit;
	
	if ((value % 4 == 0) && (value % 100 != 0) && (value % 400 != 0))
		return true;
	return false;
}

int main()
{
	try {
		cout << "Enter year: ";
		int year;
		cin >> year;
	
		if (!cin) error("Invalid input.");
		if (leapyear(year))
			cout << year << " is a leap year.\n";
		else
			cout << year << " is not a leap year.\n";
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}

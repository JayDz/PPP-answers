/*
	chapter 9 exercise 10
	page 335
*/
#include "std_lib_facilities.h"

bool leapyear(int y)
{	
	if ((y % 4 == 0) && (y % 100 != 0) && (y % 400 != 0))
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

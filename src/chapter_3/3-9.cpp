/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 3, exercise 9
	Page 86
*/
#include "std_lib_facilities.h"

int main()
{
	cout << "Enter a spelled-out (lowercase) number: ";
	string number;
	cin >> number;

	if (number == "zero")
		cout << 0 << endl;
	else
		if (number == "one")
			cout << 1 << endl;
		else
			if (number == "two")
				cout << 2 << endl;
			else
				if (number == "three")
					cout << 3 << endl;
				else
					if (number == "four")
						cout << 4 << endl;
					else
						cout << "Not a number I know." << endl;
	return 0;
}

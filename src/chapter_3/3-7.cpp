/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 3, exercise 7
	Page 85
*/
#include "std_lib_facilities.h"

int main()
{
	cout << "Enter three string values: ";
	string val1;
	string val2;
	string val3;
	cin >> val1 >> val2 >> val3;

	if (val1 < val2){
		if (val1 < val3)	
			if (val2 < val3)
				cout << val1 << ", " << val2 << ", " << val3 << endl;
			else
				cout << val1 << ", " << val3 << ", " << val2 << endl;
		else 
			cout << val3 << ", " << val1 << ", " << val2 << endl;
	}else {
		if (val2 < val3)
			if (val1 < val3)
				cout << val2 << ", " << val1 << ", " << val3 << endl;
			else 
				cout << val2 << ", " << val3 << ", " << val1 << endl;
		else 
			cout << val3 << ", " << val2 << ", " << val1 << endl;
	}

	return 0;
}

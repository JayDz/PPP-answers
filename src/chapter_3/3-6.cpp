/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 3, exercise 6
	Page 85
*/
#include "std_lib_facilities.h"

int main()
{
	cout << "Enter three integer values: ";
	int val1;
	int val2;
	int val3;
	cin >> val1 >> val2 >> val3;

	if (val1 < val2){
		if (val1 < val3)	
			if (val2 < val3)
				cout << val1 << "," << val2 << "," << val3 << endl;
			else
				cout << val1 << "," << val3 << "," << val2 << endl;
		else 
			cout << val3 << "," << val1 << "," << val2 << endl;
	}else {
		if (val2 < val3)
			if (val1 < val3)
				cout << val2 << "," << val1 << "," << val3 << endl;
			else 
				cout << val2 << "," << val3 << "," << val1 << endl;
		else 
			cout << val3 << "," << val2 << "," << val1 << endl;
	}

	return 0;
}

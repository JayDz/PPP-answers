/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 5 exercise 8
	Page 168
*/
#include "std_lib_facilities.h"

int main()
{		
	cout << "Please enter how many of the numbers you wish to sum, starting from the first: ";
	int n;
	cin >> n;

	cout << "Please enter some numbers (press '|' at prompt to stop): ";
	vector<int> numbers;
	int val;
	while (cin >> val)
		numbers.push_back(val);

	if (n < 0) {
		cerr << "Cannot sum a negative number of numbers." << endl;
		return 1;
	}
	if (n > numbers.size()) {
		cerr << "Cannot sum more numbers than exist!" << endl;
		return 2;
	}

	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += numbers[i];

	switch (n) {
	case 0: 
		cout << "I guess you don't want to sum anything." << endl;
		break;
	case 1:
		cout << "Only one number to sum: " << sum << endl;
		break;
	default:
		cout << "The sum of the first " << n << " numbers: ";
		for (int i = 0; i < n; ++i) {
			if ((n-i) == 1)
				cout << "and " << numbers[i];
			else
				cout << numbers[i] << ", ";
		}
		cout << " is " << sum << "." << endl;
		break;
	}

	return 0;
}

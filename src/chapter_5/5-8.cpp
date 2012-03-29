/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 5 exercise 8
	Page 168
*/
#include "std_lib_facilities.h"

int main()
{
	vector<int> numbers;
	
	cout << "Please enter some numbers (press '|' at prompt to stop): ";
	int val;
	while (cin >> val)
		numbers.push_back(val);
	cin.clear(); //After loop ends cin will be in bad state, will skip all prompts below if not cleared.
	string junk;
	cin >> junk; //Clean up.

	cout << "Please enter how many of the numbers you wish to sum, starting from the first: ";
	int n;
	cin >> n;

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

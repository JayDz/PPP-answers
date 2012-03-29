/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 5 exercise 10
	Page 169
*/
#include "std_lib_facilities.h"

int main()
{
	vector<double> numbers;
	vector<double> differences;

	cout << "Please enter some numbers (press '|' at prompt to stop): ";
	double val;
	bool first_iteration = true;
	int i = 0;
	while (cin >> val) {
		if (first_iteration == true) {
			numbers.push_back(val);
			first_iteration = false;
		}
		else {
			differences.push_back(numbers[i] - val);
			numbers.push_back(val);
			++i;
		}
	}

	cin.clear(); //After loop ends cin will be in bad state, will skip all prompts below if not cleared.
	string junk;
	cin >> junk; //Clean up.

	cout << "Please enter how many of the numbers you wish to sum, starting from the first: ";
	int n;
	cin >> n;

	if (n < 0)
		error("Cannot sum a negative number of numbers.");
	if (n > numbers.size())
		error("Cannot sum more numbers than exist!");

	double sum = 0;
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

	cout << "The differences between adjacent values: ";
	if (numbers.size() == 1)
		cout << numbers[i] << " has no adjacent value." << endl;
	else
		for (int i = 0; i < differences.size(); ++i)
			cout << differences[i] << " ";
	cout << endl;
	
	return 0;
}

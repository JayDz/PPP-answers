/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	chapter 6 exercise 9
	page 217
*/
#include "std_lib_facilities.h"

bool print_conjunction = false; //nasty solution for printing "and" when needed.

void print_ones(char ch)
{
	int n = ch;

	if (n != 0) {
		if (print_conjunction)
			cout << " and ";
		cout << n;
		if (n == 1)
			cout << " one";
		else
			cout << " ones";
	}
}

void print_tens(char ch)
{
	int n = ch;
	
	if (n != 0) {
		if (print_conjunction)
			cout << " and ";
		cout << n;
		if (n == 1)
			cout << " ten";
		else
			cout << " tens";
	}
}

void print_hundreds(char ch)
{
	int n = ch;

	if (n != 0) {
		if (print_conjunction)
			cout << " and ";
		cout << n;
		if (n == 1)
			cout << " hundred";
		else
			cout << " hundreds";
	}
}

void print_thousands(char ch)
{
	int n = ch;
	cout << n << " thousand";
}
int main()
{
	try {
		vector<char> digits;
		cout << "Enter a positive integer containing 4 or less digits followed by a semi-colon (e.g. 200;): ";
		char ch;
		cin >> ch;
		while (ch != ';') {
			if (ch < '0' || ch > '9')
				error("Invalid digit entered.");
			digits.push_back(ch - '0');
			cin >> ch;
		}

		if (digits.size() == 0) error("No digits entered.");
		if (digits.size() > 4)  error("Cannot handle more than four digits.");
		int number = 0;
		for (int i = 0; i < digits.size(); ++i)
			number = number * 10 + digits[i];

		cout << number << " is ";

		switch (digits.size()) {
		case 1: 
			print_ones(digits[0]);
			break;
		case 2:
			print_tens(digits[0]);
			print_conjunction = true;
			print_ones(digits[1]);
			break;
		case 3:
			print_hundreds(digits[0]);
			print_conjunction = true;
			print_tens(digits[1]);
			print_ones(digits[2]);
			break;
		case 4:
			print_thousands(digits[0]);
			print_conjunction = true;
			print_hundreds(digits[1]);
			print_tens(digits[2]);
			print_ones(digits[3]);
			break;
		}
	
		cout << ".\n";
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}

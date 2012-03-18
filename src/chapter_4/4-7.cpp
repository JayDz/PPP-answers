/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 4, exercise 7
	Page 127
*/
#include "std_lib_facilities.h"

int convert_to_digit(string digit)
{
	vector<string> digits(10);
	digits[0] = "zero" ; digits[1] = "one";
	digits[2] = "two"  ; digits[3] = "three";
	digits[4] = "four" ; digits[5] = "five";
	digits[6] = "six"  ; digits[7] = "seven";
	digits[8] = "eight"; digits[9] = "nine";

	const int invalid = -1;
	int real_digit = invalid;

	// Lets see if digit was entered in spelled-out format
	for (int i = 0; i < digits.size(); ++i) {
		if (digit == digits[i])
			return i;
	}
	
	// digit might be in digital format instead
	if (digit == "0")      real_digit = 0;
	else if (digit == "1") real_digit = 1;
	else if (digit == "2") real_digit = 2;
	else if (digit == "3") real_digit = 3;
	else if (digit == "4") real_digit = 4;
	else if (digit == "5") real_digit = 5;
	else if (digit == "6") real_digit = 6;
	else if (digit == "7") real_digit = 7;
	else if (digit == "8") real_digit = 8;
	else if (digit == "9") real_digit = 9;
	
	return real_digit;
}

int main()
{
	string left_op;
	string right_op;
	char operation  = 0;
	const int invalid = -1;

	cout << "Please enter three arguments (x y +) where x and y are single positive digits: ";
	cin >> left_op >> right_op >> operation;
	
	int left  = convert_to_digit(left_op);
	int right = convert_to_digit(right_op);
	if (left == invalid || right == invalid)
		cout << "Invalid input." << endl;
	else {
		switch (operation) {
		case '+': 
			cout << "The sum of " << left_op << " and " << right_op
		         << " is: " << left + right << endl;
			break;
		case '-':
			cout << "The difference of " << left_op << " and " << right_op
		    	 << " is: " << left -right << endl;
			break;
		case '*':
			cout << "The product of " << left_op << " and " << right_op
		      	 << " is: " << left * right << endl;
			break;
		case '/':
			if (right == 0)
				cout << "Cannot divide by zero!" << endl;
			else
				cout << "The quotient of " << left_op << " and " << right_op			     
		     		 << " is: " << left / right << endl;
			break;
		default: 
			cout << "Unknown operation." << endl;
			break;
		}
	}

	return 0;
}

/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 4, exercise 5
	Page 126
*/
#include "std_lib_facilities.h"

int main()
{
	double left_op  = 0;
	double right_op = 0;
	char operation  = 0;

	cout << "Please enter three arguments (x y +): ";
	cin >> left_op >> right_op >> operation;

	if (operation == '+') 
		cout << "The sum of " << left_op << " and " << right_op
		     << " is: " << left_op + right_op << endl;
	else if (operation == '-')
		cout << "The difference of " << left_op << " and " << right_op
		     << " is: " << left_op - right_op << endl;
	else if (operation == '*')
		cout << "The product of " << left_op << " and " << right_op
		     << " is: " << left_op * right_op << endl;
	else if (operation == '/') {
		if (right_op == 0)
			cout << "Cannot divide by zero!" << endl;
		else
			cout << "The quotient of " << left_op << " and " << right_op
			     << " is: " << left_op / right_op << endl;
	}
	else 
		cout << "Unknown operation." << endl;

	return 0;
}

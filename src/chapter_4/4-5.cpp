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
	
	switch (operation) {
	case '+': 
		cout << "The sum of " << left_op << " and " << right_op
		     << " is: " << left_op + right_op << endl;\
	    break;
	case '-':
		cout << "The difference of " << left_op << " and " << right_op
		     << " is: " << left_op - right_op << endl;
		break;
	case '*':
		cout << "The product of " << left_op << " and " << right_op
		     << " is: " << left_op * right_op << endl;
		break;
	case '/':
		if (right_op == 0)
			cout << "Cannot divide by zero!" << endl;
		else
			cout << "The quotient of " << left_op << " and " << right_op
			     << " is: " << left_op / right_op << endl;
		break;
	default: 
		cout << "Unknown operation." << endl;
		break;
	}
	return 0;
}

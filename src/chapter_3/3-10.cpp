/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 3, exercise 10
	Page 86
*/
#include "std_lib_facilities.h"

int main()
{
	cout << "Enter an arithmetic operation in the form of: + 4 5 OR plus 4 5" << endl;
	string operation;
	cin >> operation;
	
	double l_operand;
	double r_operand;
	cin >> l_operand >> r_operand;
	
	double result = 0.0;
	if (operation == "+")
		result = l_operand + r_operand;
	else
		if (operation == "plus")
			result = l_operand + r_operand;
		else
			if (operation == "-")
				result = l_operand - r_operand;
			else
				if (operation == "minus")
					result = l_operand - r_operand;
				else
					if (operation == "*")
						result = l_operand * r_operand;
					else
						if (operation == "mul")
							result = l_operand * r_operand;
						else
							if (operation == "/")
								result = l_operand / r_operand;
							else 
								if (operation == "div")
									result = l_operand / r_operand;

	cout << result << endl;

	return 0;
}

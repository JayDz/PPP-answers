/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 5 exercise 11
	Page 169
*/
#include "std_lib_facilities.h"

int main()
{
	int pre_num1 = 0;
	int pre_num2 = 1;
	int fib_number = 1;

	while ((pre_num1 + pre_num2) > 0) {
			cout << fib_number << endl;
			fib_number = pre_num1 + pre_num2;
			
			pre_num1 = pre_num2;
			pre_num2 = fib_number;
	}
	
	cout << "The largest Fibonacci number that fits in an int is: " << fib_number << endl;
	return 0;
}

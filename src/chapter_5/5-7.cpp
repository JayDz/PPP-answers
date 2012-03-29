/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 5 exercise 7
	Page 168
*/
#include "std_lib_facilities.h"

class Complex_number_error { };

void print_roots(double a, double b, double c)
	// Will attempt to calculate the roots of a quadratic equation.
	// pre-condition: Result of expression b^2 - 4ac must not be less than zero. 
	// post-condition: Will print roots of the quadratic equation.
{
	double sqrt_op = (b*b) - (4*a*c);
	
	if (sqrt_op < 0)
		throw Complex_number_error();

	double x1 = (-b) / (2*a);
	double x2 = x1;
	x1 += (sqrt(sqrt_op)) / (2*a);
	x2 -= (sqrt(sqrt_op)) / (2*a);

	cout << "The roots for the quadratic equation are: " << x1 << " and " << x2 << endl;
}

int main()
{
	cout << "This program can find roots of quadratic equations, enter a, b, and c: ";
	double a;
	double b;
	double c;
	cin >> a >> b >> c;
	
	if (cin) {
		if (a == 0) 
			error("Since a = 0 you no longer have a quadratic equation.");
			
		try {
			print_roots(a,b,c);
		}
		catch(Complex_number_error&) {
			error("Sorry, program cannot handle complex solutions!");
		}
	}
	else 
		error("There was a problem with your input.");
		
	return 0;
}

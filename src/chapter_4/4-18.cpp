/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 4 exercise 18
	Page 128
*/
#include "std_lib_facilities.h"

int main()
{
	cout << "This program solves quadratic equations (ax2+bx+c=0), please enter a, b, and c: ";
	double a;
	double b;
	double c;
	cin >> a >> b >> c;

	double x1;
	double x2;

	double check_if_imaginary = (b*b) - (4*a*c);
	if (check_if_imaginary < 0)
		cout << "Sorry, I cannot handle complex solutions." << endl;
	else {
		x1 = (-b) / (2*a);
		x2 = x1;
		x1 += (sqrt(check_if_imaginary)) / (2*a);
		x2 -= (sqrt(check_if_imaginary)) / (2*a);

		cout << "The solutions are: x = " << x1 << " and x = " << x2 << "." << endl;
	}

	return 0;
}

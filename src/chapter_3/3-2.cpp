/*
 	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 3, Exercise 2 
	Page 85
*/

#include "std_lib_facilities.h"

int main()
{
	cout<<"Enter the number of miles to covert into kilometers: ";
	double miles;
	cin>>miles;

	double km_in_a_mile = 1.609;
	cout<<"The kilometer equivalent of "<<miles<<" miles is: "
	<< km_in_a_mile * miles<<'\n';

	return 0;
}

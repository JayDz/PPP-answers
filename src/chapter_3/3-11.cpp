/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 3, exercise 11
	Page 86
*/
#include "std_lib_facilities.h"

int main()
{
	cout << "How many pennies do you have? ";
	double pennies;
	cin >> pennies;

	cout << "How many nickels do you have? ";
	double nickels;
	cin >> nickels;

	cout << "How many dimes do you have? ";
	double dimes;
	cin >> dimes;

	cout << "How many quarters do you have? ";
	double quarters;
	cin >> quarters;

	cout << "How many 50-cent coins do you have? ";
	double half_dollars;
	cin >> half_dollars;

	cout << "How many 100-cent coins do you have? ";
	double full_dollars;
	cin >> full_dollars;

	if (pennies == 1)
		cout << "You have  " << pennies << " penny." << endl;
	else
		if (pennies < 10)
			cout << "You have  " << pennies << " pennies." << endl;
		else 
			cout << "You have " << pennies << " pennies." << endl;
	if (nickels == 1)
		cout << "You have  " << nickels << " nickel." << endl;
	else
		if ( nickels < 10)
			cout << "You have  " << nickels << " nickels." << endl;
		else
			cout << "You have " << nickels << " nickels." << endl;
	
	if (dimes == 1)
		cout << "You have  " << dimes << " dime." << endl;
	else
		if (dimes < 10)
			cout << "You have  " << dimes << " dimes." << endl;
		else
			cout << "You have " << dimes << " dimes." << endl;
	
	if (quarters == 1)
		cout << "You have  " << quarters << " quarter." << endl;
	else
		if (quarters < 10)
			cout << "You have  " << quarters << " quarters." << endl;
		else
			cout << "You have " << quarters << " quarters." << endl;

	if (half_dollars == 1)
		cout << "You have  " << half_dollars << " half dollar." << endl;
	else
		if (half_dollars < 10)
			cout << "You have  " << half_dollars << " half dollars." << endl;
		else
			cout << "You have " << half_dollars << " half dollars." << endl;

	if (full_dollars == 1)
		cout << "You have  " << full_dollars << " full-dollar." << endl;
	else
		if (full_dollars < 10)
			cout << "You have  " << full_dollars << " full-dollars." << endl;
		else 
			cout << "You have " << full_dollars << " full-dollars." << endl;
			
	double total_cents = 0.0;
	total_cents += pennies;
	total_cents += nickels * 5;
	total_cents += dimes * 10;
	total_cents += quarters * 25;
	total_cents += half_dollars * 50;
	total_cents += full_dollars * 100;
	
	cout << "The value of all of your coins is " << total_cents << " cents." << endl;
	cout << "Sum in cents: " << total_cents << endl;
	cout << "Sum in dollars: $" << total_cents / 100 << endl;
	return 0;
}

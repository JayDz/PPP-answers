/*
	chapter 9 exercise 14
	page 335
*/
#include "std_lib_facilities.h"

class Money {
public:
	Money();
	Money(double amount);
	double get_amount() const;
	void set_amount(double amount);
	void add(double amount);
	void sub(double amount);
private:
	long cents;
};

long convert_to_cents(double amount);

Money::Money(): cents(0) { }
Money::Money(double amount)
{
	set_amount(amount);
}

double Money::get_amount() const
{
	return (double(cents)/100);
}

void Money::set_amount(double amount)
{
	if (amount < 0) error("Amount must be positive.");
	cents = convert_to_cents(amount);
}

void Money::add(double amount)
{
	if (amount < 0) error("Amount must be positive.");
	cents += convert_to_cents(amount);
}

void Money::sub(double amount)
{
	if (amount < 0) error("Amount must be positive.");
	cents -= convert_to_cents(amount);
}

long convert_to_cents(double amount)
{
	int dollars = amount;
	double remainder = amount - dollars;
	double total = (dollars*100)+(remainder*100);

	long real = total;
	if (total > real) {
		double remainder = total - real;
		if (remainder >= 0.5) ++real;
	}
	return real;
}

int main()
{
	try {
		cout << "Enter dollar amount: ";
		double amount;
		cin >> amount;

		Money m(amount);
		
		cout << "Add some more money: ";
		cin >> amount;
		m.add(amount);

		cout << "Now subtract some: ";
		cin >> amount;
		m.sub(amount);

		cout << "You have: $" << m.get_amount() << endl;
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}

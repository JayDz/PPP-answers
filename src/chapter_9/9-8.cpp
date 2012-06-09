/*
	chapter 9 exercise 8
	page 334
*/
#include "std_lib_facilities.h"

class Patron {
public:
	Patron(string user, string c_number, double fee=0);

	string get_username() const { return username; }
	string get_card_number() const { return card_number; }
	double get_fees_owed() const { return fees_owed; }
	
	void set_fee(double amount);
private:
	string username;
	string card_number;
	double fees_owed;
};

Patron::Patron(string user, string c_number, double fee)
	:username(user),card_number(c_number),fees_owed(fee)
{
}
	
void Patron::set_fee(double amount)
{
	fees_owed = amount;
}

//helper function
bool owes_fee(const Patron& p)
{
	if (p.get_fees_owed() > 0) 
		return true;
	return false;
}

int main()
{
	Patron jeff("Jeffrey Diaz","2 3333 07338 1287");
	cout << "Name: " << jeff.get_username() << endl;
	cout << "Card Number: " << jeff.get_card_number() << endl;
	if (owes_fee(jeff)) 
		cout << jeff.get_username() << " owes fees of: " << jeff.get_fees_owed() << endl;
	else
		cout << jeff.get_username() << " does not owe any fees." << endl;
	
	jeff.set_fee(20.34);
	cout << "Fees added: $" << jeff.get_fees_owed() << endl;

	return 0;
}

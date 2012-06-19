/*
	chapter 11 exercise 3
	page 404
*/
#include "std_lib_facilities.h"

int string_to_int(string& str)
{
	istringstream is(str);
	is.unsetf(ios::dec);
	is.unsetf(ios::hex);
	is.unsetf(ios::oct);
	int val;
	is >> val;
	if (!is) error("Please enter integers only.");
	return val;
}

void print(const string& str_int, int val)
{
	cout << str_int << '\t';
	if (str_int.size() > 1) {
		if (str_int[1] == 'x' || str_int[1] == 'X')
			cout << "hexadecimal ";
		else if (str_int[0] == '0')
			cout << "octal       ";
		else 
			cout << "decimal     ";
	}
	else
		cout << "decimal     ";
	cout << "converts to " << setw(4) << val << "\tdecimal.\n";
}

int main()
{
	try {
		cout << "Enter some integers in any (hex,octal,decimal) base (\"quit\" to finish input loop): ";
		vector<string> s_integers;
		string num;
		while (cin >> num && num != "quit")
			s_integers.push_back(num);
		
		if (cin.eof()) { //check for early exit (ctrl-d).
			cout << "Ok, goodbye.\n";
			return -1;
		}

		for (int i = 0; i < s_integers.size(); ++i)
			print(s_integers[i],string_to_int(s_integers[i]));
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}

/*
	chapter 17 exercise 3
	page 609
*/
#include "std_lib_facilities.h"

void to_lower(char* s)
{
	const int ascii_lower_limit  = 65;
	const int ascii_higher_limit = 90;
	const int lowercase = 32;

	while (*s) {
		//check if we found an uppercase letter.
		if (*s >= ascii_lower_limit && *s <= ascii_higher_limit)
			*s = *s + lowercase;
		++s;
	}
}

int main()
{
	cout << "Please enter text: ";
	string line;
	getline(cin,line);
	to_lower(const_cast<char*>(line.c_str()));

	cout << line << endl;

	return 0;
}

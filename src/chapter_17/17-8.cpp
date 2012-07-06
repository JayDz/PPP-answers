/*
	chapter 17 exercise 8
	page 609
*/
#include "std_lib_facilities.h"

int main()
{
	cout << "Enter characters and \'!\' to quit:\n";
	string ch;
	char c;
	while (cin.get(c) && c != '!')
		ch += c;
	
	for (int i = 0; i < ch.size(); ++i)
		cout << hex << showbase << static_cast<int>(ch[i]) << " ";
	cout << endl;	
	return 0;
}

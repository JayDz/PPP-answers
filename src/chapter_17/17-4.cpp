/*
	chapter 17 exercise 4
	page 609
*/
#include "std_lib_facilities.h"

char* strdup(const char* str)
{
	//get string size.
	int size = 0;
	while (str[size])
		size++;

	char* s = new char[size];
	for (int i = 0; i < size; ++i)
		s[i] = str[i];
	
	//remember to zero-terminate the c-string.
	s[size] = 0;
	return s;
}

int main()
{
	cout << "Enter text: ";
	string line;
	getline(cin,line);

	char* str = strdup(line.c_str());
	cout << str << endl;
	
	delete[] str;
	return 0;
}

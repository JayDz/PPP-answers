/*
	chapter 18 exercise 1
	page 643
*/
#include "std_lib_facilities.h"
#include <string.h>

char* strdup(const char* str)
{
	//get string size.
	int sz = strlen(str);

	char* s = new char[sz];
	for (int i = 0; i < sz; ++i)
		*(s+i) = *(str+i);
	
	//remember to zero-terminate the c-string.
	s[sz] = 0;
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

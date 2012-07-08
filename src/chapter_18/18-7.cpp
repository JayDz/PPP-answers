/*
	chapter 18 exercise 7
	page 643
*/
#include "std_lib_facilities.h"

int size(const char* str)
{
	const char* temp = str;
	while (*temp) ++temp;
	return temp - str;
}

char* cat_dot(const char* s1, const char* s2)
{
	int s1_sz = size(s1);
	int s2_sz = size(s2);
	char* cat_str = new char[s1_sz+s2_sz+2]; //+2 for the '.' and for the zero byte.	
	
	int i;
	for (i = 0; i < s1_sz; ++i)
		cat_str[i] = s1[i];
	
	cat_str[i] = '.';

	++i;
	for (int j = 0; j < s2_sz; ++j)
		cat_str[i++] = s2[j];

	cat_str[i] = 0;
	return cat_str;
}

char* cat_dot(const char* s1, const char* s2, const char* seperator)
{
	int s1_sz = size(s1);
	int s2_sz = size(s2);
	int sr_sz = size(seperator);
	char* cat_str = new char[s1_sz+s2_sz+sr_sz+1];

	int i;
	for (i = 0; i < s1_sz; ++i)
		cat_str[i] = s1[i];
	
	for (int j = 0; j < sr_sz; ++j)
		cat_str[i++] = seperator[j];
	
	for (int j = 0; j < s2_sz; ++j)
		cat_str[i++] = s2[j];

	cat_str[i] = 0;
	return cat_str;
}

int main()
{
	char* ans1 = cat_dot("C++","Programming is fun.");
	cout << ans1 << endl;

	char* ans2 = cat_dot("C++","Programming is fun.","-.-.-");
	cout << ans2 << endl;
	
	delete[] ans1;
	delete[] ans2;
	return 0;
}

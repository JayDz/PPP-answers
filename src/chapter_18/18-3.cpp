/*
	chapter 18 exercise 3
	page 643
*/
#include "std_lib_facilities.h"

//must implement our own, cannot use strlen since string.h 
//also declares int strcmp(const char*,const char*) causing a collision.
int size(const char* str)
{
	const char* temp = str;
	while (*temp) ++temp;
	return temp - str;
}

int strcmp(const char* s1, const char* s2)
{
	int s1_sz = size(s1);
	int s2_sz = size(s2);
	int n = s1_sz < s2_sz ? s1_sz : s2_sz;

	for (int i = 0; i < n+1; ++i) {
		if (*(s1+i) != *(s2+i)) {
			if (*(s1+i) < *(s2+i))
				return -1;
			else
				return 1;
		}
	}
	return 0;
}

int main()
{
	cout << strcmp("RIVERa","RIVERe") << endl;
	cout << strcmp("camping","camping") << endl;
	cout << strcmp("operator","operating") << endl;
	return 0;
}

/*
	chapter 18 exercise 5
	page 643
*/
#include "std_lib_facilities.h"

string cat_dot(const string& s1, const string& s2)
{
	return s1+'.'+s2;
}

int main()
{
	string ans = cat_dot("Niels","Bohr");
	cout << ans << endl;
	return 0;
}

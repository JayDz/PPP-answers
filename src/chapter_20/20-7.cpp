/*
	chapter 20 exercise 7
	page 725
*/
#include "std_lib_facilities.h"

template<class Iter>
Iter high(Iter first, Iter last)
{
	if (first == last) return last;

	Iter high = first;
	for (Iter p = first; p != last; ++p)
		if (*p > *high) 
			high = p;
	return high;
}

int main()
{
	vector<string> strs;
	strs.push_back("algorithm");
	strs.push_back("bacon");
	strs.push_back("cats");
	strs.push_back("spike");
	strs.push_back("guitar");
	strs.push_back("zebra");
	strs.push_back("wheels");

	vector<string>::iterator h = high(strs.begin(),strs.end());

	if (h != strs.end())
		cout << "The lexicographical last string is: " << *h << endl;
	else
		cout << "Empty container.\n";

	return 0;
}

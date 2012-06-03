/*
	chapter 8 exercise 6
	page 296
*/
#include "std_lib_facilities.h"

vector<string> reverse1(const vector<string>& sequence)
{
	vector<string> r_seq;

	for (int i = sequence.size()-1; i >= 0; --i)
		r_seq.push_back(sequence[i]);

	return r_seq;
}

void reverse2(vector<string>& v)
	// Better, cleaner algorithm by Prof. Stroustrup.
	// http://www.stroustrup.com/Programming/Solutions/Ch8/e8-5.cpp
{
	for(int i = 0; i<v.size()/2; ++i)
		swap(v[i],v[v.size()-1-i]);
}

void print(const vector<string>& v)
{
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i];
		if (i+1 < v.size())
			cout << ", ";
	}
	cout << ".\n";
}

int main()
{
	vector<string> v;
	
	cout << "Enter a sequence of strings (enter \"quit\" to exit loop): ";
	string str;
	while (cin >> str && str != "quit")
		v.push_back(str);
	
	cout << "Reversing with reverse1(): ";
	v = reverse1(v);
	print(v);

	cout << "Reversing with reverse2(): ";
	reverse2(v);
	print(v);

	return 0;
}

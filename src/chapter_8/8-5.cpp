/*
	chapter 8 exercise 5
	page 296
*/
#include "std_lib_facilities.h"

vector<int> reverse1(const vector<int>& sequence)
{
	vector<int> r_seq;

	for (int i = sequence.size()-1; i >= 0; --i)
		r_seq.push_back(sequence[i]);

	return r_seq;
}

void reverse2(vector<int>& v)
	// Better, cleaner algorithm by Prof. Stroustrup.
	// http://www.stroustrup.com/Programming/Solutions/Ch8/e8-5.cpp
{
	for(int i = 0; i<v.size()/2; ++i)
		swap(v[i],v[v.size()-1-i]);
}

void print(const vector<int>& v)
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
	vector<int> v;
	
	cout << "Enter a sequence of integers (enter | to quit loop): ";
	int n;
	while (cin >> n)
		v.push_back(n);
	
	cout << "Reversing with reverse1(): ";
	vector<int> r_copy = reverse1(v);
	print(r_copy);

	cout << "Reversing with reverse2(): ";
	reverse2(v);
	print(v);

	return 0;
}

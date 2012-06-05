/*
	chapter 8 exercise 11
	page 297
*/
#include "std_lib_facilities.h"

double maxv(vector<double>& v)
{
	sort(v.begin(),v.end());
	return v[v.size()-1];
}

int main()
{
	vector<double> v;
	cout << "Enter a sequece of numbers (or non-digit to exit loop): ";
	double val;
	while (cin >> val)
		v.push_back(val);
	
	if (v.size() > 0)
		cout << "The largest element is: " << maxv(v) << endl;
	else
		cout << "No elements entered." << endl;
	return 0;
}

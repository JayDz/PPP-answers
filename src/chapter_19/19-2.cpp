/*
	chapter 19 exercise 2
	page 682
*/
#include "std_lib_facilities.h"

template<class T, class U> double f(const vector<T>& vt, const vector<U>& vu)
{
	double sum = 0;
	int i = 0;
	while (i < vt.size() && i < vu.size()) {
		sum += (vt[i]*vu[i]);
		++i;
	}
	return sum;
}

int main()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	vector<double> v2;
	v2.push_back(5.5);
	v2.push_back(10.5);
	v2.push_back(3.14);
	cout << f(v1,v2) << endl;
	return 0;
}

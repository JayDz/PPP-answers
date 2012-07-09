/*
	chapter 19 exercise 1
	page 682
*/
#include "std_lib_facilities.h"

template<class T> void f(vector<T>& v1,const vector<T>& v2)
{
	int v1_sz = v1.size();
	int v2_sz = v2.size();

	int i = 0;
	while (i < v1_sz && i < v2_sz) {
		v1[i] += v2[i];
		++i;
	}
}

int main()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	vector<int> v2;
	v2.push_back(1);
	v2.push_back(1);
	v2.push_back(1);

	f(v1,v2);
	for (int i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";

	vector<string> v3;
	v3.push_back("A");
	v3.push_back("B");
	v3.push_back("C");

	vector<string> v4;
	v4.push_back("D");
	v4.push_back("E");
	v4.push_back("F");
	v4.push_back("G");

	f(v3,v4);
	for (int i = 0; i < v3.size(); ++i)
		cout << v3[i] << " ";

	return 0;
}

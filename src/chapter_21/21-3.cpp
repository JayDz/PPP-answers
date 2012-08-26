/*
	chapter 21 exercise 3
	page 766
*/
#include "std_lib_facilities.h"

namespace exercise_3 {
	template<class Iter, class T>
	int count(Iter first, Iter last, const T& value)
	{
		int counter = 0;
		while (first != last) {
			if (*first == value) ++counter;
			++first;
		}
		return counter;
	}
}

struct Record {
	string n;
	Record(string val): n(val){}
	bool operator==(const Record& r)
	{
		return n == r.n;
	}
};

int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(10);
	v.push_back(2);
	v.push_back(2);

	int c = exercise_3::count(v.begin(),v.end(),1);
	cout << c << " 1's." << endl;

	c = exercise_3::count(v.begin(),v.end(),10);
	cout << c << " 10's." << endl;

	c = exercise_3::count(v.begin(),v.end(),2);
	cout << c << " 2's." << endl;
	
	//test with an object as the value argument to count.
	vector<Record> rv;
	rv.push_back(Record("Jay"));
	rv.push_back(Record("Jake"));
	rv.push_back(Record("Mike"));
	rv.push_back(Record("Jake"));
	rv.push_back(Record("Mike"));
	rv.push_back(Record("Mike"));

	c = exercise_3::count(rv.begin(),rv.end(),Record("Jay"));
	cout << c << " Jay's." << endl;

	c = exercise_3::count(rv.begin(),rv.end(),Record("Jake"));
	cout << c << " Jake's." << endl;

	c = exercise_3::count(rv.begin(),rv.end(),Record("Mike"));
	cout << c << " Mike's." << endl;

	return 0;
}

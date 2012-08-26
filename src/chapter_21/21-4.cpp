/*
	chapter 21 exercise 4
	page 766
*/
#include "std_lib_facilities.h"
#include <map>

class item_count {
public:
	item_count(double val): value(val) {}
	bool operator()(const pair<string,double>& p)
	{
		return p.second < value;
	}
private:
	double value;
};

namespace exercise_4 {
	template<class Iter, class Pred>
	int count_if(Iter first, Iter last, Pred pred)
	{
		int counter = 0;
		while (first != last) {
			if (pred(*first)) ++counter;
			++first;
		}
		return counter;
	}
}

int main()
{
	map<string,double> items;
	items.insert(make_pair("Television",875.10));
	items.insert(make_pair("Radio",54.50));
	items.insert(make_pair("Desktop",870));
	items.insert(make_pair("Air Conditioner",270));
	items.insert(make_pair("smartphone",699.99));

	//return the number of items with a value of less than 500.00
	int c = exercise_4::count_if(items.begin(),items.end(),item_count(500.00));

	cout << "The count is: " << c << endl;
	return 0;
}

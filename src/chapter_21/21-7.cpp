/*
	chapter 21 exercise 7
	page 767
*/
#include "std_lib_facilities.h"

namespace exercise_7 {
	//Created a namespace to avoid name collision with std::binary_search
	
	bool binary_search(const vector<int>& v, int value)
	{
		int mid = v.size() / 2;
		vector<int>::const_iterator mid_element = v.begin();
		advance(mid_element,mid);
		
		if (*mid_element == value) return true;
		
		if (*mid_element > value) {
			for (vector<int>::const_iterator p = v.begin(); p != mid_element; ++p)
				if (*p == value) return true;
		}
		else {
			for (vector<int>::const_iterator p = ++mid_element; p != v.end(); ++p)
				if (*p == value) return true;
		}
		return false;
	}

	bool binary_search(const list<string>& lst, const string& value)
	{
		int mid = lst.size() / 2;
		list<string>::const_iterator mid_link = lst.begin();
		advance(mid_link,mid);
		
		if (*mid_link == value) return true;
		
		if (*mid_link > value) {
			for (list<string>::const_iterator p = lst.begin(); p != mid_link; ++p)
				if (*p == value) return true;
		}
		else {
			for (list<string>::const_iterator p = ++mid_link; p != lst.end(); ++p)
				if (*p == value) return true;
		}
		return false;
	}
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	v.push_back(10);
	
	int ivalue = 9;
	if (exercise_7::binary_search(v,ivalue))
		cout << "The value " << ivalue << " was found.\n";
	else
		cout << "Did not find " << ivalue << endl;

	list<string> lst;
	lst.push_back("hello");
	lst.push_back("world");
	lst.push_back("return");
	lst.push_back("virtual");
	lst.push_back("class");
	lst.push_back("struct");
	lst.push_back("operator");

	//After an hour of head scratching over the fact std::sort does not work
	//with iterators provided by list<>, a little research pointed me towards
	//the sort member function.
	lst.sort();

	string svalue = "return";
	if (exercise_7::binary_search(lst,svalue))
		cout << "The value " << "\"" << svalue << "\"" << " was found.\n";
	else
		cout << "Did not find " << svalue << endl;

	return 0;
}

/*
	chapter 20 exercise 11
	page 725
*/
#include "std_lib_facilities.h"

void f(list<int>& lst)
{
	vector<double> v;
	
	for (list<int>::iterator p = lst.begin(); p != lst.end(); ++p)
		v.push_back(*p);

	//verify copy
	vector<double>::iterator v_iter = v.begin();
	list<int>::iterator lst_iter = lst.begin();
	
	for (; lst_iter != lst.end(); ++v_iter, ++lst_iter)
		if (*v_iter != *lst_iter) error("Error during copy.");
	
	sort(v.begin(),v.end());
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
}

int main()
{
	try {
		list<int> lst;
		lst.push_front(10);
		lst.push_front(5);
		lst.push_front(15);
		lst.push_back(1);
		lst.push_front(100);

		f(lst);
	}
	catch(exception& e) {
		cerr << e.what() << endl;
		return 1;
	}
	return 0;
}

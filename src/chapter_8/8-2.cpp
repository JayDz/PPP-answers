/*
	chapter 8 exercise 2
	page 296
*/
#include "std_lib_facilities.h"

void print(string label, const vector<int>& values)
{
	cout << label << ": ";
	for (int i = 0; i < values.size(); ++i) {
		cout << values[i];
		if (i+1 < values.size()) 
			cout << ", ";
	}
	cout << endl;
}

int main()
{
	vector<int> values;
	values.push_back(8);
	values.push_back(0);
	values.push_back(3);
	values.push_back(2);

	print("elements",values);
	return 0;
}

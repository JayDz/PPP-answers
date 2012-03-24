/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 4 exercise 19
	Page 128
*/
#include "std_lib_facilities.h"

int main()
{
	vector<string> names;
	vector<int> scores;
	
	string str_val;
	int int_val;
	cout << "Please enter name-and-value pairs (such as Joe 1) where name is unique. Enter No more to end input loop: \n";
	while (cin >> str_val >> int_val) {
		int name_has_been_seen = 0;
		for (int i = 0; i < names.size(); ++i) 
			if (str_val == names[i])
				name_has_been_seen = 1;
		
		if (name_has_been_seen == 0) {
			names.push_back(str_val);
			scores.push_back(int_val);
		}
		else {
			cout << "A name cannot be entered twice!" << endl;
			break;
		}
	}

	for (int i = 0; i < names.size(); ++i)
		cout << names[i] << ", " << scores[i] << endl;
	
	return 0;
}

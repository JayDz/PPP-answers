/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 6 exercise 4
	Page 216
*/
#include "std_lib_facilities.h"

class Name_value {
public:
	string name;
	int value;

	Name_value(string n, int val)
		:name(n), value(val) { }
};

int main()
{
	vector<Name_value> pairs;
	
	cout << "Please enter name-and-value pairs (such as Joe 1) where name is unique. Enter No more to end input loop:\n";
	string str_val;
	int int_val;
	while (cin >> str_val >> int_val) {
		bool name_has_been_seen = false;
		for (int i = 0; i < pairs.size(); ++i) 
			if (str_val == pairs[i].name)
				name_has_been_seen = true;
		
		if (!name_has_been_seen) 
			pairs.push_back(Name_value(str_val, int_val));
		else {
			cout << "A name cannot be entered twice!" << endl;
			break;
		}
	}

	for (int i = 0; i < pairs.size(); ++i)
		cout << pairs[i].name << ", " << pairs[i].value << endl;
	
	return 0;
}

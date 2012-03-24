/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 4 exercise 20
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

	if (names.size() > 0) {
		cout << "To browse scores, enter its name pair, or enter exit to terminate program: ";
		string name = "";
		cin >> name;
		while (name != "exit") {
			int found_score = 0;
			for (int i = 0; i < names.size(); ++i) {
				if (name == names[i]) {
					cout << "The score for " << name << " is " << scores[i] << "." << endl;
					found_score = 1;
				}
			}

			if (found_score == 0)
				cout << "name not found." << endl;
			cin >> name;
		}
	}
	else 
		cout << "You didn't enter any name-and-value pairs!" << endl;
		
	return 0;
}

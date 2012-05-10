/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 4 exercise 21
	Page 128
*/
#include "std_lib_facilities.h"

int main()
{
	vector<string> names;
	vector<int> scores;
	
	string str_val;
	int int_val;
	cout << "Please enter name-and-value pairs (such as Joe 1) where name is unique. Enter NoName 0 to end input loop:\n";
	
	int continue_loop = 1;
	while (continue_loop == 1) {
		cin >> str_val >> int_val;

		if (str_val == "NoName") {
			if (int_val == 0)
				continue_loop = 0;
			else
				cout << "Sorry, the only acceptable value for NoName is 0." << endl;
		}
		else {
			int name_has_been_seen = 0;
			for (int i = 0; i < names.size(); ++i)
				if (str_val == names[i])
					name_has_been_seen = 1;
					
			if (name_has_been_seen == 0) {
				if (int_val == -1337) 
					cout << int_val << " cannot be recorded, it has special meaning to program." << endl;
				else {
					names.push_back(str_val);
					scores.push_back(int_val);
				}
			}
			else
				cout << "A name cannot be entered twice!" << endl;
		}
	}

	if (names.size() > 0) {
		cout << "To browse names enter its paired score, or enter -1337 to terminate program." << endl;
		int score;
		cin >> score;
		while (score != -1337) {
			int found_score = 0;
			vector<string> output;
			for (int i = 0; i < names.size(); ++i) {
				if (score == scores[i]) {
					output.push_back(names[i]);
					found_score = 1;
				}
			}

			if (found_score == 0)
				cout << "score not found." << endl;
			else {
				cout << "The names for score " << score << " are:" << endl;
				for (int i = 0; i < output.size(); ++i)
					cout << output[i] << endl;
			}
			cin >> score;
		}
	}
	else 
		cout << "You didn't enter any name-and-value pairs!" << endl;
		
	return 0;
}

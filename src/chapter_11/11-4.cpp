/*
	chapter 11 exercise 4
	page 404
*/
#include "std_lib_facilities.h"

void classify(const string& str)
{
	for (int i = 0; i < str.size(); ++i) {
		if (isalpha(str[i])) {
			cout << str[i] << " is an alpha";
			if (isupper(str[i]))
				cout << ", is an uppercase letter";
			else
				cout << ", is a lowercase letter";
			cout << ", and is a printable character.\n";
		}
		else if (isdigit(str[i])) {
			cout << str[i] << " is a digit";
			if (isxdigit(str[i])) 
				cout << ", is a hex digit";
			cout << ", and is a printable character.\n";
		}
		else {
			if (ispunct(str[i])) {
				cout << str[i] << " is a punctuation";
				cout << ", and is a printable character.\n";
			}
			else if (iscntrl(str[i]))
				cout << str[i] << " is a control character.\n";
		}
	}
}

int main()
{
	cout << "Enter some strings and I will give you the classification of each character (\"done\" to get results): ";
	string str;
	vector<string> strings;
	while (cin >> str && str != "done")
		strings.push_back(str);

	for (int i = 0; i < strings.size(); ++i)
		classify(strings[i]);

	return 0;
}

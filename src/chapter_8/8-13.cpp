/*
	chapter 8 exercise 13
	page 297
*/
#include "std_lib_facilities.h"

void print_until_ss(const vector<string> v, const string quit)
{
	int sec_occur = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == quit)
			++sec_occur;
		if (sec_occur == 2) return;
		cout << v[i] << '\n';
	}
	cout << "Second occurance not found.\n";
}

int main()
{
	cout << "Enter words (\"quit\" to stop loop): ";
	vector<string> words;
	string input;
	while (cin >> input && input != "quit") 
		words.push_back(input);
	
	cout << "Print until: ";
	cin >> input;
	print_until_ss(words,input);
	return 0;
}

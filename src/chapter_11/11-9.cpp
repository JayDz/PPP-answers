/*
	chapter 11 exercise 9
	page 404
*/
#include "std_lib_facilities.h"

vector<string> split(const string& s)
{
	vector<string> words;
	stringstream ss(s);
	string word;
	while (ss >> word)
		words.push_back(word);

	return words;
}

int main()
{
	//test code here
	return 0;
}

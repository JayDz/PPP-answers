/*
	chapter 11 exercise 10
	page 404
*/
#include "std_lib_facilities.h"

vector<string> split(const string& s, const string& w)
{
	//find the indexes of the characters defined by w.
	vector<int> indexes;
	for (int i = 0; i < s.size(); ++i)
		for (int j = 0; j < w.size(); ++j) 
			if (s[i] == w[j])
				indexes.push_back(i);
	
	string copy = s; //we'll replace characters defined in w with whitespace.
	for (int i = 0; i < indexes.size(); ++i)
		copy[indexes[i]] = ' ';

	vector<string> words;
	istringstream is(copy);
	string word;
	while (is >> word)
		words.push_back(word);
	return words;
}

int main()
{
	//test code here
	return 0;
}

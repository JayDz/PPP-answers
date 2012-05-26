/*
	Jeffrey Diaz - jeffreydiaz27@gmail.com
	Chapter 6 exercise 6
	Page 217
*/
#include "std_lib_facilities.h"

bool is_noun(string val)
{
	vector<string> nouns;
	nouns.push_back("birds");
	nouns.push_back("Birds");
	nouns.push_back("fish");
	nouns.push_back("Fish");
	nouns.push_back("C++");
	nouns.push_back("c++");

	for (int i = 0; i < nouns.size(); ++i)
		if (val == nouns[i])
			return true;
	return false;
}

bool is_verb(string val)
{
	vector<string> verbs;
	verbs.push_back("rules");
	verbs.push_back("fly");
	verbs.push_back("swim");

	for (int i = 0; i < verbs.size(); ++i)
		if (val == verbs[i])
			return true;
	return false;
}

bool is_conjunction(string val)
{
	vector<string> cons;
	cons.push_back("and");
	cons.push_back("or");
	cons.push_back("but");

	for (int i = 0; i < cons.size(); ++i)
		if (val == cons[i])
			return true;
	return false;
}

bool is_sentence()
{
	string input;

	cin >> input;
	if (!is_noun(input)) return false;
	
	cin >> input;
	if (!is_verb(input)) return false;

	cin >> input;
	if (input == ".") return true;
	if (!is_conjunction(input)) return false;
	else
		return is_sentence();
}

int main()
{
	cout << "Enter a sentence and to specify the end use a period sorrounded by whitespace ( . ): ";
	bool is_valid = is_sentence();
	if (is_valid)
		cout << "OK\n";
	else
		cout << "Not OK\n";
	return 0;
}

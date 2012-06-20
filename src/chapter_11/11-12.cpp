/*
	chapter 11 exercise 12
	page 405
*/
#include "std_lib_facilities.h"

int main()
{
	try {
		cout << "Enter filename: ";
		string name;
		cin >> name;

		ifstream is(name.c_str());
		if (!is) error("Error opening ",name);

		vector<string> words;
		string word;
		while (is >> word)
			words.push_back(word);
		is.close();

		ofstream os(name.c_str(),ios_base::trunc);
		if (!os) error("Error opening ",name);

		for (int i = words.size()-1; i >= 0; --i)
			os << words[i] << " ";
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}

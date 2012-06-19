/*
	chapter 11 exercise 5
	page 404
*/
#include "std_lib_facilities.h"

string rm_punct(const string& str)
{
	string new_str;
	for (int i = 0; i < str.size(); ++i)
		if (!ispunct(str[i]))
			new_str += str[i];
	return new_str;
}

int main()
{
	try {
		cout << "Enter filename: ";
		string filename;
		cin >> filename;
		
		if (cin.eof()) { // check for early exit (ctrl-d).
			cout << "Goodbye.\n";
			return -1;
		}

		ifstream is(filename.c_str());
		if (!is) error("Error opening for reading.");

		vector<string> lines;
		string line;
		while (getline(is,line)) {
			line = rm_punct(line);
			lines.push_back(line);
		}
		is.close(); // cannot have two streams attached to a single file.

		ofstream os(filename.c_str(),ios_base::trunc|ios_base::out); //erase (trunc) old content.
		if (!os) error("Error opening for writing.");

		for (int i = 0; i < lines.size(); ++i)
			os << lines[i] << endl;
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}

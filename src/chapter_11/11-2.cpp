/*
	chapter 11 exercise 2
	page 404
*/
#include "std_lib_facilities.h"

bool isvowel(char ch)
{
	if (!isalpha(ch)) return false;

	static const string vowels = "AaEeIiOoUu";
	for (int i = 0; i < vowels.size(); ++i)
		if (ch == vowels[i])
			return true;
	return false;
}

string disemvowel(string& line)
{
	string volweless;
	bool saw_space = false; // helps avoid back-to-back spaces such as, "nc pn  tm!"
	for (int i = 0; i < line.size(); ++i) {
		if (!isvowel(line[i])) {
			if (saw_space)
				if (line[i] != ' ')
					saw_space = false;
			if (!saw_space) {
				volweless += line[i];
				if (volweless[volweless.size()-1] == ' ')
					saw_space = true;
			}
		}
	}
	return volweless;
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
			line = disemvowel(line);
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

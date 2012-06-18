/*
	chapter 11 exercise 1
	page 404
*/
#include "std_lib_facilities.h"

int main()
{
	try {
		cout << "Enter name of text file to read: ";
		string in_file;
		cin >> in_file;

		ifstream is(in_file.c_str());
		if (!is)
			error("Error opening: ",in_file);

		cout << "Enter name for the new file: ";
		string new_file;
		cin >> new_file;

		ofstream os(new_file.c_str());
		if (!os)
			error("Error opening: ",new_file);

		char ch;
		while (is.get(ch)) { //use get istead of >> to keep whitespace.
			if (isalpha(ch) && isupper(ch))
				ch = tolower(ch);
			os << ch;
		}
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}

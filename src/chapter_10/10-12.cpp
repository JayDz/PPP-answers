/*
	chapter 10 exercise 12
	page 373
	NOTE: The program runs well when compiled with Microsoft's compiler (9.0 & 10.0), 
	range_error when compiled with g++.
	big TODO here.
*/
#include "std_lib_facilities.h"

bool search_line(const string& line, const string& word)
{
	int k = 0;
	for (int i = 0; i < line.size(); ++i) {
		if (!isspace(line[i])) { //skip any white-space, for example, tabs.
			if (line[i] != word[k]) {
				k = 0;
				// lets go to the next word in line, avoids returning true
				// when word is a sub-string. For example, searching for
				// spy within spyro will return true without this loop.
				while (line[i] != ' ') { 
					if (i < line.size())
						i++;
					else
						break;
				}
			}
			else {
				k++;
				if (k == word.size() && !isalpha(line[i+1]))
					return true;
			}
		}
	}
	return false;
}

int main()
{
	try {
		cout << "Enter file name: ";
		string filename;
		cin >> filename;
		ifstream is(filename.c_str());
		if (!is) error("Error opening file.");

		cout << "Enter search term: ";
		string search_term;
		cin >> search_term;

		string line;
		int line_num = 0;
		while (getline(is,line)) {
			line_num++;
			if (search_line(line,search_term))
				cout << line_num << ". " << line << endl;
		}
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}

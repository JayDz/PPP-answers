/*
	chapter 11 exercise 6
	page 404
*/
#include "std_lib_facilities.h"

vector<string> contractions;
vector<string> full_form;

void init_vectors() 
{
	// short list of contractions in the English language.
	contractions.push_back("aren't");
	contractions.push_back("can't");
	contractions.push_back("couldn't");
	contractions.push_back("didn't");
	contractions.push_back("don't");
	contractions.push_back("he'll");
	contractions.push_back("let's");
	contractions.push_back("isn't");
	contractions.push_back("i've");
	contractions.push_back("i'm");
	contractions.push_back("i'll");
	contractions.push_back("they're");
	contractions.push_back("we've");
	contractions.push_back("you're");
	contractions.push_back("you've");
	contractions.push_back("won't");
	
	// their replacements.
	full_form.push_back("are not");
	full_form.push_back("cannot");
	full_form.push_back("could not");
	full_form.push_back("did not");
	full_form.push_back("do not");
	full_form.push_back("he will");
	full_form.push_back("let us");
	full_form.push_back("is not");
	full_form.push_back("i have");
	full_form.push_back("i am");
	full_form.push_back("i will");
	full_form.push_back("they are");
	full_form.push_back("we have");
	full_form.push_back("you are");
	full_form.push_back("you have");
	full_form.push_back("will not");
}

string replace_contractions(string& line)
{
	stringstream ss(line);
	vector<string> words;
	string s;
	while (ss >> s)
		words.push_back(s);

	string new_str;
	for (int i = 0; i < words.size(); ++i) {
		bool found_contraction = false;
		for (int j = 0; j < contractions.size(); ++j) {
			if (words[i] == contractions[j]) {
				new_str += full_form[j];
				new_str += ' ';
				found_contraction = true;
			}
		}
		if (!found_contraction) {
			new_str += words[i];
			new_str += ' ';
		}
	}
	return new_str;
}

void convert_to_lower(string& line)
{
	for (int i = 0; i < line.size(); ++i)
		if (isalpha(line[i]))
			if (isupper(line[i]))
				line[i] = tolower(line[i]);
}

string edit_line(string& str)
{
	convert_to_lower(str);
	string new_str = replace_contractions(str);
	string final_str;
	for (int i = 0; i < new_str.size(); ++i) {
		if (!ispunct(new_str[i]))
			final_str += new_str[i];
		else {
			if (new_str[i] == '-')
				if (i > 0 && i < new_str.size()-1) // [i-1] and [i+1] could be trouble.
					if (isalpha(new_str[i-1]) && isalpha(new_str[i+1])) //hyphen is between words.
						final_str += '-';
		}
	}
	return final_str;
}

int main()
{
	try {
		init_vectors();

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
			line = edit_line(line);
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

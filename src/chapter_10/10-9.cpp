/*
	chapter 10 exercise 9
	page 372
*/
#include "std_lib_facilities.h"

void copy_content(ifstream& source, vector<string>& v)
{
	while (source) {
		string str;
		source >> str;
		v.push_back(str);
	}
}

void stream_status(const istream& is)
{
	//we should've only exited on eof(), if not an error (bad,fail) occured.
	if (!is.eof()) error("Error reading input.");
}

void write_out(ofstream& os, const vector<string>& v)
{
	for (int i = 2; i < v.size(); ++i) 
		//set i to 2, because for some reason v contains two spaces
		//in v[0] and v[1] (on Linux) respectfully.
		os << v[i] << ' ';
}

int main()
{
	try {
		cout << "Enter names of files to merge: ";
		string f1;
		string f2;
		cin >> f1 >> f2;

		if (cin.eof()) //check for early exit (ctrl-D).
			error("Ok, goodbye.");
		
		ifstream file1(f1.c_str());
		ifstream file2(f2.c_str());
		if (!file1 || !file2) error("Error opening input files.");
		
		string merge_file = "10-9-merge_file.txt";
		ofstream output_file(merge_file.c_str());
		if (!output_file) error("Error opening output file.");

		vector<string> words;

		copy_content(file1,words);
		stream_status(file1);

		copy_content(file2,words);
		stream_status(file2);

		sort(words.begin(),words.end());

		write_out(output_file,words);
		cout << "Files " << f1 << " and " << f2 << " have been merged into " << merge_file << endl;
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}

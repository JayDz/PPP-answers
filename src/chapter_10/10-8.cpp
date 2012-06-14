/*
	chapter 10 exercise 8
	page 372
*/
#include "std_lib_facilities.h"

void copy_content(ifstream& source, ofstream& dest)
{
	while (source) {
		char byte; 
		//read a byte at a time, that way, we grab newlines and whitespace.
		source.get(byte);
		dest << byte;
	}
}

void stream_status(const istream& is)
{
	//we should've only exited on eof(), if not an error (bad,fail) occured.
	if (!is.eof()) error("Error reading input.");
}

int main()
{
	try {
		cout << "Enter the two file names to concatenate: ";
		string f1;
		cin >> f1;
		string f2;
		cin >> f2;
		
		if (cin.eof()) //check for an early exit (ctrl-D).
			error("Ok, goodbye.");

		ifstream file1(f1.c_str());
		ifstream file2(f2.c_str());
		if (!file1 || !file2) error("Error opening input files.");

		ofstream output_file("10-8-concat_file.txt");
		if (!output_file) error("Error opening output file.");

		copy_content(file1,output_file);
		stream_status(file1);
			
		copy_content(file2,output_file);
		stream_status(file2);

		cout << f1 << " and " << f2 << " have been concatenated.\n";
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}

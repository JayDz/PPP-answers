/*
	chapter 10 exercise 1
	page 372
*/
#include "std_lib_facilities.h"

void read_from_file(ifstream& is, double& sum)
{
	double n = 0;
	while (is >> n)
		sum += n;
}

void check_stream_state(const ifstream& is)
{
	if (!is.eof()) 
		error("Error reading input.");
}

int main()
{
	try {
		string filename = "10-1.txt";
		ifstream is(filename.c_str());
		if (!is) error("Error opening file.");
		
		double sum = 0;
		read_from_file(is,sum);
		check_stream_state(is);

		cout << "The sum is: " << sum << endl;
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}

/*
	chapter 11 exercise 14
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

		cout << "Enter a name for the ouput file: ";
		string out_name;
		cin >> out_name;
		ofstream os(out_name.c_str());
		if (!os) error("An error occured when creating ",out_name);

		os << scientific << setprecision(8);
		double number;
		int output_count = 0;
		while (is >> number) {
			os << number << setw(20);
			++output_count;
			if (output_count == 4) {
				output_count = 0;
				os << '\n';
			}
		}
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}

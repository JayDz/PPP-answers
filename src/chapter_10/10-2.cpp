/*
	chapter 10 exercise 2
	page 372
*/
#include "std_lib_facilities.h"

int main()
{
	try {
		string filename = "raw_temps.txt";
		ofstream os(filename.c_str());
		if (!os) error("Couldn't open file.");

		for (int i = 0; i < 50; ++i) {
			int rand_hour    = randint(0,13); 
			double rand_temp = randint(1000); //meaningless magic number.
			os << rand_hour << ' ' << rand_temp << '\n';
		}
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}

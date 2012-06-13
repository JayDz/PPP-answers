/*
	chapter 10 exercise 4 - store_temps.cpp
	page 372
*/
#include "std_lib_facilities.h"

int main()
{
	try {
		string filename = "raw_temps2.txt";
		ofstream os(filename.c_str());
		if (!os) error("Couldn't open file.");

		for (int i = 0; i < 50; ++i) {
			int rand_hour    = randint(0,13); 
			double rand_temp = randint(1000); //meaningless magic number.
			int temp_suffix  = randint(1,10); //generate a suffix, even == Fahrenheit, odd == Celsius

			char suffix;
			if (temp_suffix % 2 == 0) 
				suffix = 'f';
			else
				suffix = 'c';

			os << rand_hour << ' ' << rand_temp << suffix << '\n';
		}
	}
	catch(runtime_error e) {
		cerr << e.what() << endl;
	}
	return 0;
}

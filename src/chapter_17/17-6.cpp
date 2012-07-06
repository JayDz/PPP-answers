/*
	chapter 17 exercise 6
	page 609
*/
#include "std_lib_facilities.h"

int main()
{
	int size;
	try {
		size = 655360000; //lets start with a big value.
		char* heap_mem;
		while (true) {
			heap_mem = new char[size]; //throws bad_alloc exception when limit is reached.
			cout << size << " bytes allocated successfully!\n";
			size++;
		}
	}
	catch(...) {
		cerr << "Blew up @ " << size << " bytes.\n";
	}
	return 0;
}

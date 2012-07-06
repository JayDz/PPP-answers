/*
	chapter 17 exercise 7
	page 609
*/
#include "std_lib_facilities.h"

char* alloc_more(char* s, int size, int increment)
{
	char* new_s = new char[size+increment];
	for (int i = 0; i < size; ++i)
		new_s[i] = s[i];

	delete[] s;	
	return new_s;
}

int main()
{
	try {
		const int increment = 100; //re-alloc amount when/if we run out of initial space.
		int size = 100; //lets allocate 100 bytes ahead of time.
		char* ch = new char[size];

		cout << "Enter characters and \'!\' to quit:\n";
		int i = 0; //keep count of characters read.
		char c;
		while (cin.get(c) && c != '!') {
			ch[i] = c;
			i++;
			if (i == size) {
				ch = alloc_more(ch,size,increment);
				size += increment;
			}
		}

		for (int j = 0; j < i; ++j)
			//print the hex value of each character, that way we see the whitespace input.
			cout << hex << showbase << static_cast<int>(ch[j]) << " ";
		cout << endl;

		delete[] ch;
	}
	catch(...) {
		cerr << "Memory exhaustion error\n";
	}
	return 0;
}

/*
	exercise 6 chapter 25
	page 946
*/
#include <iostream>
#include <limits>

int main()
{
	for (unsigned char i = 0; i < 256; ++i) {
		std::cout << (int)i << ' ';
		int scale = i; //helps us crash sooner!
		char* heap_array = new char[std::numeric_limits<unsigned char>::max()*scale];
	}

	return 0;
}

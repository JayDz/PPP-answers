/*
	exercise 6 chapter 25
	page 946
*/
#include <iostream>
#include <limits>

int main()
{
	//WARNING: this program greatly affected my computer's performance.
	for (unsigned char i = 0; i < 256; ++i) {
		std::cout << (int)i << ' ';
		int scale = i;
		char* heap_array = new char[std::numeric_limits<unsigned char>::max()*scale];
		*heap_array == i;
		++heap_array;
	}

	return 0;
}

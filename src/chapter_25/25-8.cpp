/*
	chapter  25 exercise 8
	page 946
*/
#include <iostream>

int main()
{
	const char kb_char_begin = 0x21; //The characters on the keyboard begin at ascii value 0x21
	const char kb_char_end   = 0x7F;

	for (char i = kb_char_begin; i < kb_char_end; ++i)
		std::cout << "The numerical value of " << i << " is " << static_cast<int>(i) << '\n';

	return 0;
}

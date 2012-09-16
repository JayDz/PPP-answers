/*
	chapter 25 exercise 7
	page 946
*/
#include <iostream>

int main()
{
	std::cout << std::showbase << std::hex;
	for (int i = 0; i <= 400; ++i)
		std::cout << i << ", ";

	std::cout << "\n\n\n";

	for (int i = -200; i <= 200; ++i)
		std::cout << i << ", ";
	std::cout << std::endl;

	return 0;
}
